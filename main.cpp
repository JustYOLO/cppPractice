#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    char c;
    int *p = static_cast<int*>(&c);
    *p = 4004;
    cout << *p;
}