#include <iostream>
using namespace std;

void input(int& big, double& small);
void meConvert(int pound, double ounce, int& kilo, double& gram);
void imConvert(int kilo, double gram, int& pound, double& ounce);
void output(int big, double small, int unit);

void input(struct imperial& fi);
void input(struct metric& me);
struct metric meConvert(struct imperial fi);
struct imperial imConvert(struct metric me);
void output(struct metric me);
void output(struct imperial fi);

struct metric {
    int meters;
    double centiMeters;
};
struct imperial {
    int feet;
    double inch;
};

int main(void)
{
    int pound, kilo, unit;
    double ounce, gram;
    char type;
    struct imperial fi;
    struct metric me;

    cout << "input 0 to exit\n";
    while(true)
    {
        cout << "input 'w' for weight convert, 'l' for length convert: ";
        cin >> type;
        if(type == '0') break;
        else if(type == 'w')
        {
            cout << "input '1' for metric, input '2' for imperial: ";
            cin >> unit;
            if(unit == 1)
            {
                input(kilo, gram);
                imConvert(kilo, gram, pound, ounce);
                output(pound, ounce, unit);
            }
            else if(unit == 2)
            {
                input(pound, ounce);
                meConvert(pound, ounce, kilo, gram);
                output(kilo, gram, unit);
            }
        }
        else if(type == 'l')
        {
            cout << "input '1' for metric, input '2' for imperial: ";
            cin >> unit;
            if(unit == 1)
            {
                input(me);
                fi = imConvert(me);
                output(fi);
            }
            else if(unit == 2)
            {
                input(fi);
                me = meConvert(fi);
                output(me);
            }
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
void output(int big, double small, int unit)
{
    if(unit == 1) cout << big << "lbs " << small << "oz \n";
    else cout << big << "kg " << small << "g \n";
}
void input(struct imperial& fi)
{
    cout << "input length: ";
    cin >> fi.feet >> fi.inch;
}
void input(struct metric& me)
{
    cout << "input length: ";
    cin >> me.meters >> me.centiMeters;
}
struct metric meConvert(struct imperial fi)
{
    double tmp = 0;
    struct metric me;
    tmp += fi.feet * 0.3048;
    tmp += fi.inch * 0.0254;
    me.meters = static_cast<int>(tmp/1);
    tmp -= me.meters;
    me.centiMeters = tmp * 100;

    return me;
}
struct imperial imConvert(struct metric me)
{
    double tmp = 0;
    struct imperial fi;
    tmp += 39.37 * me.meters;
    tmp += 0.3937 * me.centiMeters;
    fi.feet = static_cast<int>(tmp/12);
    fi.inch = tmp - (fi.feet*12);

    return fi;
}
void output(struct metric me)
{
    cout << me.meters << "m " << me.centiMeters << "cm \n";
}
void output(struct imperial fi)
{
    cout << fi.feet << "ft " << fi.inch << "in \n";
}
