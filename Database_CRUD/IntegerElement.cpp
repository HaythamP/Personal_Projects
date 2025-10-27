#include "IntegerElement.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


int IntegerElement::convert(std::string c){
    int out;
    std::stringstream ss(c);
    ss>>out;
    return out;
}
IntegerElement::IntegerElement(std::string data){
    this->data=convert(data);
}
bool IntegerElement::operator==(const std::string& s) const {
    return data==convert(s);
}

void IntegerElement::operator()(const std::string& s) {
    data = convert(s);
}

IntegerElement::operator std::string() const {
    std::stringstream ss;
    ss<<data;
    return ss.str();
}

std::ostream& IntegerElement::print(std::ostream& out) const {
    out << data;
    return out;
}