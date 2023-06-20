#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(double real, double imaginary);
        Complex(double real);
        Complex();
        friend const Complex operator +(const Complex& c1, const Complex& c2);
        friend const Complex operator -(const Complex& c1, const Complex& c2);
        friend const Complex operator -(const Complex& c1);
        friend const Complex operator *(const Complex& c1, const Complex& c2);
        friend bool operator ==(const Complex& c1, const Complex& c2);
        friend ostream& operator <<(ostream& outputStream, const Complex& c1);
        friend istream& operator >>(istream& inputStream, Complex& c1);
    private:
        double real;
        double imaginary;
};

int main()
{
    Complex c1(10, 10);
    Complex c2(10, 10);
    Complex c3(10);
    Complex c4(0);
    Complex c5;
    
    cin >> c2;
    if(c1 == c2) cout << "true\n";
    else cout << "false\n";
    cout << c1 << c2;
    cout << c1 * c2;
    cout << -c1;
    cout << c1 + c2;
    cout << c1 - c2;
    cout << c3;
    cout << c4;

    cout << c5;

    return 0;
}

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary)
{}
Complex::Complex(double real): real(real), imaginary(0)
{}
Complex::Complex(): real(0), imaginary(0)
{}

const Complex operator +(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real+c2.real, c1.imaginary+c2.imaginary);
}
const Complex operator -(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real-c2.real, c1.imaginary-c2.imaginary);
}
const Complex operator -(const Complex& c1)
{
    return Complex(-1*c1.real, -1*c1.imaginary);
}
const Complex operator *(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real*c2.real - c1.imaginary*c2.imaginary, c1.real*c2.imaginary + c2.real*c1.imaginary);
}
bool operator ==(const Complex& c1, const Complex& c2)
{
    if(c1.real == c2.real && c1.imaginary == c2.imaginary) return true;
    else return false;
}
ostream& operator <<(ostream& outputStream, const Complex& c1)
{
    outputStream << c1.real;
    if(c1.imaginary >= 0) outputStream << " + " << c1.imaginary << "*i\n";
    else outputStream << " - " << -1*c1.imaginary << "*i\n";
    return outputStream;
}
istream& operator >>(istream& inputStream, Complex& c1)
{
    inputStream >> c1.real >> c1.imaginary;
    return inputStream;
}