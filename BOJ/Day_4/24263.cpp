#include <iostream>
using namespace std;

static int count(0);

int MenOfPassion(int A[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        ::count++;
        sum += A[i];
    }
    return sum;
}


int main() {
    int n = 0; 
    int a[500000];
    for(int i = 0; i < 10; i++) a[i] = i;
    cin >> n;
    MenOfPassion(a, n);
    cout << ::count << '\n' << 1;

    return 0;
}