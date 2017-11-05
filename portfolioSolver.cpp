#include "csv.h"
#include "Matrix.h"
#include "returnData.h"
#include "portfolioSolver.h"
#include <cmath>


Vector Portfolio::meanCalc(Matrix &returnMatrix, int startPoint)
{
	int NPer=NPeriods();
	Vector mean;
	mean.resize(NAssets); 
	
    for(int i=0;i<NAssets;i++){
    mean[i]=0;                       
    for(int j=startPoint;j<startPoint+NPer;j++)
    {
        double temp=returnMatrix[i][j];
        mean[i]=mean[i]+temp/NPer; 
    }

    }
	return mean;
}


Matrix Portfolio::covCalc(Matrix &returnMatrix, int startPoint)
{
	int NPer=NPeriods();
	Matrix covMatrix;
	covMatrix.resize(NAssets);
	for(int i=0;i<NAssets;i++) covMatrix[i].resize(NAssets);

	Vector mean=meanCalc(returnMatrix,startPoint);
	
	for(int i=0;i<NAssets;i++)
		for(int j=0;j<NAssets;j++){
			covMatrix[i][j]=0;
			for(int k=startPoint;k<startPoint+NPer;k++){
				double temp=(returnMatrix[i][k]-mean[i])*(returnMatrix[j][k]-mean[j]);
				covMatrix[i][j]=covMatrix[i][j]+temp/(NPer-1);
				}
		}
	return covMatrix;
}

Matrix Portfolio::getQ(Matrix &returnMatrix,int startPoint)
{
	Vector mean=meanCalc(returnMatrix,startPoint);
	Matrix covariance=covCalc(returnMatrix,startPoint);
	
	Matrix Q; //initialize Q
	Q.resize(NAssets+2);
	for(int i=0;i<NAssets+2;i++) Q[i].resize(NAssets+2);
	
	for(int i=0;i<NAssets+2;i++)
		for(int j=0;j<NAssets+2;j++){
			if(i<NAssets && j<NAssets) Q[i][j]=covariance[i][j];
			else if (i<NAssets && j==NAssets) Q[i][j]=-mean[i];
			else if (i<NAssets && j==NAssets+1) Q[i][j]=-1;
			else if (i==NAssets && j<NAssets) Q[i][j]=-mean[j];
			else if (i==NAssets+1 && j<NAssets) Q[i][j]=-1;
			else Q[i][j]=0;
		}
		
		return Q;
}

Vector Portfolio::getX0(Matrix &returnMatrix)
{
	Vector X0;
	X0.resize(returnMatrix[0].size()+2);
	for(int i=0;i<returnMatrix[0].size();i++) X0[i]=1/83;
	X0[83]=1;
	X0[84]=1;
	return X0;
}
	
Vector Portfolio::getB(double targetReturn)
{
	Vector b;
	b.resize(NAssets+2);
	for(int i=0;i<NAssets;i++) b[i]=0;
	b[NAssets]=-targetReturn;
	b[NAssets+1]=-1;
	return b;
}


Vector Portfolio::cgmSolver(Matrix &Q, Vector &X0, Vector &b)
{

	double alpha,beta;
	Vector SK,S0,PK,P0,XK;
	const double eps=pow(10,-6);
	
	S0=b-(Q*X0);
	P0=S0;

	while(transposeMult(S0)>eps) //function that multiplies a vector by its transpose -> check the definition in Matrix.cpp
	{
		alpha= transposeMult(S0)/(P0*Q*P0);
		XK= X0 + (alpha*P0);
		SK= S0 - (alpha*Q*P0);
		beta= transposeMult(SK)/transposeMult(S0);
		P0=SK + (beta*P0);
		
		S0=SK;
		X0=XK;
	}
	
	return X0;
}


