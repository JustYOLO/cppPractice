#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::string;

int num(char c)
{
    if(isdigit(c)) return static_cast<int>(c) - '0';
    else return static_cast<int>(c) - 55;
}

int main()
{
    char c;
    c = '9';
    cout << num(c);

    return 0;
}