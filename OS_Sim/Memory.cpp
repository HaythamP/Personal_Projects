#include "Memory.h"
#include "IO.h"
MemoryBuffer::MemoryBufferObject* ram = NULL;    
MemoryBuffer::MemoryBufferObject* storage = NULL; 
void MemoryBuffer::printOutContents(MemoryBufferObject* memoryBufferObject)
{
    if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)

    {
        printError(0);
    }
    else{
        for (int i = 0; i < memoryBufferObject->bufferSize; i++)
        {
            std::cout<<"["<<i<<"] "<<memoryBufferObject->buffer[i]<<std::endl;
        }
    }
}
int* MemoryBuffer::dereference(MemoryBufferObject* memoryBufferObject, int memoryAddress)
{
    if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)

    {
        printError(0);
        return NULL;
    }
    if(memoryAddress<0||memoryAddress>=memoryBufferObject->bufferSize)
    {
        printError(2);
        return NULL;
    }

    return &(memoryBufferObject->buffer[memoryAddress]);
}
void MemoryBuffer::store(MemoryBufferObject* memoryBufferObject, int memoryAddress, int value)
{
    if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)

    {
        printError(0);
        return;
    }
    if(memoryAddress<0||memoryAddress>=memoryBufferObject->bufferSize)
    {
        printError(2);
        return;
    }
    memoryBufferObject->buffer[memoryAddress]=value;
}
int MemoryBuffer::read(MemoryBufferObject* memoryBufferObject, int memoryAddress)
{
    if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)

    {
        printError(0);
        return 0;
    }
    if(memoryAddress<0||memoryAddress>=memoryBufferObject->bufferSize)
    {
        printError(2);
        return 0;
    }

    return memoryBufferObject->buffer[memoryAddress];
}
void MemoryBuffer::createBuffer(MemoryBuffer::MemoryBufferObject*& memoryBufferObject, int bufferSize)
{
    if(bufferSize<0)
    {
        printError(3);
        return;
    }

    if (memoryBufferObject != NULL) {
        destroyBuffer(memoryBufferObject); 
    }

    memoryBufferObject = new MemoryBufferObject;
    memoryBufferObject->buffer = new int[bufferSize];
    memoryBufferObject->bufferSize = bufferSize;
    for (int i = 0; i < memoryBufferObject->bufferSize; i++) {
        memoryBufferObject->buffer[i] = 0;
    }
}
void MemoryBuffer::destroyBuffer(MemoryBuffer::MemoryBufferObject*& memoryBufferObject)
{
    if (memoryBufferObject == NULL) {
        return;
    }
    if (memoryBufferObject->buffer != NULL) {
        delete[] memoryBufferObject->buffer;
    }
    delete memoryBufferObject;
    memoryBufferObject = NULL;
}