#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"
class TextElement: public Element{
    private:
    std::string data;
    std::ostream& print(std::ostream& out) const;
    public:
    TextElement(std::string data);
    bool operator==(const std::string& data) const;
    void operator()(const std::string& data);
    operator std::string() const;
};

#endif 
/* TEXTELEMENT_H */
