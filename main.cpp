#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s1 = "1";
    string s2 = "c";

    if(isdigit(static_cast<char>(s1)))
        cout << "s1 is digit" << endl;
    if(isdigit(static_cast<char>(s2)))
        cout << "s2 is digit" << endl;
    
    return 0;
}