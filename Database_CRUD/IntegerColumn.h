#ifndef INTERGERCOLUMN_H
#define INTERGERCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "IntegerElement.h"

class IntegerColumn:public Column{
    private:
    IntegerElement** array;
    public:
    IntegerColumn(std::string columName,int columnSize);
    ~IntegerColumn();
    IntegerColumn* clone() const;
    IntegerColumn& operator+=(std::string data);
    IntegerColumn& operator-=(std::string data);
    IntegerColumn& operator-=(int index);
    int operator()(std::string data) const;
    IntegerColumn& operator()(std::string value,std::string newValue);
     IntegerElement const* operator[](int pos) const;
     IntegerElement const* operator[](std::string value) const;
    bool operator!() const;
    
};

#endif

/* INTERGERCOLUMN_H */
