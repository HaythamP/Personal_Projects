#include "OS.h"
#include "Instructions.h"
#include "Memory.h"
#include "IO.h"
#include <fstream>
#include <string>
#include <iostream>

int main() {
    const int RAM_SIZE = 16;
    const int STORAGE_SIZE = 64;

    const std::string HIGH_LEVEL_FILE = "programTask.txt";
    const std::string LOW_LEVEL_FILE = "programTask_low_level.txt";
    OperatingSystem::bootComputer(RAM_SIZE, STORAGE_SIZE);
    OperatingSystem::translateProgram(HIGH_LEVEL_FILE, LOW_LEVEL_FILE);
    OperatingSystem::loadInstructions(LOW_LEVEL_FILE);
    OperatingSystem::executeProgram();
    OperatingSystem::shutDownComputer();


    return 0;
}