#include <iostream>
#include <string>
#include <sstream> // stringstream 사용
#include <stack> // postfix notation을 구현하기 위해 stack 사용
using std::string;
using std::stack;
using std::cout;
using std::stringstream;
using std::stoi;
using std::endl;

enum Opcode // string이 operator인지 operand인지 구분할때 사용하는 enum
{
    NUM, // 숫자일 경우 해당
    ADD, // +에 해당
    SUB, // -에 해당
    MUL, // *에 해당
    DIV // /에 해당
};

int evaluate(string expr); // postfix notation으로 된 식을 계산하는 함수
Opcode whatOperator(string s); // s가 operand인지 operator인지 확인하는 함수 

int main() // 드라이버 코드
{
    string pexpr1 = "5 2 + 8 3 - * 4 /";
    int result = evaluate(pexpr1);
    cout << "Result: " << result << endl;
    return 0;
}

int evaluate(string expr)
{
    stringstream sTokens(expr); // 식을 띄어쓰기 단위로 받는 stringstream
    stack<int> s; // 수를 넣을 stack
    string token; // 각 단어(operator 혹은 operand)를 받을 string
    while(sTokens >> token) // expr(수식)의 모든 단어를 확인
    {
        Opcode code = whatOperator(token); // 함수로부터 operand 인지 operator인지 확인
        if(code != NUM) // NUM이 아닐경우 -> operator인 경우
        {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop(); // operand가 될 스택의 최상단 2개의 원소를 가져옴
            switch (code) // 해당하는 operator에 적용
            {
            case ADD: // 덧셈인 경우
                s.push(a + b);
                break;
            
            case SUB: // 뺄셈인 경우
                s.push(a - b);
                break;
            
            case MUL: // 곱셈인 경우
                s.push(a * b);
                break;
            
            case DIV: // 나눗셈인 경우
                s.push(a / b);
                break;
            
            default:
                cout << "opcode error" << endl;
                break;
            }
        }
        else // NUM인 경우 -> 숫자인 경우
            s.push(stoi(token)); 
    }

    return s.top(); // 스택의 최상단을 return
}

Opcode whatOperator(string s)
// 숫자인지, 어떤 operator인지 구분하는 함수
{
    if(s == "+") 
        return ADD; // 덧셈인 경우 ADD 반환
    else if(s == "-")
        return SUB; // 뺄셈인 경우 SUB 반환
    else if(s == "*")
        return MUL; // 곱셈인 경우 MUL 반환
    else if(s == "/")
        return DIV; // 나눗셈인 경우 DIV 반환
    else
        return NUM; // 모두 아닌 경우(숫자인 경우) NUM 반환
}