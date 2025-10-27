#include "RealElement.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

float RealElement::convert(std::string c){
    float out;
    std::stringstream ss(c);
    ss>>out;
    return out;
}
RealElement::RealElement(std::string data){
    this->data=convert(data);
}
void RealElement::operator()(const std::string& data){
    this->data=convert(data);

}
RealElement::operator std::string() const{
    std::stringstream ss;
    ss << data;
    return ss.str();
}
std::ostream& RealElement::print(std::ostream& out)const{
    out<<data;
    return out;

}
bool RealElement::operator==(const std::string& data) const{
        return this->data==convert(data);
}