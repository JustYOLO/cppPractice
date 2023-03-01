#include <iostream>
using namespace std;

int main() {
    int N, M, n1, n2, tmp;
    cin >> N >> M;
    int basket[N];
    for(int i = 0; i < N; i++) {
        basket[i] = i+1;
    }
    for(int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        swap(basket[n1-1], basket[n2-1]);
    }
    for(int num: basket) {
        cout << num << ' ';
    }
    return 0;
}