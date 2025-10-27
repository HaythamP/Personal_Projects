#ifndef BOOLEANELEMENT_H
#define BOOLEANELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class BooleanElement : public Element{
private:
    bool data;
    static bool convert(std::string);
    std::ostream& print(std::ostream& out) const;
public:
    BooleanElement(std::string data);
    bool operator==(const std::string& data)const;
    void operator()(const std::string& data);
    operator std::string() const;
};

#endif 
/* BOOLEANELEMENT_H */
