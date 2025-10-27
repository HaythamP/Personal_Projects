#ifndef INTERGERELEMENT_H
#define INTERGERELEMENT_H

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

#include "Element.h"
class IntegerElement: public Element{
private:
int data;
static int convert(std::string);
std::ostream& print(std::ostream& out)const;

public:
IntegerElement(std::string data);
bool operator==(const std::string& s) const;
void operator()(const std::string& s);
operator std::string()const;
};

#endif /* INTERGERELEMENT_H */
