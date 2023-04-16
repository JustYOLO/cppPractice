#include <iostream>
using namespace std;

struct metric {
    int meters;
    double centiMeters;
};
struct imperial {
    int feet;
    double inch;
};

void input(struct imperial& fi);
void input(struct metric& me);
struct metric meConvert(struct imperial fi);
struct imperial imConvert(struct metric me);
void output(struct metric me);
void output(struct imperial fi);

int main(void)
{
    struct imperial fi;
    struct metric me;
    char unit;
    cout << "input 0 to exit\n";
    while(true)
    {
        cout << "input 'i' for imperial, 'm' for metric: ";
        cin >> unit;
        if(unit == '0') break;
        else if(unit == 'i')
        {
            input(fi);
            me = meConvert(fi);
            output(me);
        }
        else if(unit == 'm')
        {
            input(me);
            fi = imConvert(me);
            output(fi);
        }
    }

    return 0;
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