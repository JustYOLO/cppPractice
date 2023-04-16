// sorts only 3 elements
#include <iostream>
#include <algorithm>
using namespace std;

void sort(int& a, int& b, int& c);

int main()
{
    int a, b, c;
    a = 10; b = 40; c = 5;
    sort(a, b, c);
    cout << a << ' ' << b << ' ' << c << " \n";
    return 0;
}

void sort(int& a, int& b, int& c)
{
    int intArr[3];
    intArr[0] = a; intArr[1] = b; intArr[2] = c;
    sort(intArr, intArr+3);
    a = intArr[0]; b = intArr[1], c = intArr[2];
}