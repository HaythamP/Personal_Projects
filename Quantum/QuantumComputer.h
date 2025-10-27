#ifndef QUANTUMCOMPUTER_H
#define QUANTUMCOMPUTER_H

#include "ComplexNamespace.h"
#include "Matrix.h"

using namespace complexNamespace;
using namespace std;

class Matrix;
class QuantumComputer {
private:
    int numQubits;
    int numGates;
    Matrix** gates;

public:
    static void printStateVectorEvolution(int stateVectorSize, int numberOfGates, string* measurementLabels, complexNumber** probabilities);
    static Matrix* xGate();
    static Matrix* yGate();
    static Matrix* zGate();
    static Matrix* hGate();
    static Matrix* sGate();
    static Matrix* rxGate(complexNumber value);
    static Matrix* ryGate(complexNumber value);
    static Matrix* rzGate(complexNumber value);

    QuantumComputer(int numQubits);
    ~QuantumComputer();
    void addGate(int qubit, char gate);
    void addRotationGate(int qubit, complexNumber value, char gate);
    void evolveStateVector();
};

#endif
