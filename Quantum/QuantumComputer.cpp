#include "QuantumComputer.h"
#include "ComplexNamespace.h"
#include "Matrix.h"
#include "QuantumComputer.h"
#include <complex>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace complexNamespace;

void QuantumComputer::printStateVectorEvolution(int stateVectorSize, int numberOfGates, string* measurementLabels, complexNumber** probabilities) {
    std::cout << std::fixed << std::setprecision(3);
    for (int i = 0; i < stateVectorSize; i++) {
        std::cout << "|" << measurementLabels[i] << ">";
        for (int j = 0; j < numberOfGates; j++) {
            std::cout << std::right << std::setw(10) << probabilities[i][j].real() * 100 << " %";
        }
        std::cout << std::endl;
    }
}

Matrix* QuantumComputer::xGate(){
    Matrix* temp=new Matrix(2,2);
    temp->setValue(0,0,complexNumber(0.0,0.0));
    temp->setValue(0,1,complexNumber(1.0,0.0));
    temp->setValue(1,0,complexNumber(1.0,0.0));
    temp->setValue(1,1,complexNumber(0.0,0.0));
    return temp;
}

Matrix* QuantumComputer::yGate(){
    Matrix* temp=new Matrix(2,2);
    temp->setValue(0,0,complexNumber(0.0,0.0));
    temp->setValue(0,1,complexNumber(0.0,-1.0));
    temp->setValue(1,0,complexNumber(0.0,1.0));
    temp->setValue(1,1,complexNumber(0.0,0.0));
    return temp;
}

Matrix* QuantumComputer::zGate(){
    Matrix* temp=new Matrix(2,2);
    temp->setValue(0,0,complexNumber(1.0,0.0));
    temp->setValue(0,1,complexNumber(0.0,0.0));
    temp->setValue(1,0,complexNumber(0.0,0.0));
    temp->setValue(1,1,complexNumber(-1.0,0.0));
    return temp;
}

Matrix* QuantumComputer::hGate(){
    Matrix* temp=new Matrix(2,2);
    double scalar=1.0/sqrt(2);
    temp->setValue(0,0,complexNumber(scalar,0.0));
    temp->setValue(0,1,complexNumber(scalar,0.0));
    temp->setValue(1,0,complexNumber(scalar,0.0));
    temp->setValue(1,1,complexNumber(-scalar,0.0));
    return temp;
}

Matrix* QuantumComputer::sGate(){
    Matrix* temp=new Matrix(2,2);
    temp->setValue(0,0,complexNumber(0.5,0.5));
    temp->setValue(0,1,complexNumber(0.5,0.5));
    temp->setValue(1,0,complexNumber(0.5,0.5));
    temp->setValue(1,1,complexNumber(0.5,0.5));
    return temp;
}

Matrix* QuantumComputer::rxGate(complexNumber value){
    Matrix* temp=new Matrix(2,2);
    double th=value.real();
    double theta=th/2.0;
    temp->setValue(0,0,complexNumber(cos(theta),0.0));
    temp->setValue(0,1,complexNumber(0.0,-sin(theta)));
    temp->setValue(1,0,complexNumber(0.0,-sin(theta)));
    temp->setValue(1,1,complexNumber(cos(theta),0.0));
    return temp;
}

Matrix* QuantumComputer::ryGate(complexNumber value){
    Matrix* temp=new Matrix(2,2);
    double th=value.real();
    double theta=th/2.0;
    temp->setValue(0,0,complexNumber(cos(theta),0.0));
    temp->setValue(0,1,complexNumber(-sin(theta),0.0));
    temp->setValue(1,0,complexNumber(sin(theta),0.0));
    temp->setValue(1,1,complexNumber(cos(theta),0.0));
    return temp;
}

Matrix* QuantumComputer::rzGate(complexNumber value){
    Matrix* temp = new Matrix(2,2);
    double th=value.real();
    double theta=th/2.0;
    temp->setValue(0,0,complexNumber(cos(theta),-sin(theta)));
    temp->setValue(0,1,complexNumber(0.0,0.0));
    temp->setValue(1,0,complexNumber(0.0,0.0));
    temp->setValue(1,1,complexNumber(cos(theta),sin(theta)));
    return temp;
}

QuantumComputer::QuantumComputer(int numQubits){
    if(numQubits>5){
        this->numQubits=5;
    }
    else{
        this->numQubits=numQubits;
    }
    this->numGates=0;
    this->gates=NULL;
}

QuantumComputer::~QuantumComputer(){
    for(int i=0;i<numGates;i++){
        if(gates[i]!=NULL){
        delete gates[i];
        }
    }
    delete[] gates;
}

void QuantumComputer::addGate(int qubit,char gate){
    if(qubit<0||qubit>=numQubits) return;

    Matrix* singleGate=NULL;
    switch(gate){
        case 'X': 
            singleGate=xGate();
            break;
        case 'Y': 
            singleGate=yGate();
            break;
        case 'Z': 
            singleGate=zGate();
            break;
        case 'H': 
            singleGate=hGate();
            break;
        case 'S': 
            singleGate=sGate();
            break;
        default: 
            return;
    }

    Matrix* ident=new Matrix(2,2);
    ident->setValue(0,0,complexNumber(1.0,0.0));
    ident->setValue(0,1,complexNumber(0.0,0.0));
    ident->setValue(1,0,complexNumber(0.0,0.0));
    ident->setValue(1,1,complexNumber(1.0,0.0));
    
    Matrix* full=NULL;
    if(qubit==0){
        full=new Matrix(2,2);
        full->setValue(0,0,singleGate->getValue(0,0));
        full->setValue(0,1,singleGate->getValue(0,1));
        full->setValue(1,0,singleGate->getValue(1,0));
        full->setValue(1,1,singleGate->getValue(1,1));

    }else{
        full=new Matrix(2,2);
        full->setValue(0,0,complexNumber(1.0,0.0));
        full->setValue(0,1,complexNumber(0.0,0.0));
        full->setValue(1,0,complexNumber(0.0,0.0));
        full->setValue(1,1,complexNumber(1.0,0.0));
    }

    for(int i=1;i<numQubits;i++){
        Matrix* newMat;
        if(i==qubit){
            newMat=singleGate;
        }else{
            newMat=ident;
        }

        Matrix res;
        res.tensor(*full,*newMat);
        int nSize=1;
    for(int j=0;j<=i;j++)
    {
        nSize *=2;
    }

    delete full;
    full= new Matrix(nSize,nSize);

    for(int row=0;row<nSize;row++)
    {
        for(int col=0;col<nSize;col++)
        {
            full->setValue(row,col,res.getValue(row,col));
        }
    }

    }
    Matrix** newGate = new Matrix*[numGates+1];

for(int i=0;i<numGates;i++)
{
    newGate[i]=gates[i];
}
newGate[numGates]=full;

if(gates!=NULL)
{
    delete[] gates;
}

gates = newGate;
numGates++;

delete singleGate;
delete ident;

}

void QuantumComputer::addRotationGate(int qubit,complexNumber value,char gate){
    if(qubit<0||qubit>=numQubits){ 
        return;
    }

    Matrix* singleGate=NULL;
    switch(gate){
        case 'X': 
            singleGate=rxGate(value);
            break;
        case 'Y': 
            singleGate=ryGate(value);
            break;
        case 'Z': 
            singleGate=rzGate(value);
            break;
        default: 
            return;
    }

    Matrix* ident=new Matrix(2,2);
    ident->setValue(0,0,complexNumber(1.0,0.0));
    ident->setValue(0,1,complexNumber(0.0,0.0));
    ident->setValue(1,0,complexNumber(0.0,0.0));
    ident->setValue(1,1,complexNumber(1.0,0.0));
    
    Matrix* full=NULL;
    if(qubit==0){
        full=new Matrix(2,2);
        full->setValue(0,0,singleGate->getValue(0,0));
        full->setValue(0,1,singleGate->getValue(0,1));
        full->setValue(1,0,singleGate->getValue(1,0));
        full->setValue(1,1,singleGate->getValue(1,1));

    }else{
        full=new Matrix(2,2);
        full->setValue(0,0,complexNumber(1.0,0.0));
        full->setValue(0,1,complexNumber(0.0,0.0));
        full->setValue(1,0,complexNumber(0.0,0.0));
        full->setValue(1,1,complexNumber(1.0,0.0));
    }
    for(int i=1;i<numQubits;i++){
        Matrix* newMat;
        if(i==qubit){
            newMat=singleGate;
        }else{
            newMat=ident;
        }

        Matrix res;
        res.tensor(*full,*newMat);
        int nSize=1;
    for(int j=0;j<=i;j++)
    {
        nSize *=2;
    }

    delete full;
    full= new Matrix(nSize,nSize);

    for(int row=0;row<nSize;row++)
    {
        for(int col=0;col<nSize;col++)
        {
            full->setValue(row,col,res.getValue(row,col));
        }
    }

    }
    Matrix** newGate = new Matrix*[numGates+1];

for(int i=0;i<numGates;i++)
{
    newGate[i]=gates[i];
}
newGate[numGates]=full;

if(gates!=NULL)
{
    delete[] gates;
}

gates = newGate;
numGates++;

delete singleGate;
delete ident;
    
}

void QuantumComputer::evolveStateVector(){
    int stateSize=1;
    for(int i=0;i<numQubits;i++){
        stateSize*=2;
    }

    Matrix* stateVector=new Matrix(stateSize,1);
    stateVector->setValue(0,0,complexNumber(1.0,0.0));
    for(int i=1;i<stateSize;i++)
    {
        stateVector->setValue(i,0,complexNumber(0.0,0.0));
    }

    string* measurementLabels=new string[stateSize];
    for(int i=0;i<stateSize;i++){
            stringstream ss;
            for(int bit = numQubits-1;bit>=0;bit--)
        {
            if((i>>bit)&1)
            {
                ss << "1";
            }
            else
            {
                ss <<"0";
            }
        }

        measurementLabels[i] = ss.str();
    }

    
    complexNumber** probabilities=new complexNumber*[stateSize];
    for(int i=0;i<stateSize;i++){
        probabilities[i]=new complexNumber[numGates];
        
    }

    for(int k=0;k<numGates;k++){
        Matrix stVector;
        stVector.multiply(*gates[k],*stateVector);
        delete stateVector;
        stateVector=new Matrix(stateSize,1);
        for(int i=0;i<stateSize;i++){
            stateVector->setValue(i,0,stVector.getValue(i,0));
        }
        for(int i=0;i<stateSize;i++){
            complexNumber am=stateVector->getValue(i,0);
            complexNumber prob=am*conj(am);
            probabilities[i][k]=prob;
        }
    }
    printStateVectorEvolution(stateSize,numGates,measurementLabels,probabilities);
    delete stateVector;
    delete[] measurementLabels;
    for(int i=0;i<stateSize;i++)
    {
        delete[] probabilities[i];
    }
    delete[] probabilities;

    
}