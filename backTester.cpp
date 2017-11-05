//Uncomment the relevant sections if you want to exoport all the 40 iterations of each target return to Excel
#include <iostream>
#include "backTester.h"
#include "returnData.h"
#include "portfolioSolver.h"
#include "Matrix.h"
#include "csv.h"
#include <fstream>
#include <cmath>

using namespace std;


Vector backTesting(Matrix &returnMatrix, double targetReturn,int ISwindowSize, int OOSwindowSize)
{
		
	inSample IS;
	outOfSample OOS;
	Matrix Q;
	Vector b,X,X0,W(returnMatrix.size()),meanCov(2); 
	// Notice that the two class objects (IS and OOS) could be defined outside the function and just passed to it by reference as well which would further increase the efficiency of the algorithm
	// Vector mean,covariance;
	double summation=0,averageMean=0,averageCov=0,mean,covariance;
	int count=0,startPoint=0,totalNPeriods=returnMatrix[0].size();
	
	IS.getNAssets(returnMatrix.size()); OOS.getNAssets(returnMatrix.size());
    IS.SetWS(ISwindowSize);OOS.SetWS(OOSwindowSize);
	
	X0=IS.getX0(returnMatrix);
	//mean.resize((totalNPeriods-ISwindowSize)/OOSwindowSize);
	//covariance.resize((totalNPeriods-ISwindowSize)/OOSwindowSize);
	
	
	
	// This is the actual backtesting algorithm
	////////////////////////////////////////////////////
	while(startPoint+ISwindowSize<=totalNPeriods)
	{
		//Find the weights In-Sample
		Q=IS.getQ(returnMatrix,startPoint);
		b=IS.getB(targetReturn);
		X=IS.cgmSolver(Q,X0,b); 
		for(int i=0;i<returnMatrix.size();i++) W[i]=X[i];
		
		//the end of an IS rolling window and the beginning of the OOS window
		startPoint=startPoint+ISwindowSize; 
		
		//Find the realized portfolio mean and variance
		//mean[count]=OOS.meanCalc(returnMatrix,startPoint)*W; //mean*W
		//covariance[count]=W*OOS.covCalc(returnMatrix,startPoint)*W; //W*cov*W
		mean=OOS.meanCalc(returnMatrix,startPoint)*W; //mean*W
		covariance=W*OOS.covCalc(returnMatrix,startPoint)*W; //W*cov*W
		
		
		//Export to Excel
	    /*ofstream output;
	    output.open("MarkowitzPortfolios.csv",ios::app);
		output << i+1 << "   " << targetReturn << "   " << mean[i] << "   " << covariance[i] << endl;
		output.close();*/
		
		//Calculate the Realized Return and Covariance for each portfolio
		averageMean=averageMean+(mean/((totalNPeriods-ISwindowSize)/OOSwindowSize));
		averageCov=averageCov+(covariance/((totalNPeriods-ISwindowSize)/OOSwindowSize));
	
		
		//Roll the window
		startPoint=startPoint-(ISwindowSize-OOSwindowSize); //E.g. for the first iteration --> startPoint=100 - 88=12
		count++; //counts the number of iterations
	}
	////////////////////////////////////////////////////	
	meanCov[0]=averageMean;
	meanCov[1]=averageCov;
	return meanCov;

	
}
