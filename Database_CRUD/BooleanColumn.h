#ifndef BOOLEANCOLUMN_H
#define BOOLEANCOLUMN_H
#include "BooleanElement.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "TemplateFunctions.h"
#include "Column.h"
#include "BooleanElement.h"

class BooleanColumn:public Column{
    private:
    BooleanElement** array;
    public:
    BooleanColumn(std::string columnName,int columnSize);
    ~BooleanColumn();
    BooleanColumn* clone() const;
    BooleanColumn& operator+=(std::string data);
    BooleanColumn& operator-=(std::string data);
    BooleanColumn& operator-=(int index);
    int operator()(std::string data) const;
    BooleanColumn& operator()(std::string value,std::string newValue);
    BooleanElement const* operator[](int pos) const;
    BooleanElement const* operator[](std::string value) const;
    bool operator!() const;
    
};


#endif
 /* BOOLEANCOLUMN_H */
