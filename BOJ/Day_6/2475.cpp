#include <iostream>
using namespace std;

int main() {
    long int n[5];
    long int sum;
    for(int i = 0; i < 5; i++) {
        cin >> n[i];
        sum += n[i] * n[i];
    }
    cout << sum%10;
    return 0;
}