#include <iostream>
using namespace std;

class Fraction
{
    public:
        void setNumerator(int num);
        void setDenominator(int num);
        void fractionOutput();
        double getDouble();
    private:
        int numerator;
        int denominator;
};

int main()
{
    Fraction f;
    f.setNumerator(20);
    f.setDenominator(60);
    f.fractionOutput();
    cout << f.getDouble();
}

void Fraction::setNumerator(int num)
{
    Fraction::numerator = num;
}
void Fraction::setDenominator(int num)
{
    Fraction::denominator = num;
}
void Fraction::fractionOutput()
{
    for(int i = 2; i <= max(numerator, denominator); i++)
    {
        while(numerator%i == 0 && denominator%i == 0 && numerator >= i && denominator >= i)
        {
            numerator /= i;
            denominator /= i;
        }
    }
    cout << numerator << '/' << denominator << '\n';
}
double Fraction::getDouble()
{
    return numerator/static_cast<double>(denominator);
}