#include <iostream>
using std::cout;
using std::cin;

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