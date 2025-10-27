#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.h"
#include <complex>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
void Matrix::print() {
    std::cout << std::fixed << std::setprecision(3);
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            std::cout << std::left << std::setw(10) << values[r][c];
        }
        std::cout << std::endl;
    }
}
Matrix::Matrix(){
    numRows=2;
    numCols=2;
    values=new complexNumber*[numRows];
    for (int i = 0; i < numRows; i++)
    {
        values[i]=new complexNumber[numCols];
    }
    values[0][0]=1;
    values[0][1]=0;
    values[1][0]=0;
    values[1][1]=1;
}
Matrix::Matrix(int numRows,int numCols){
this->numRows=numRows;
this->numCols=numCols;
this->values=new complexNumber*[numRows];
for (int i = 0; i < numRows; i++)
{
    this->values[i]=new complexNumber[numCols];
}

for (int i = 0; i < numRows; i++)
{
   for(int j=0;j<numCols;j++)
   {
    if(i==j){
    this->values[i][j]=1;
    }
    else{
    this->values[i][j]=0;
    }
   }
}
}
Matrix::Matrix(int numRows,int numCols,complexNumber** values){
if(numRows<=0||numCols<=0||values==NULL){
    std::cout<<"Error invalid parameters"<<std::endl;
}
this->numRows=numRows;
this->numCols=numCols;
this->values=new complexNumber*[numRows];
for (int i = 0; i < numRows; i++)
{
    this->values[i]=new complexNumber[numCols];
    for (int j = 0; j<numCols; j++)
    {
        if(values!=NULL){
            this->values[i][j]=values[i][j];
        }else{
            this->values[i][j]=complexNumber(0,0);
        }
    }
    
}
}
Matrix::~Matrix(){
    if(values!=NULL){
        for (int i = 0; i < numRows; i++)
        {
            if(values[i]!=NULL){
                delete []values[i];
                values[i]=NULL;
            }
        }
        delete[] values;
        values=NULL;        
    }
}
void Matrix::setValue(int row,int col,complexNumber value){
if(row<0||row>numRows-1||col<0||col>numCols-1){
    return;
}
else{
    values[row][col]=value;
}
}
complexNumber Matrix::getValue(int row, int col){
if(row<0||row>numRows-1||col<0||col>numCols-1){
    return complexNumber(404.0,404.0);
}else{
    return values[row][col];
}
}
complexNumber** Matrix::getValues(){
    return values;
}

void Matrix::multiply(const Matrix& a,const Matrix& b){
    if(a.numCols!=b.numRows){
        return;
    }
    else if(this==&a||this==&b){
        return;
    }else{
        for (int i = 0; i < numRows; i++)
        {
            delete[] values[i];
        }
        delete[] values;

        numRows=a.numRows;
        numCols=b.numCols;
        values=new complexNumber*[numRows];
        for (int i = 0; i < numRows; i++)
        {   
            values[i]=new complexNumber[numCols];
        }

            for(int j=0;j<numRows;j++){
                for(int k=0;k<numCols;k++){
                    complexNumber total=0;
                    for(int l=0;l<a.numCols;l++){
                       total=total+a.values[j][l]*b.values[l][k];
                    }
                    values[j][k]=total;
            } 
    }

}
}
void Matrix::tensor(const Matrix& a,const Matrix& b){
    if(this==&a||this==&b){
        return;
    }
    else{
        for (int i = 0; i < numRows; i++)
        {
            delete[] values[i];
        }
        delete[] values;

        numRows=a.numRows*b.numRows;
        numCols=a.numCols*b.numCols;
        values=new complexNumber*[numRows];
        for (int i = 0; i <numRows; i++)
        {
            values[i]=new complexNumber[numCols];
        }

        for(int i=0;i<a.numRows;i++){
            for(int j=0;j<a.numCols;j++){
                for(int k=0;k<b.numRows;k++){
                    for(int l=0;l<b.numCols;l++){
                        values[i*b.numRows +k][j*b.numCols +l]=a.values[i][j]*b.values[k][l];
                    }
                }
            }
        }
    }
}
#endif