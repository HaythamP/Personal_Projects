#ifndef TEMPLATE_FUNCTIONS
#define TEMPLATE_FUNCTIONS

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace TemplateFunctions
{
    template <class T>
    void createAndPopulate(int size, T **&array);

    template <class T>
    void expand(int &size, T **&array, T *&new_value);

    template <class T>
    void reduce(int &size, T **&array, std::string value);

    template <class T>
    void reduce(int &size, T **&array, int index);

    template <class T>
    T *get(const int size, T ** array, std::string value);

    template <class T>
    int getIndex(const int size, T ** array, std::string value);

    template <class T>
    bool isFull(const int size, T ** array);

    template <class T>
    T **clone(const int size, T ** array);

    template <class T>
    void update(int size, T **&array, std::string oldValue, std::string newValue);

    template <class T, bool obj>
    void destroyArray(int& size, T**&a);

} // namespace TemplateFunctions

#include "TemplateFunctions.cpp"

#endif /*TEMPLATE_FUNCTIONS*/