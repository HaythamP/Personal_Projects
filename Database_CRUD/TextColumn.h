#ifndef TEXTCOLUMN_H
#define TEXTCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "TextElement.h"
using namespace std;

class TextColumn:public Column{
    private:
    TextElement** array;
    public:
    TextColumn(string columName,int columnSize);
    ~TextColumn();
    TextColumn* clone() const;
    TextColumn& operator+=(string data);
    TextColumn& operator-=(string data);
    TextColumn& operator-=(int index);
    int operator()(string data) const;
    TextColumn& operator()(string value,string newValue);
     TextElement const* operator[](int pos) const;
    TextElement const* operator[](string value) const ;
    bool operator!() const;
    
};
#endif /* TEXTCOLUMN_H */

