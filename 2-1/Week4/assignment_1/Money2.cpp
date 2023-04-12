#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Money // Money 클래스 정의(Money2.cpp)
{
    private: // 멤버 변수를 private로 선언
        double dollar; // Money2.cpp에선 double을 사용
    public: // 멤버 변수 double dollar에 접근하는 멤버 함수 선언
        // Money::dollar의 달러 부분과 센트 부분을 리턴하는 함수 선언
        int getDollar();
        int getCent();

        // Money::dollar의 달러 부분과 센트 부분을 변경하는 함수 선언
        void setDollar(int dollar);
        void setCent(int cent);

        // Money::dollar의 값을 리턴하는 함수 선언
        double getValue();
};

// 출력을 위해 오버로딩된 2개의 output함수
void output(int dollar, int cent);
void output(double dollar);

int main(void)
{
    Money m1, m2, m3; // m1,m2는 리터럴를 입력받는 객체, m3는 사용자에게 입력받는 객체
    int dollar, cent; // 사용자에게 입력받을 값을 저장할 정수 변수
    m1.setDollar(100); 
    m1.setCent(99); // m1 객체에 리터럴로 값을 입력
    // void output(int dollar, int cent) 함수를 이용하는 경우에는 예상되는 출력값과 비교하기 위해 asset매크로를 이용
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

    m2.setDollar(120);
    m2.setCent(78); // m2 객체에 리터럴로 값을 입력
    output(m2.getDollar(), m2.getCent()); // 달러와 센트 값을 각각 출력
    assert(m2.getDollar() == 120 && m2.getCent() == 78 && "unexpected ouput assertion"); // 출력값과 예상값을 비교
    output(m2.getValue()); // 미화 값을 실수 형태로 출력

    cout << "input dollars and cents: ";
    cin >> dollar >> cent; // 사용자에게 입력 받은 값을 dollar와 cent에 저장
    m3.setDollar(dollar);
    m3.setCent(cent); // m3 객체에 값을 입력
    output(m3.getDollar(), m3.getCent()); // 달러와 센트값을 각각 출력
    assert(m3.getDollar() == dollar && m3.getCent() == cent && "unexpected output assertion"); // 출력값과 예상값을 비교
    output(m3.getValue()); // 미화 값을 실수형태로 출력
    
    return 0;
}

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

int Money::getDollar()
{
    // Money::dollar의 정수부분(달러)을 리턴하는 멤버 함수
    assert(Money::dollar >= 0 && "dollar value is negative");
    return static_cast<int>(Money::dollar);
}
int Money::getCent()
{
    // Money::dollar의 소수점 부분(센트)을 리턴하는 멤버 함수
    assert(Money::dollar >= 0 && "cent value is negative");
    return round((Money::dollar - Money::getDollar()) * 100);
}
void Money::setDollar(int dollar)
{
    // Money::dollar값의 소수점 부분은 유지한후, 정수 부분을 dollar로 변환한 후 Money::dollar에 저장하는 멤버 함수
    assert(dollar >= 0 && "dollar input is negative");
    int tmp = static_cast<int>(Money::dollar);
    Money::dollar =  dollar + Money::dollar-tmp;
}
void Money::setCent(int cent)
{
    // Money::dollar값의 정수 부분은 유지한후, 소수점 부분은 입력받은 cent로 변환한후 Money::dollar에 저장하는 멤버 함수
    assert(cent >= 0 && "cent input is negative");
    assert(cent < 100 && "cent input is bigger than 99");
    Money::dollar = Money::getDollar() + cent/100.0;
}
double Money::getValue()
{
    // Money::dollar의 값을 반환하는 함수
    assert(Money::dollar >= 0 && "Money::dollar is negative");
    return dollar;
}