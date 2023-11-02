#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "1";
    string s2 = "cddd";
    int n1 = stoi(s1);
    cout << "n1 is " << n1 << endl;
    try 
    {
        int n2 = stoi(s2);
    } catch (invalid_argument)
    {
        cout << "cannot convert s2 to int" << endl;
    }
    
    return 0;
}