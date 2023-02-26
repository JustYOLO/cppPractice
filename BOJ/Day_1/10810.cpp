#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int basket[N];
    for(int i = 0; i < N; i++) {
        basket[i] = 0;
    }
    int start, end, num;
    for(int i = 0; i < M; i++) {
        cin >> start >> end >> num;
        for(int j = start-1; j < end; j++) basket[j] = num;
    }
    for(int i = 0; i < N; i++) {
        cout << basket[i] << ' ';
    }

    return 0;
}