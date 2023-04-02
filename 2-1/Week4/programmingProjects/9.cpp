#include <iostream>
using namespace std;

void input(int& big, double& small);
void meConvert(int pound, double ounce, int& kilo, double& gram);
void imConvert(int kilo, double gram, int& pound, double& ounce);
void output(int big, double small, char unit);

int main(void)
{
    int pound, kilo;
    double ounce, gram;
    char unit;
    while(true)
    {
        cout << "input 0 to exit\n" << "input i for imperial, m for metric: ";
        cin >> unit;
        if(unit == '0') break;
        else if(unit == 'i')
        {
            input(pound, ounce);
            meConvert(pound, ounce, kilo, gram);
            output(kilo, gram, unit);
        }
        else if(unit == 'm')
        {
            input(kilo, gram);
            imConvert(kilo, gram, pound, ounce);
            output(pound, ounce, unit);
        }
    }

    return 0;
}

void input(int& big, double& small)
{
    cout << "input weight: ";
    cin >> big >> small;
}
void meConvert(int pound, double ounce, int& kilo, double& gram)
{
    double tmp = 0;
    tmp += pound * 16;
    tmp += ounce;
    tmp /= 35.274;
    kilo = static_cast<int>(tmp/1);
    gram = (tmp - kilo)*1000;
}
void imConvert(int kilo, double gram, int& pound, double& ounce)
{
    double tmp = 0;
    tmp += kilo * 1000;
    tmp += gram;
    tmp /= 453.6;
    pound = static_cast<int>(tmp/1);
    ounce = (tmp - pound)*16;
}
void output(int big, double small, char unit)
{
    if(unit == 'm') cout << big << "lbs " << small << "oz \n";
    else cout << big << "kg " << small << "g \n";
}
