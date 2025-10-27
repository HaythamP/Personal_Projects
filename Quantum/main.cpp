#include "ComplexNamespace.h"
#include "Matrix.h"
#include "QuantumComputer.h"

using namespace complexNamespace;
using namespace std;

int main() {
    // Declaring a complex variable and setting it to 1 + 2i
    complexNumber num1 = 1 + 2 * im;
    complexNumber num2 = 1;      // A complex number with no imaginary part
    complexNumber num3 = im;     // A complex number with no real part
    complexNumber num4(10, -1);  // A different way to write 10 - i
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;
    std::cout << "num4: " << num4 << std::endl;

    std::cout << "Real part of num1: " << num1.real() << std::endl;
    std::cout << "Imaginary part of num1: " << num1.imag() << std::endl;
    std::cout << "Complex Conjugate of num1: " << conj(num1) << std::endl;

    std::cout << "num1 + num4 = " << num1 + num4 << std::endl;
    std::cout << "num1 - num4 = " << num1 - num4 << std::endl;
    std::cout << "num1 * num4 = " << num1 * num4 << std::endl;

    std::cout << "=========================================\n";
    Matrix m1(3, 2);
    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(1, 0, 3);
    m1.setValue(1, 1, 4);
    m1.setValue(2, 0, 5);
    m1.setValue(2, 1, 6);
    Matrix m2(2, 4);
    m2.setValue(0, 0, 8);
    m2.setValue(0, 1, 7);
    m2.setValue(0, 2, 6);
    m2.setValue(0, 3, 5);
    m2.setValue(1, 0, 4);
    m2.setValue(1, 1, 3);
    m2.setValue(1, 2, 2);
    m2.setValue(1, 3, 1);

    Matrix m3, m4;
    m3.multiply(m1, m2);
    m4.tensor(m1, m2);

    m1.print();
    std::cout << " * \n";
    m2.print();
    std::cout << " = \n";
    m3.print();
    std::cout << "=========================================\n";
    m1.print();
    std::cout << " tensor \n";
    m2.print();
    std::cout << " = \n";
    m4.print();

    std::cout << "=========================================\n";

    QuantumComputer qc(3);
    qc.addGate(1, 'H');
    qc.addRotationGate(0, 0.5 * M_PI, 'X');
    qc.evolveStateVector();

    return 0;
}