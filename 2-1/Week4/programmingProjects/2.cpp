#include <iostream>
using namespace std;

void rectangle(int b, int l);

int main(void)
{
    int b, l;
    cout << "종료하려면 0 0을 입력하세요" << '\n';
    while(true)
    {
        cout << "길이와 폭을 입력하세요: ";
        cin >> b >> l;
        if(b == 0 && l == 0) break;
        rectangle(b, l);
    }
    return 0;
}

void rectangle(int b, int l)
{
    cout << "넓이는: " << b*l << '\n';
    cout << "둘레는: " << 2*(b+l) << '\n';
}