#include <iostream>
#include "Matrix.h"
#include <cmath>
using namespace std;

Vector operator*(const Matrix& C,const Vector& V)
{
   int d = C.size();
   Vector W(d);
   for (int j=0; j<d; j++)
   {
      W[j]=0.0;
      for (int l=0; l<d; l++) W[j]=W[j]+C[j][l]*V[l];
   }
   return W;
}


Vector operator*(const Vector& V,const Matrix& C)
{
	int rows = V.size();
	int cols= C[0].size();
	Vector W;
	W.resize(cols);
	for (int i=0;i<cols;i++)
	{
		W[i]=0.0;
		for(int j=0;j<rows;j++) W[i]=W[i]+V[j]*C[i][j];
	}
	
	return W;
}


Vector operator+(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] + W[j];
   return U;
}

Vector operator+(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a + V[j];
   return U;
}

Vector operator-(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] - W[j];
   return U;
}

Vector operator-(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a - V[j];
   return U;
}

Matrix operator*(const double& a,const Matrix& C)
{
   int rows = C.size();
   int cols = C[0].size();
   Matrix U;
   U.resize(rows);
   for(int i=0;i<rows;i++) U[i].resize(cols);
   
   for (int i=0; i<rows; i++)
	   for(int j=0;j<cols;j++) U[i][j] = a*C[i][j];
   return U;
}
	
Vector operator*(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a*V[j];
   return U;
}

double operator*(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   double sum=0.0;
   for (int j=0; j<d; j++) sum = sum + V[j] * W[j];
   return sum;
}

Vector exp(const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = exp(V[j]);
   return U;
}

double transposeMult(const Vector& V)
{
   int d = V.size();
   double sum=0;
   for (int j=0; j<d; j++) sum=sum + V[j] * V[j];
   return sum;
}
