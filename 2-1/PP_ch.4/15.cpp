#include <iostream>
using namespace std;

bool ConvertToLowestTerms(int& numerator, int& denominator);

int main()
{
    int numerator, denominator;
    numerator = 123;
    denominator = 3;
    cout << ConvertToLowestTerms(numerator, denominator) << '\n';
    cout << numerator << '/' << denominator;

    return 0;
}

bool ConvertToLowestTerms(int& numerator, int& denominator)
{
    if(denominator == 0) return false;
    else
    {
        for(int i = 2; i <= numerator; i++)
        {
            while(numerator % i == 0 && denominator % i == 0 && numerator >= i && denominator >= i)
            {
                numerator /= i; denominator /= i;
            }
        }
        return true;
    }
}