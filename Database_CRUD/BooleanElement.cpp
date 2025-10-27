#include "BooleanElement.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool BooleanElement::convert(std::string s){
    return (s=="T");
}
BooleanElement::BooleanElement(std::string data){
    this->data=convert(data);
}
bool BooleanElement::operator==(const std::string& data)const{
    return this->data==convert(data);
}
void BooleanElement::operator()(const std::string& data){
this->data=convert(data);
}
BooleanElement::operator std::string() const{
    return data ?"T":"F";
}
std::ostream& BooleanElement::print(std::ostream& out) const{
    out<<(data?"T":"F");
    return out;
}