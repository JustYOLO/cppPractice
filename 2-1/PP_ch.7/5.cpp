#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 11; i++) {v.push_back(i+1);}
    int start = 0;
    while(v.size() > 1)
    {
        start += 2;
        if(start >= v.size()) start %= v.size();
        v.erase(v.begin() + start);
    }
    cout << v.size() << '\n';
    cout << "The winner is: " << v[0];

    return 0;
}