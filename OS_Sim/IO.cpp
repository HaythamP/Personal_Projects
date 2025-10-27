#include "IO.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int strToInt(std::string str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return result;
}
std::string intToBin(int value, int size) {
    if (value < 0) {
        return std::string(size, 'X');
    }

    std::string binaryString;
    if (value == 0) {
        binaryString = "0";
    } else {
        while (value > 0) {
            binaryString = (value % 2 == 0 ? "0" : "1") + binaryString;
            value /= 2;
        }
    }

    
    while (static_cast<int>(binaryString.length()) < size) {
        binaryString = "0" + binaryString;
    }

    if (static_cast<int>(binaryString.length()) > size) {
        binaryString = binaryString.substr(static_cast<int>(binaryString.length()) - size);
    }

    return binaryString;
}
void writeToFile(std::string fileName, const int* array, int size)
{
    if(array==NULL||size<=0)
    {
        return;
    }
    else{
        std::ofstream outfile;
        outfile.open(fileName.c_str());
        for (int i = 0; i < size; ++i)
        {
            outfile<<array[i]<<"\n";
        }
        
        outfile.close();
    }

    
}
void readFromFile(std::string fileName, int* array, int size)
{
    std::ifstream infile;
    int count=0;
    if(array==NULL||size<=0)
    {
        return;
    }
    else{
        
        
        infile.open(fileName.c_str());
        
        for (int i = 0; i < size; i++)
        {
            int num;
           if(infile>>num&&count<size)
           {
            array[i]=num;
            count=count+1;
           }
        }
        
    }
    for(int i=count;i<size;i++)
    {
        array[i]=0;
    }
    infile.close();
}
void printError(int errorCode)
{
    switch (errorCode)
    {
    case 0:
        std::cout<<"Error: Buffer Is Null"<<std::endl;
        break;
    case 2:
    std::cout<<"Error: Segfault"<<std::endl;
        break;
    case 3:
    std::cout<<"Error: Invalid buffer size"<<std::endl;
        break;
    case 4:
        std::cout<<"Error: Unknown Instruction"<<std::endl;
    default:
        break;
    }
}
int obtainInput()
{
    std::cout<<"Please enter an input"<<std::endl;
    int input;
    std::cin>>input;
    return input;
}
void printOut(int value)
{
    std::cout<<"Printout: "<<value<<std::endl;
}