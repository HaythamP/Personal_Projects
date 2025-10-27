#ifndef COMPLEXNAMESPACE_H
#define COMPLEXNAMESPACE_H

#include <complex>

namespace complexNamespace {

typedef std::complex<double> complexNumber;

struct ImaginaryUnit {
    operator complexNumber() const;
};

extern const ImaginaryUnit im;

complexNumber operator*(double d, const ImaginaryUnit&);
complexNumber operator*(const ImaginaryUnit&, double d);

complexNumber operator+(double re, const complexNumber& imag);
complexNumber operator+(const complexNumber& imag, double re);

complexNumber operator-(double re, const complexNumber& imag);

}  // namespace complexNamespace

#endif
