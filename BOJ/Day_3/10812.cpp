#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 1; i <= N; i++) v.push_back(i);
    while(M--) {
        int begin, end, mid;
        cin >> begin >> end >> mid;
        rotate(v.begin() + (begin-1), v.begin() + (mid-1), v.begin() + end);
    }
    for(int num:v) cout << num << " ";

    return 0;
}