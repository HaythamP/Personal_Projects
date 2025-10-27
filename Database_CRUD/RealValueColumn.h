#ifndef REALCOLUMN_H
#define REALCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "RealElement.h"
using namespace std;

class RealValueColumn:public Column{
    private:
    RealElement** array;
    public:
    RealValueColumn(string columName,int columnSize);
    ~RealValueColumn();
    RealValueColumn* clone() const;
    RealValueColumn& operator+=(string data);
    RealValueColumn& operator-=(string data);
    RealValueColumn& operator-=(int index);
    int operator()(string data) const;
    RealValueColumn& operator()(string value,string newValue);
    RealElement const* operator[](int pos) const;
    RealElement const* operator[](string value) const;
    bool operator!() const;
    
};


#endif /* REALCOLUMN_H */
