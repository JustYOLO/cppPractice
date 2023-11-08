#include <iostream>
#include <string>
#include <sstream> // stringstream 사용
#include <stack> // stack 자료구조 사용
#include <stdexcept> // stoi() 변환 에러 발생
using namespace std;

int operation(string s, int a, int b);

int evaluatePostfix(string S)
{
    stringstream sTokens(S); // 식을 띄어쓰기 단위로 받는 stringstream
    stack<int> s; // 수를 넣을 stack
    string token; // 각 단어(operator 혹은 operand)를 받을 string
    for(int i = 0; i < S.length(); i++)
    {
        int num; // 숫자를 담을 변수
        if(isdigit(S[i]))
        {
            s.push(num); // 숫자를 stack에 추가
        }
        else
        { // 숫자 변환 불가능 -> operator인 경우
            int b = s.top(); s.pop();
            int a = s.top(); s.pop(); // operand가 될 스택의 최상단 2개의 원소를 가져옴
            s.push(operation(token, a, b));
        }
    }
    return s.top(); // 스택의 최상단을 return
}

int operation(string s, int a, int b)
{ // 주어진 연산자를 이용해 a, b를 계산하는 함수
if(s == "+") 
    return a + b; // 덧셈인 경우 ADD 반환
else if(s == "-")
    return a - b; // 뺄셈인 경우 SUB 반환
else if(s == "*")
    return a * b; // 곱셈인 경우 MUL 반환
else if(s == "/")
    return a / b; // 나눗셈인 경우 DIV 반환
else
{
    cout << "operator err" << endl;
    exit(-1); // 해당하는 operator가 없을경우 종료
}
}

int main()
{
    cout << evaluatePostfix("231*+9-") << endl;

    return 0;
}