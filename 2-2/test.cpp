#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool is_palindrome(string s)
{
    stack<char> st;
    queue<char> q;

    int length = s.length();
    int n = length/2;

    for(int i = 0; i < n; i++)
        st.push(s[i]);
    for(int i = n; i < length; i++)
        q.push(s[i]);
    for(int i = 0; i < n; i++)
    {
        if(st.top() != q.front())
            return false;
        st.pop(); q.pop();
    }
    return true;
}

int main(void)
{
    string s1;
    cin >> s1;
    if(is_palindrome(s1))
        cout << "s1 is palindrome" << endl;
    else
        cout << "s1 is not palindrome" << endl;
}