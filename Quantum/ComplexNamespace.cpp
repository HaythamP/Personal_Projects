#ifndef COMPLEXNAMESPACE_CPP
#define COMPLEXNAMESPACE_CPP

#include "ComplexNamespace.h"

namespace complexNamespace {

const ImaginaryUnit im = ImaginaryUnit();

ImaginaryUnit::operator complexNumber() const {
    return complexNumber(0.0, 1.0);
}

complexNumber operator*(double d, const ImaginaryUnit&) {
    return complexNumber(0.0, d);
}

complexNumber operator*(const ImaginaryUnit&, double d) {
    return complexNumber(0.0, d);
}

complexNumber operator+(double re, const complexNumber& imag) {
    return complexNumber(re, imag.imag());
}

complexNumber operator+(const complexNumber& imag, double re) {
    return complexNumber(re, imag.imag());
}

complexNumber operator-(double re, const complexNumber& imag) {
    return complexNumber(re, -imag.imag());
}

}  // namespace complexNamespace

#endif
