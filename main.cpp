#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    double x;
    double intpart;
    double decimalPart = modf(10.111, &intpart);
    cout << intpart << " " << decimalPart;

    return 0;
}