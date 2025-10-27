#include "Instructions.h"
#include "IO.h"
#include "Memory.h"
#include <string>
#include <iostream>
#include <cmath>

namespace Instructions{
    bool halt=false;
}
int Instructions::binaryToInt(std::string binaryString) {
    int num = 0;
    int powerOfTwo = 1; 

    
    for (int i = binaryString.length() - 1; i >= 0; --i) {
        if (binaryString[i] == '1') {
            num += powerOfTwo;
        }
        powerOfTwo *= 2; 
    }
    return num;
}
int Instructions::determineNumberOfOperands(int opcode)
{
    switch(opcode)
    {
        case 0:
            return 0;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 3;
            break;
        case 5:
            return 3;
            break;
        case 6:
            return 3;
            break;
        case 7:
            return 3;
            break;
        case 8:
            return 3;
            break;
        case 9:
            return 1;
            break;
        case 10:
            return 1;
            break;
        case 11:
            return 1;
            break;
        case 12:
            return 0;
            break;
        case 13:
            return 0;
            break;
        case 14:
            return 2;
            break;
        case 15:
            return 2;
            break;
        default:
            return 0;
    }
}
Instructions::Instruction* Instructions::createInstruction(std::string strInstruction)
{
    Instruction *ins=new Instruction;
    std::string code;
    code=strInstruction.substr(0,4);
    ins->opcode=binaryToInt(code);

    int numOfOp=determineNumberOfOperands(ins->opcode);
    ins->operands=new int[numOfOp];

    for (int i = 0; i < numOfOp; i++)
    {
        std::string currentStr=strInstruction.substr(4+(i*4),4);
        ins->operands[i]=binaryToInt(currentStr);
    }
    return ins;

}

void Instructions::destroyInstruction(Instruction*& instruction)
{
    if(instruction==NULL)
    {
        return;
    }
    if(instruction->operands!=NULL)
    {
        delete[]instruction->operands;
        instruction->operands=NULL;
    }
    delete instruction;
    instruction=NULL;
}

void Instructions::exitOp()
{
    Instructions::halt=true;
}
void Instructions::loadOp(int memoryLocation, int RAMLocation)
{
    int val=MemoryBuffer::read(storage,memoryLocation);
    MemoryBuffer::store(ram,RAMLocation,val);

}
void Instructions::saveOp(int RAMLocation, int memoryLocation)
{
    int value=MemoryBuffer::read(ram,RAMLocation);
    MemoryBuffer::store(storage,memoryLocation,value);
}
void Instructions::addOp(int resultLocation, int inputALocation, int inputBLocation)
{
    int a=MemoryBuffer::read(ram,inputALocation);
    int b=MemoryBuffer::read(ram,inputBLocation);

    int result=a+b;
    MemoryBuffer::store(ram,resultLocation,result);
}
void Instructions::minusOp(int resultLocation, int inputALocation, int inputBLocation)
{
    int a=MemoryBuffer::read(ram,inputALocation);
    int b=MemoryBuffer::read(ram,inputBLocation);

    int result=a-b;
    MemoryBuffer::store(ram,resultLocation,result);
}
void Instructions::greaterOp(int resultLocation, int inputALocation, int inputBLocation)
{
    int a = MemoryBuffer::read(ram, inputALocation);
    int b = MemoryBuffer::read(ram, inputBLocation);
    int result;
    if(a>b)
    {
        result=1;
    }
    else{
        result=0;
    }

    MemoryBuffer::store(ram,resultLocation,result);
}
void Instructions::lessOp(int resultLocation, int inputALocation, int inputBLocation)
{
    int a = MemoryBuffer::read(ram, inputALocation);
    int b = MemoryBuffer::read(ram, inputBLocation);
    int result;
    if(a<b)
    {
        result=1;
    }
    else{
        result=0;
    }

    MemoryBuffer::store(ram,resultLocation,result);
}
void Instructions::equalOp(int resultLocation, int inputALocation, int inputBLocation)
{
    int a = MemoryBuffer::read(ram, inputALocation);
    int b = MemoryBuffer::read(ram, inputBLocation);
    int result;
    if(a==b)
    {
        result=1;
    }
    else{
        result=0;
    }

    MemoryBuffer::store(ram,resultLocation,result);
}
void Instructions::ifOp(int booleanLocation, int trueInstructionNumber, int falseInstructionNumber, int& currentInstructionNumber)
{
    if(MemoryBuffer::read(ram,booleanLocation)==0)
    {
        currentInstructionNumber=falseInstructionNumber;
    }
    else{
        currentInstructionNumber=trueInstructionNumber;
    }
}
void Instructions::inputOp(int RAMLocation){
    int inputValue = obtainInput();

    MemoryBuffer::store(ram, RAMLocation, inputValue);
}
void Instructions::outputOp(int RAMLocation)
{
    int valueToOutput = MemoryBuffer::read(ram, RAMLocation);
     printOut(valueToOutput);
}
void Instructions::gotoOp(int targetInstructionNumber, int& currentInstructionNumber)
{
    currentInstructionNumber=targetInstructionNumber;
}
void Instructions::persistOp()
{
    writeToFile("memory.txt",storage->buffer,storage->bufferSize);
}
void Instructions::reloadOp(){
    readFromFile("memory.txt",storage->buffer,storage->bufferSize);
}
void Instructions::constOp(int constValue, int RAMLocation)
{
    MemoryBuffer::store(ram,RAMLocation,constValue);
}
void Instructions::moveOp(int sourceLocation, int destinationLocation) {
    int val = MemoryBuffer::read(ram, sourceLocation);
    MemoryBuffer::store(ram, destinationLocation, val);
}
void Instructions::debugPrintout(const Instruction* instr) {
    if (instr == NULL) {
        std::cout << "Instruction: NULL" << std::endl;
        return;
    }

    std::cout << "Instruction: " << std::endl;
    std::cout << "  Opcode: " << instr->opcode << std::endl;

    int numOperands = determineNumberOfOperands(instr->opcode);
    if (numOperands > 0) {
        std::cout << "  Operands: ";
        for (int i = 0; i < numOperands; ++i) {
            std::cout << instr->operands[i] << " ";
        }
        std::cout << std::endl;
    }
}
void Instructions::executeInstruction(Instruction *instr, int& currentInstructionNumber) {
    if (instr == NULL) {
        printError(4);
        halt = true;
        return;
    }

    switch (instr->opcode) {
        case 0:
            exitOp();
            return;
        case 1:
            if (determineNumberOfOperands(instr->opcode) == 2 && instr->operands != NULL) {
                loadOp(instr->operands[0], instr->operands[1]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 2:
            if (determineNumberOfOperands(instr->opcode) == 2 && instr->operands != NULL) {
                saveOp(instr->operands[0], instr->operands[1]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 3:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                addOp(instr->operands[0], instr->operands[1], instr->operands[2]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 4:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                minusOp(instr->operands[0], instr->operands[1], instr->operands[2]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 5:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                greaterOp(instr->operands[0], instr->operands[1], instr->operands[2]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 6:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                lessOp(instr->operands[0], instr->operands[1], instr->operands[2]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 7:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                equalOp(instr->operands[0], instr->operands[1], instr->operands[2]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 8:
            if (determineNumberOfOperands(instr->opcode) == 3 && instr->operands != NULL) {
                ifOp(instr->operands[0], instr->operands[1], instr->operands[2], currentInstructionNumber);
            } else {
                printError(4);
                halt = true;
            }
            return;
        case 9:
            if (determineNumberOfOperands(instr->opcode) == 1 && instr->operands != NULL) {
                inputOp(instr->operands[0]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 10:
            if (determineNumberOfOperands(instr->opcode) == 1 && instr->operands != NULL) {
                outputOp(instr->operands[0]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 11:
            if (determineNumberOfOperands(instr->opcode) == 1 && instr->operands != NULL) {
                gotoOp(instr->operands[0], currentInstructionNumber);
            } else {
                printError(4);
                halt = true;
            }
            return;
        case 12:
            if (determineNumberOfOperands(instr->opcode) == 0) {
                persistOp();
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 13:
            if (determineNumberOfOperands(instr->opcode) == 0) {
                reloadOp();
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 14:
            if (determineNumberOfOperands(instr->opcode) == 2 && instr->operands != NULL) {
                constOp(instr->operands[0], instr->operands[1]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        case 15:
            if (determineNumberOfOperands(instr->opcode) == 2 && instr->operands != NULL) {
                moveOp(instr->operands[0], instr->operands[1]);
                currentInstructionNumber++;
            } else {
                printError(4);
                halt = true;
            }
            break;
        default:
            printError(4);
            halt = true;
            break;
    }
}   