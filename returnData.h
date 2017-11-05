#ifndef returnData_h
#define returnData_h

#include "csv.h"
#include "Matrix.h"
#include <cstring>


class Data{
	private:
	string fileName;
	
	
	public:
	double string_to_double( const std::string& s );
	Matrix readData();
	void getInput(string _fileName){fileName=_fileName;}
};


#endif
	