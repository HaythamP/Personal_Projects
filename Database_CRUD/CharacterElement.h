#ifndef CHARACTERELEMENT_H
#define CHARACTERELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class CharacterElement: public Element{
private:
    char data;
    static char convert(std::string);
    std::ostream& print(std::ostream& out) const;
public:
    CharacterElement(std::string data);
    bool operator==(const std::string& data) const;
    void operator()(const std::string& data);
    operator std::string() const;
};


#endif /* CHARACTERELEMENT_H */
