#include <iostream>
#include <cmath>
using namespace std;

static int count(0);


int MenOfPassion(int A[], int n) {
    ::count++;
    return A[static_cast<int>(floor(n/2))];
}

int main() {
    int n, count; n = 0; count = 0;
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = i;
    cin >> n;
    MenOfPassion(a, n);
    cout << ::count << '\n' << 0;

    return 0;
}