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
        double getValue();
};

// 출력을 위해 오버로딩된 2개의 output함수
void output(int dollar, int cent);
void output(double dollar);
const Money operator +(const Money& m1, const Money& m2);
const Money operator -(const Money& m1, const Money& m2);
const Money operator -(const Money& m1);
bool operator ==(const Money& m1, const Money& m2);


int main(void)
{
    int dollar, cent; // 사용자에게 입력받을 값을 저장할 정수 변수
    Money m1(100, 99);

    output(m1.getDollar(), m1.getCent()); // 달러와 센트 값을 각각 출력
    assert(m1.getDollar() == 100 && m1.getCent() == 99 && "unexpected ouput assertion"); // 출력값과 예상값을 비교
    output(m1.getValue()); // 미화 값을 실수형태로 출력
    
    m1.setDollar(912); // m1 객체의 달러 값만 변경
    output(m1.getDollar(), m1.getCent()); // 변경된 값을 출력
    assert(m1.getDollar() == 912 && m1.getCent() == 99 && "unexpected ouput assertion"); // 출력값과 예상값을 비교
    output(m1.getValue()); // 변한 값을 출력
    m1.setCent(12); // m1 객체의 센트 값만 변경
    output(m1.getValue()); // 변한 값을 출력
    assert(m1.getDollar() == 912 && m1.getCent() == 12 && "unexpected ouput assertion"); // 출력값과 예상값을 비교

    Money m2(120, 78);
    output(m2.getDollar(), m2.getCent()); // 달러와 센트 값을 각각 출력
    assert(m2.getDollar() == 120 && m2.getCent() == 78 && "unexpected ouput assertion"); // 출력값과 예상값을 비교
    output(m2.getValue()); // 미화 값을 실수 형태로 출력

    cout << "input dollars and cents: ";
    cin >> dollar >> cent; // 사용자에게 입력 받은 값을 dollar와 cent에 저장
    Money m3(dollar, cent);
    output(m3.getDollar(), m3.getCent()); // 달러와 센트값을 각각 출력
    assert(m3.getDollar() == dollar && m3.getCent() == cent && "unexpected output assertion"); // 출력값과 예상값을 비교
    output(m3.getValue()); // 미화 값을 실수형태로 출력

    Money m4(100, 90);
    output(m4.getDollar(), m4.getCent());

    m1 = m3+m2;
    output(m1.getDollar(), m1.getCent());
    m2 = m4 - m3;
    output(m2.getDollar(), m2.getCent());
    bool test = m4 == m3;
    m2.setDollar(10);
    m2.setCent(10);
    output(m2.getDollar(), m2.getCent());
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
double Money::getValue()
{
    // Money::dollar와 Money::cent의 값을 더해서 double 자료형으로 리턴하는 함수
    return Money::dollar + Money::cent/100.0;
}

const Money operator +(const Money& m1, const Money& m2)
{
    int m1Cents = m1.getDollar() * 100 + m1.getCent();
    int m2Cents = m2.getDollar() * 100 + m2.getCent();
    int sumCents = m1Cents + m2Cents;
    int absSumCents = abs(sumCents);
    if(sumCents < 0) return Money(-1*(absSumCents/100), -1*(absSumCents%100));
    else return Money(absSumCents/100, absSumCents%100);
}
const Money operator -(const Money& m1, const Money& m2)
{
    int m1Cents = m1.getDollar() * 100 + m1.getCent();
    int m2Cents = m2.getDollar() * 100 + m2.getCent();
    int sumCents = m1Cents - m2Cents;
    int absSumCents = abs(sumCents);
    if(sumCents < 0) return Money(-1*(absSumCents/100), -1*(absSumCents%100));
    else return Money(absSumCents/100, absSumCents%100);
}
const Money operator -(const Money& m1)
{
    return Money(-m1.getDollar(), -m1.getCent());
}
bool operator ==(const Money& m1, const Money& m2)
{
    if(m1.getDollar() == m2.getDollar() && m1.getCent() == m2.getCent()) return true;
    else return false;
}
