// #define NDEBUG
#include <iostream>
using namespace std;

class Money // Money 클래스 정의
{
    private: // 멤버 데이터를 private로 선언
        int dollar = -1, cent = -1;
    public: // 멤버 데이터에 접근하는 accessor(getter)와 mutator(setter) 멤버 함수 선언
        // getter 함수 선언
        int getDollar();
        int getCent();
        // setter 함수 선언
        void setDollar(int dollar);
        void setCent(int cent);
        // 달러와 센트를 통합적으로 리턴하는 함수 getValue
        double getValue();
};

void output(int dollar, int cent);
void output(double dollar);

int main(void)
{
    Money m1, m2;
    m1.setDollar(100);
    m1.setCent(99);
    output(m1.getDollar(), m1.getCent());
    output(m1.getValue());
    
    m1.setDollar(912);
    output(m1.getDollar(), m1.getCent());
    output(m1.getValue());
    m1.setCent(12);
    output(m1.getValue());

    m2.setDollar(120);
    m2.setCent(78);
    output(m2.getDollar(), m2.getCent());
    output(m2.getValue());
    
    return 0;
}

void output(int dollar, int cent)
{
    cout << dollar << "달러 " << cent << "센트\n";
}
void output(double dollar)
{
    cout << '$' << dollar << '\n';
}

int Money::getDollar()
{
    // Money::dollar를 반환하는 멤버 함수(getter)
    assert(Money::dollar > 0 && "dollar value is not set or negative value");
    return Money::dollar;
}
int Money::getCent()
{
    // Money::cent를 반환하는 멤버 함수(getter)
    assert(Money::cent > 0 && "cent value is not set or negative value");
    return Money::cent;
}
void Money::setDollar(int dollar)
{
    // Money::dollar값을 설정하는 멤버 함수(setter)
    assert(dollar > 0 && "input is negative integer");
    Money::dollar = dollar;
}
void Money::setCent(int cent)
{
    // Money::cent값을 설정하는 멤버 함수(setter)
    assert(cent > 0 && "input is negative integer");
    assert(cent < 100 && "cent input is bigger then 99");
    Money::cent = cent;
}
double Money::getValue()
{
    // Money::dollar와 Money::cent의 값을 더해서 double 자료형으로 리턴하는 함수
    double tmp;
    assert((Money::dollar >= 0 && Money::cent >= 0) && "dollar/cent value is negative or not set");
    tmp += Money::dollar + Money::cent/100.0;
    return tmp;
}