#include <iostream>
using namespace std;

double ConvertToKPH(int mins, int secs);
double ConvertToKPH(int kph);

int main()
{
    cout << ConvertToKPH(1,0) << '\n';
    cout << ConvertToKPH(ConvertToKPH(1,0));
    return 0;
}

double ConvertToKPH(int mins, int secs)
{
    // 1 miles per mins and secs
    return (1.61/(secs+60*mins))*3600;
}
double ConvertToKPH(int kph)
{
    // returns mph
    return kph/1.61;
}