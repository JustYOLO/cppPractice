// #define NDEBUG
#include <iostream>
#include <cmath>
using namespace std;

class Money // Money 클래스 정의
{
    private: // 멤버 데이터를 private로 선언
        double dollar = -1.0; // Money2.cpp에선 double을 사용
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
    // Money::dollar의 정수부분(달러)을 반환하는 멤버 함수
    assert(Money::dollar > 0 && "dollar value is not set or negative value");

    double div;
    modf(Money::dollar, &div);

    return div;
}
int Money::getCent()
{
    // Money::dollar의 소수점 부분(센트)을 반환하는 멤버 함수
    assert(Money::dollar > 0 && "dollar value is not set or negative value");
    double mod;
    mod = Money::dollar - Money::getDollar();
    return round(mod*100);
}
void Money::setDollar(int dollar)
{
    // Money::dollar값의 소수점 부분은 유지한후, 정수 부분을 dollar로 변환한 후 Money::dollar에 저장하는 멤버 함수(setter)
    assert(dollar > 0 && "input is negative integer");
    int div;
    div = static_cast<int>(Money::dollar);
    Money::dollar =  dollar + Money::dollar-div;
}
void Money::setCent(int cent)
{
    // Money::dollar값의 정수 부분은 유지한후, 소수점 부분은 입력받은 cent로 변환한후 Money::dollar에 저장하는 멤버 함수(setter)
    assert(cent > 0 && "input is negative integer");
    assert(cent < 100 && "cent input is bigger then 99");
    double div, mod, tmp;
    mod = modf(Money::dollar, &div);
    Money::dollar = div + cent/100.0;
}
double Money::getValue()
{
    // Money::dollar와 Money::cent의 값을 통합적으로 cout으로 출력하는 함수
    return dollar;
}