#ifndef CHARACTERCOLUMN_H
#define CHARACTERCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "CharacterElement.h"
using namespace std;
class CharacterColumn:public Column{
    private:
    CharacterElement** array;
    public:
    CharacterColumn(string columName,int columnSize);
    ~CharacterColumn();
    CharacterColumn* clone() const;
    CharacterColumn& operator+=(string data);
    CharacterColumn& operator-=(string data);
    CharacterColumn& operator-=(int index);
    int operator()(string data) const;
    CharacterColumn& operator()(string value,string newValue);
    CharacterElement const* operator[](int pos) const;
    CharacterElement const* operator[](string value) const;
    bool operator!() const;
    
};

#endif
 /* CHARACTERCOLUMN_H */
