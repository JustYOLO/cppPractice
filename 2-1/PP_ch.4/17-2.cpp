// sorts an int vector?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int>& v);

int main()
{
    vector<int> v = {4, 7, 2, 5, 10, 8, 1, 6, 3 };
    sort(v);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}

void sort(vector<int>& v)
{
    sort(v.begin(), v.end());
}