#include "csv.h"
#include "Matrix.h"
#include "returnData.h"
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>


double Data::string_to_double( const std::string& s )
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
} 

Matrix Data::readData()
{
	//cout << "----";
	Matrix data;
	data.resize(83);
	for(int i=0;i<83;i++) data[i].resize(700);
	
	char tmp[20];
	ifstream file (strcpy(tmp, fileName.c_str()));
	Csv csv(file);
	string line;
	if (file.is_open())
	{
		int i=0;
		while (csv.getline(line) != 0) {
         	for (int j = 0; j < csv.getnfield(); j++)
            {
               double temp=string_to_double(csv.getfield(j));
               //cout << "Asset " << j << ", Return "<<i<<"="<< temp<<"\n";
               data[j][i]=temp;
            }
            i++;
		}
		
		file.close();
	}
	else {cout <<fileName <<" missing\n";exit(0);}
	//cout << "**";
	return data;
  }
  

 