#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <iostream>
#include <sstream>

class Element;
std::ostream& operator<<(std::ostream& out, const Element& el);

class Element
{
protected:
    virtual std::ostream& print(std::ostream& out) const =0;
public:
    virtual ~Element(){};
    virtual bool operator==(const std::string &) const = 0;
    virtual bool operator!=(const std::string & data) const {return !((*this) == data);}
    friend std::ostream& operator<<(std::ostream& out, const Element& el);
    virtual void operator()(const std::string&) =0;
    virtual operator std::string() const =0;
};

inline std::ostream& operator<<(std::ostream& out, const Element& el){
    el.print(out);
    return out;
}

#endif /* ELEMENT_H */
