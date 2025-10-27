#ifndef REALELEMENT_H
#define REALELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class RealElement: public Element{
    private:
        float data;
        static float convert(std::string);
        std::ostream& print(std::ostream& out)const;
    public:
        RealElement(std::string data);
        void operator()(const std::string& data);
        operator std::string() const;
        bool operator==(const std::string& data) const;
};

#endif /* REALELEMENT_H */
