#include "CharacterElement.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

char CharacterElement::convert(std::string c){
    if(c.empty()){
        return ' ';
    }
    return c[0];
}
CharacterElement::CharacterElement(std::string data){
    this->data=convert(data);
}
std::ostream& CharacterElement::print(std::ostream& out) const{
    out<<data;
    return out;
}
bool CharacterElement::operator==(const std::string& data) const{
    return this->data==convert(data);
}
void CharacterElement::operator()(const std::string& data){
        this->data=convert(data);
    }
CharacterElement::operator std::string() const{
    return std::string(1,data);
    }