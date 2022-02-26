#include <iostream>
#include <math.h>

using namespace std;

class Numar_Complex {
private:
    double real;
    double imag;

public:
    Numar_Complex(double real_, double imag_) {
        real = real_;
        imag = imag_;
    }

    void setReal(double real_) {
        real = real_;
    }

    void setImag(double imag_) {
        imag = imag_;
    }

    double getReal() {
        return real;
    }

    double getImag() {
        return imag;
    }

    void afisare() {
        if (imag < 0) {
            if (real == 0)
                cout << "-i*" << abs(imag) << endl;
            else
                cout << real << "-i*" << abs(imag) << endl;
        } else if (imag == 0)
            cout << real << endl;
        else {
            if (real == 0)
                cout << "i*" << abs(imag) << endl;
            else
                cout << real << "+i*" << abs(imag) << endl;
        }
    }

    double modul() {
        return sqrt(real*real + imag*imag);
    }

    Numar_Complex operator+(Numar_Complex const &obj) {
        Numar_Complex rez(0, 0);
        rez.real = real + obj.real;
        rez.imag = imag + obj.imag;
        return rez;
    }

    Numar_Complex operator*(Numar_Complex const &obj) {
        Numar_Complex rez(0, 0);
        rez.real = real*obj.real - imag*obj.imag;
        rez.imag = real*obj.imag + imag*obj.real;
        return rez;
    }

    Numar_Complex operator/(Numar_Complex const &obj) {
        Numar_Complex rez(0, 0);
        rez.real = (real*obj.real + imag*obj.imag)/(obj.real*obj.real + obj.imag*obj.imag);
        rez.imag = (imag*obj.real - real*obj.imag)/(obj.real*obj.real + obj.imag*obj.imag);
        return rez;
    }
};

int main() {

    Numar_Complex c1(2, -3);
    Numar_Complex c2 = c1;
    c2.setImag(5);

    c1.afisare();
    c2.afisare();

    Numar_Complex c3 = c1 + c2, c4 = c1 * c2, c5 = c1 / c2;
    c3.afisare();
    c4.afisare();
    c5.afisare();

    return 0;
}
