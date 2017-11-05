#ifndef backTester_h
#define backTester_h

#include "Matrix.h"

Vector backTesting(Matrix &returnMatrix, double targetReturn, int ISwindowSize, int OOSwindowSize);

#endif