#include "TextElement.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


    std::ostream& TextElement::print(std::ostream& out) const{
        out<<data;
        return out;
    }
   
    TextElement::TextElement(std::string data){
        this->data=data;
    }
    bool TextElement::operator==(const std::string& data) const{
        return this->data==data;
    }
    void TextElement::operator()(const std::string& data){
            this->data=data;
    }
    TextElement::operator std::string() const{
        return data;
    }