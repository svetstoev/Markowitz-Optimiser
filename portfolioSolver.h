#ifndef portfolioSolver_h
#define portfolioSolver_h

#include "Matrix.h"

class Portfolio{
	
	private:
	int NAssets;

	
	public:
	//Create a virtual function which would be passing the number of periods 
	//depending on whether we are In or Out of Sample
	virtual double NPeriods()=0;
	void getNAssets(int _NAssets){NAssets=_NAssets;}
	Matrix getQ(Matrix &returnMatrix, int startPoint);
	Vector getX0(Matrix &returnMatrix);
	Vector getB(double targetReturn);
	Vector meanCalc(Matrix &returnMatrix, int startPoint);
	Matrix covCalc(Matrix &returnMatrix, int startPoint);
	Vector cgmSolver(Matrix &Q, Vector &X0, Vector &b);
	
};



class inSample: public Portfolio
{
	private:
	int windowSize; //length of the period
	
	public:
	void SetWS(int windowSize_){windowSize=windowSize_;}
	double NPeriods(){return windowSize;}
	
	
};


class outOfSample: public Portfolio
{
	private:
	int windowSize; //length of the period
	
	public:
	void SetWS(int windowSize_){windowSize=windowSize_;}
	double NPeriods(){return windowSize;}
};
	
	
#endif