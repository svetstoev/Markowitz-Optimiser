#ifndef Matrix_h
#define Matrix_h

#include <vector>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;
typedef vector<Matrix> threeD;

Vector operator*(const Matrix& C,const Vector& V);
Vector operator*(const Vector& V,const Matrix& C);
Vector operator*(const double& a,const Vector& V);
Matrix operator*(const double& a,const Matrix& C);
Vector operator+(const double& a,const Vector& V);
Vector operator+(const Vector& V,const Vector& W);
Vector operator-(const double& a,const Vector& V);
Vector operator-(const Vector& V,const Vector& W);
double operator*(const Vector& V,const Vector& W);
double transposeMult(const Vector& V);
Vector exp(const Vector& V);

#endif
