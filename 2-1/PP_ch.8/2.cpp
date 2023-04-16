#include <iostream>
using namespace std;

class Rational
{
    public:
        Rational(int numerator, int denominator);
        Rational(int wholeNumber); // wholeNumber / 1
        Rational(); // 0 / 1

        void normalize();

        friend const Rational operator +(const Rational& r1, const Rational& r2);
        friend const Rational operator -(const Rational& r1, const Rational& r2);
        friend const Rational operator -(const Rational& r1);
        friend const Rational operator *(const Rational& r1, const Rational& r2);
        friend const Rational operator /(const Rational& r1, const Rational& r2);
        friend bool operator ==(const Rational& r1, const Rational& r2);
        friend bool operator <(const Rational& r1, const Rational& r2);
        friend bool operator <=(const Rational& r1, const Rational& r2);
        friend bool operator >(const Rational& r1, const Rational& r2);
        friend bool operator >=(const Rational& r1, const Rational& r2);
        friend ostream& operator <<(ostream& outputStream, const Rational& rationalNum);
        friend istream& operator >>(istream& inputStream, Rational& rationalNum);
    private:
        int numerator;
        int denominator;
    
};

int main()
{
    Rational r1(4, 8);
    r1.normalize();
    cout << r1;
    Rational r2(1, 4);
    r1 = r1 - r2;
    r1.normalize();
    cout << r1;
    cout << -r1;
    Rational r3(124, 42);
    r1 = r1 * r3;
    r1.normalize();
    cout << r1;

    Rational r4(1, 4);
    Rational r5(4, 1);
    r1 = r4/r5;
    r2 = r4*r5;
    cout << r1;
    r2.normalize();
    cout << r2;
    
    Rational r6(2, 8);
    if(r4 == r6) cout << "true \n";
    else cout << "false \n";

    return 0;
}


Rational::Rational(int numerator, int denominator): numerator(numerator), denominator(denominator)
{}
Rational::Rational(int wholeNumber): numerator(wholeNumber), denominator(1) 
{}
Rational::Rational(): numerator(0), denominator(1)
{}

ostream& operator <<(ostream& outputStream, const Rational& rationalNum)
{
    cout << rationalNum.numerator << '/' << rationalNum.denominator << '\n';
    return cout;
}
istream& operator >>(istream& inputStream, Rational& rationalNum)
{
    int numerator, denominator;
    cin >> numerator >> denominator;
    rationalNum.numerator = numerator; rationalNum.denominator = denominator;
    return cin;
}
void Rational::normalize()
{
    bool falseFlag = false;
    if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) falseFlag = true;

    numerator = abs(numerator);
    denominator = abs(denominator);

    for(int i = 2; i <= max(numerator, denominator); i++)
    {
        while(numerator%i == 0 && denominator%i == 0 && numerator >= i && denominator >= i)
        {
            numerator /= i;
            denominator /= i;
        }
    }
    if(falseFlag) numerator *= -1;
    if(numerator == 0) denominator = 1;
}
const Rational operator +(const Rational& r1, const Rational& r2)
{
    int n1, n2;
    n1 = r1.numerator * r2.denominator; n2 = r2.numerator * r1.denominator;
    return Rational(n1+n2, r1.denominator*r2.denominator);
}
const Rational operator -(const Rational& r1, const Rational& r2)
{
    int n1, n2;
    n1 = r1.numerator * r2.denominator; n2 = r2.numerator * r1.denominator;
    return Rational(n1-n2, r1.denominator*r2.denominator);
}
const Rational operator -(const Rational& r1)
{
    return Rational(r1.numerator * -1, r1.denominator);
}
const Rational operator *(const Rational& r1, const Rational& r2)
{
    return Rational(r1.numerator * r2.numerator, r1.denominator * r2.denominator);
}
const Rational operator /(const Rational& r1, const Rational& r2)
{
    return Rational(r1.numerator * r2.denominator, r1.denominator * r2.numerator);
}
bool operator ==(const Rational& r1, const Rational& r2)
{
    if(r1.numerator * r2.denominator == r2.numerator * r1.denominator) return true;
    else return false;
}
bool operator <(const Rational& r1, const Rational& r2)
{
    r1.normalize();
    return true;
}
/*bool operator <=(const Rational& r1, const Rational& r2)
{
    return;
}
bool operator >(const Rational& r1, const Rational& r2)
{
    return;
}
bool operator >=(const Rational& r1, const Rational& r2)
{
    return;
}*/