/*
5.cpp are implemented in 6.cpp
*/

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
struct metric meConvert(struct imperial fi);
void output(struct metric me);

int main(void)
{
    struct imperial fi;
    struct metric me;
    cout << "input 0 to exit\n";
    while(true)
    {
        input(fi);
        if(fi.feet == 0 && fi.inch == 0) break;
        me = meConvert(fi);
        output(me);
    }

    return 0;
}

void input(struct imperial& fi)
{
    cout << "input length: ";
    cin >> fi.feet >> fi.inch;
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

void output(struct metric me)
{
    cout << me.meters << "m " << me.centiMeters << "cm \n";
}