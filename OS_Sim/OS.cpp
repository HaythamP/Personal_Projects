#include "OS.h"
#include "Instructions.h"
#include "IO.h"
#include "Memory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace OperatingSystem {

    Instructions::Instruction** programInstructions = NULL;
    int numberOfInstructions = 0;
    int currentInstructionNumber = 0;

    bool isLineEmptyOrWhitespace(const std::string line) {
        if (line.empty()) {
            return true;
        }
        for (std::string::size_type i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
                return false;
            }
        }
        return true;
    }

    void bootComputer(int ramSize, int storageSize) {
        MemoryBuffer::createBuffer(ram, ramSize);
        MemoryBuffer::createBuffer(storage, storageSize);
    }

    void shutDownComputer() {
        MemoryBuffer::destroyBuffer(ram);
        MemoryBuffer::destroyBuffer(storage);

        if (programInstructions != NULL) {
            for (int i = 0; i < numberOfInstructions; ++i) {
                Instructions::destroyInstruction(programInstructions[i]);
            }
            delete[] programInstructions;
            programInstructions = NULL;
        }
        numberOfInstructions = 0;
        currentInstructionNumber = 0;
    }

    void loadHardDrive(std::string hardDriveDiskName) {
        readFromFile(hardDriveDiskName, storage->buffer, storage->bufferSize);
    }

    int determineNumberOfInstructions(std::string programFile) {
        std::ifstream infile(programFile.c_str());
        if (!infile) {
            return 0;
        }

        int count = 0;
        std::string line;
        while (std::getline(infile, line)) {
            if (!isLineEmptyOrWhitespace(line)) {
                count++;
            }
        }
        infile.close();
        return count;
    }

    void loadInstructions(std::string programFile) {
        std::ifstream infile;
        numberOfInstructions = determineNumberOfInstructions(programFile);
        if (numberOfInstructions == 0) {
            return;
        }

        if (programInstructions != NULL) {
            for (int i = 0; i < numberOfInstructions; ++i) {
                Instructions::destroyInstruction(programInstructions[i]);
            }
            delete[] programInstructions;
            programInstructions = NULL;
        }

        programInstructions = new Instructions::Instruction *[numberOfInstructions];

        infile.open(programFile.c_str());
        std::string line;
        int i = 0;
        while (std::getline(infile, line) && i < numberOfInstructions) {
            if (!isLineEmptyOrWhitespace(line)) {
                programInstructions[i] = Instructions::createInstruction(line);
                i++;
            }
        }
        infile.close();
        currentInstructionNumber = 0;
    }

    void executeProgram() {
        if (programInstructions == NULL || numberOfInstructions == 0) {
            return;
        }

        Instructions::halt = false;
        currentInstructionNumber = 0;
        while (!Instructions::halt && currentInstructionNumber < numberOfInstructions) {
            Instructions::executeInstruction(programInstructions[currentInstructionNumber], currentInstructionNumber);
        }
    }

    void printProgram() {
        if (programInstructions == NULL || numberOfInstructions == 0) {
            return;
        }

        for (int i = 0; i < numberOfInstructions; ++i) {
            std::cout << "[" << i << "] ";
            Instructions::debugPrintout(programInstructions[i]);
        }
    }

    void translateProgram(std::string highLevelFile, std::string lowLevelFile) {  
        std::ifstream inFile;
        inFile.open(highLevelFile.c_str()); 
        std::ofstream outFile(lowLevelFile.c_str());   
        if(!inFile.is_open() || !outFile.is_open()) {  
            return; 
        }   
        std::string line;  
        while (std::getline(inFile, line)) {  
            if (isLineEmptyOrWhitespace(line)) {
                continue; 
            }
            
            std::stringstream ss(line);  
            std::string opcodeStr;  
            std::getline(ss, opcodeStr, ',');  
            int opcode = strToInt(opcodeStr); 
            std::string binaryOpcode = intToBin(opcode, 4); 
            outFile << binaryOpcode;   
            int numOperands = Instructions::determineNumberOfOperands(opcode);  
            for (int i = 0; i < numOperands; ++i) {  
                std::string operandStr;  
                if (std::getline(ss, operandStr, ',')) {
                    int operand = strToInt(operandStr);  
                    std::string binaryOperand = intToBin(operand, 4);
                    outFile << binaryOperand;  
                } else {
                    break;
                }
            } 
            outFile << std::endl;  
        }   
        inFile.close();
        outFile.close(); 
    }
}