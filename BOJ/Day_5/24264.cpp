// time exceeded
/*#include <iostream>
using namespace std;

static int count(0);

int MenOfPassion(int A[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ::count++;
            sum += A[i]*A[j];
        }
    }
    return sum;
}

int main() {
    int A[500000];
    for(int i = 0; i < 500000; i++) A[i] = 1;
    int n;
    cin >> n;
    MenOfPassion(A, n);
    cout << ::count << '\n' << 2;

    return 0;
} */
#include <iostream>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    cout << n*n << '\n' << 2;

    return 0;
}