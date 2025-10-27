#ifndef MATRIX_H
#define MATRIX_H

#include "ComplexNamespace.h"
using complexNamespace::complexNumber;
#include "QuantumComputer.h"
#include <complex>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Matrix{
private:
    int numRows;
    int numCols;
    complexNumber** values;
public:
    void print();
    Matrix();
    Matrix(int numRows,int numCols);
    Matrix(int numRows,int numCols,complexNumber** values);
    ~Matrix();
    void setValue(int row,int col,complexNumber value);
    complexNumber getValue(int row, int col);
    complexNumber** getValues();
    void multiply(const Matrix& a,const Matrix& b);
    void tensor(const Matrix& a,const Matrix& b);


};

#endif