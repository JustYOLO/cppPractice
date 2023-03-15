#include <iostream>
using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if (n0*c >= a1*n0 + a0) {
        if (c < a1) cout << 0;
        else cout << 1;
    }
    else cout << 0;

    return 0;
}