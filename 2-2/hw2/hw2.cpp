#include <iostream>
#include <string>
#include <sstream> // stringstream 사용
#include <stack> // stack 자료구조 사용
#include <stdexcept> // stoi() 변환 에러 발생(invalid_argument) 
using std::string;
using std::stack;
using std::cout;
using std::stringstream;
using std::stoi;
using std::invalid_argument; // stoi() 사용시 정수변환 불가 오류
using std::endl;

int evaluate(string expr); // postfix notation으로 된 식을 계산하는 함수
int operation(string s, int a, int b); // s 연산으로 a, b를 계산하는 함수
void resultCheck(int a, int b); // infix로 계산된 a, postfix로 계산된 b값을 비교하는 함수

int main() // 드라이버 코드
{
    string pexpr1 = "5 2 + 8 3 - * 4 /";
    // infix: ((5 + 2) * (8 - 3)) / 4
    string pexpr2 = "6 4 + 7 2 - * 5 / 2 +";
    // infix: ((6 + 4) * (7 - 2) / 5) + 2
    string pexpr3 = "3 5 * 16 4 - / 10 +";
    // infix: 3 * 5 / (16 - 4) + 10
    string pexpr4 = "10 23 12 - 24 * 2 / +";
    // infix: 10 + (((23 – 12) * 24) / 2)

    int result = evaluate(pexpr1);
    cout << "Result: " << result << endl;
    resultCheck((((5 + 2) * (8 - 3)) / 4), result);

    result = evaluate(pexpr2);
    cout << "Result: "  << result << endl;
    resultCheck((((6 + 4) * (7 - 2) / 5) + 2), result);

    result = evaluate(pexpr3);
    cout << "Result: "  << result << endl;
    resultCheck((3 * 5 / (16 - 4) + 10), result);

    result = evaluate(pexpr4);
    cout << "Result: "  << result << endl;
    resultCheck((10 + (((23 - 12) * 24) / 2)), result);
    // prefix로 된 식을 계산하고 infix로 된 식의 값과 비교
    
    return 0;
}

int evaluate(string expr)
{
    stringstream sTokens(expr); // 식을 띄어쓰기 단위로 받는 stringstream
    string token; // 각 단어(operator 혹은 operand)를 받을 string
    stack<int> s; // 수를 넣을 stack
    while(sTokens >> token) // expr(수식)의 모든 단어를 확인
    {
        int num; // 숫자를 담을 변수
        try
        {
            num = stoi(token); // 숫자일 경우 변환
            // operator인 경우 invalid_argument 오류 발생, catch문으로 이동
            s.push(num); // 숫자를 stack에 추가
        } catch (invalid_argument) 
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
        cout << "operator " << "\"" << s <<"\"" << " is invalid or unsupported operator" << endl;
        exit(-1); // 해당하는 operator가 없을 경우 종료
    }
}

void resultCheck(int a, int b)
{
    if(a == b)
        cout << "Infix and prefix results are same" << endl;
    else
        cout << "Infix and prefix results are not same" << endl;
}