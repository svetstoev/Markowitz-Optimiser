#include <iostream>
#include <iomanip>
#include <fstream>
#include "backTester.h"
#include "returnData.h"
#include "portfolioSolver.h"
#include "Matrix.h"
#include "csv.h"


using namespace std;

int main()
{
	Data returns; // Class data, which reads and returns my Return Matrix
	Vector meanCov(2); // Stores the values for the mean and variance of each portfolio
	int ISwindowSize,OOSwindowSize;
	returns.getInput("asset_returns.csv"); // Makes it very easy/ uder friendly to switch/load different CSV files
	Matrix returnMatrix=returns.readData();
	
	cout << "Please enter the In-Sample window size here: "; cin >> ISwindowSize;
	cout << "Please enter the Out-Of-Sample window size here: "; cin >> OOSwindowSize;
	
	// Execute the "backTesting" function for each of the 10 portfolios and export to Excel
	//for(double i=0.005;i<=0.101;i=i+0.005) {backTesting(returnMatrix,i);meanCov=backTesting(returnMatrix,i);}
	
	// Execute the "backTesting" function for each of the 10 portfolios and print their individual Realized Return and Realized Variance
	for(double i=0.00;i<=0.101;i=i+0.005) 
		cout << "Target Return(IS)= " << setprecision(3) << i << ",   " << "Mean(OOS) = " << setprecision(5) << backTesting(returnMatrix,i,ISwindowSize,OOSwindowSize)[0] << ",   " << "Variance(OOS)= " << setprecision(5) << backTesting(returnMatrix,i,ISwindowSize,OOSwindowSize)[1] << endl;

	ofstream output;
	    output.open("trial.csv",ios::app);
		for(double i=0.005;i<=0.101;i=i+0.005)
			output << i << "   " << backTesting(returnMatrix,i,ISwindowSize,OOSwindowSize)[0] << "   " << backTesting(returnMatrix,i,ISwindowSize,OOSwindowSize)[1] << endl;
		output.close();

	
	
	
	cout << endl << "It's done ! ";
	
	int endofprogram;cin>>endofprogram;
	return 0;
}




ofstream output;
	    output.open("trial.csv",ios::app);
		for(double i=0.005;i<=0.101;i=i+0.005) /* PUT THE THING YOU WANT TO EXPORT HERE*/
		output.close();
