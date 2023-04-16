#define NDEBUG
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
using namespace std;

class Money // Money 클래스 정의 (Money.cpp)
{
    private: // 멤버 변수를 private로 선언
        int dollar, cent;
    public: // 멤버 변수에 접근하는 accessor(getter)와 mutator(setter) 멤버 함수 선언

        Money(int dollar, int cent);
        Money(int dollar);
        Money();
        // getter 함수 선언
        int getDollar() const;
        int getCent() const;

        // setter 함수 선언
        void setDollar(int dollar);
        void setCent(int cent);

        // Money::dollar와 Money::cent를 실수인 달러 단위 값으로 리턴하는 함수 getValue 선언
        double getValue() const;

        const Money percent(int percentFigure) const;

        friend const Money operator +(const Money& m1, const Money& m2);
        friend const Money operator -(const Money& m1, const Money& m2);
        friend const Money operator -(const Money& m1);
        friend bool operator ==(const Money& m1, const Money& m2);
        friend bool operator <(const Money& m1, const Money& m2);
        friend bool operator <=(const Money& m1, const Money& m2);
        friend bool operator >(const Money& m1, const Money& m2);
        friend bool operator >=(const Money& m1, const Money& m2);
        friend ostream& operator <<(ostream& outputStream, const Money& m1);
        friend istream& operator >>(istream& inputStream, Money& m1);
};

// 출력을 위해 오버로딩된 2개의 output함수
void output(int dollar, int cent);
void output(double dollar);

int main(void)
{
    Money m1(10, 10);
    Money m2(10, 10);
    if(m1 > m2) cout << "true" << '\n';
    else cout << "false" << '\n';

    Money m3(1000, 40);
    cout << m3.percent(25) << '\n';

    return 0;
}

Money::Money(int dollar, int cent): dollar(dollar), cent(cent)
{}
Money::Money(int dollar): dollar(dollar), cent(0)
{}
Money::Money(): dollar(0), cent(0)
{}


void output(int dollar, int cent)
{
    // 정수형 자료인 dollar와 cent를 받아서 출력하는 함수
    cout << dollar << " dollar(s), " << cent << " cent(s)\n";
}
void output(double dollar)
{
    // 실수형 자료인 dollar를 받아서 출력하는 함수
    cout << '$' << dollar << '\n';
}

int Money::getDollar() const
{
    // Money::dollar를 리턴하는 멤버 함수(getter)
    return Money::dollar;
}
int Money::getCent() const
{
    // Money::cent를 리턴하는 멤버 함수(getter)
    return Money::cent;
}
void Money::setDollar(int dollar)
{
    // Money::dollar값을 설정하는 멤버 함수(setter)
    Money::dollar = dollar;
}
void Money::setCent(int cent)
{
    // Money::cent값을 설정하는 멤버 함수(setter)
    Money::cent = cent;
}
double Money::getValue() const
{
    // Money::dollar와 Money::cent의 값을 더해서 double 자료형으로 리턴하는 함수
    return Money::dollar + Money::cent/100.0;
}
const Money Money::percent(int percentFigure) const
{
    double value = Money::getValue()/100*percentFigure;
    int dollars = static_cast<int>(value);
    int cents = round((value - dollars) * 100);
    return Money(dollars, cents);
}

const Money operator +(const Money& m1, const Money& m2)
{
    int m1Cents = m1.dollar * 100 + m1.cent;
    int m2Cents = m2.dollar * 100 + m2.cent;
    int sumCents = m1Cents + m2Cents;
    int absSumCents = abs(sumCents);
    if(sumCents < 0) return Money(-1*(absSumCents/100), -1*(absSumCents%100));
    else return Money(absSumCents/100, absSumCents%100);
}
const Money operator -(const Money& m1, const Money& m2)
{
    int m1Cents = m1.dollar * 100 + m1.cent;
    int m2Cents = m2.dollar * 100 + m2.cent;
    int sumCents = m1Cents - m2Cents;
    int absSumCents = abs(sumCents);
    if(sumCents < 0) return Money(-1*(absSumCents/100), -1*(absSumCents%100));
    else return Money(absSumCents/100, absSumCents%100);
}
const Money operator -(const Money& m1)
{
    return Money(-m1.dollar, -m1.cent);
}
bool operator ==(const Money& m1, const Money& m2)
{
    if(m1.dollar == m2.dollar && m1.cent == m2.cent) return true;
    else return false;
}
bool operator <(const Money& m1, const Money& m2)
{
    if(m1.dollar < m2.dollar) return true;
    else if(m1.dollar > m2.dollar) return false;
    else
    {
        if(m1.cent < m2.cent) return true;
        else return false;
    }
}
bool operator <=(const Money& m1, const Money& m2)
{
    if(m1.dollar < m2.dollar) return true;
    else if(m1.dollar > m2.dollar) return false;
    else
    {
        if(m1.cent <= m2.cent) return true;
        else return false;
    }
}
bool operator >(const Money& m1, const Money& m2)
{
    if(m1.dollar > m2.dollar) return true;
    else if(m1.dollar < m2.dollar) return false;
    else
    {
        if(m1.cent > m2.cent) return true;
        else return false;
    }
}
bool operator >=(const Money& m1, const Money& m2)
{
        if(m1.dollar > m2.dollar) return true;
    else if(m1.dollar < m2.dollar) return false;
    else
    {
        if(m1.cent >= m2.cent) return true;
        else return false;
    }

}

ostream& operator <<(ostream& outputStream, const Money& m1)
{
    outputStream << "$" << m1.getValue() << "\n";
    return outputStream;
}
istream& operator >>(istream& inputStream, Money& m1)
{
    int dollar, cent;
    inputStream >> dollar >> cent;
    m1.dollar = dollar, m1.cent = cent;

    return inputStream;
}
