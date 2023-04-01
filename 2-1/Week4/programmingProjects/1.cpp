#include <iostream>
using namespace std;

struct clock_12
{
    char noon;
    int hours;
    int mins;
};
struct clock_12 input(void);
struct clock_12 convert(int hours, int mins);
void output(struct clock_12 time);

int main(void)
{
    clock_12 time;
    time = input();
    time = convert(time.hours, time.mins);
    output(time);

    return 0;
}

struct clock_12 input(void)
{
    clock_12 time;
    cout << "시간을 입력하세요";
    cin >> time.hours >> time.mins;

    return time;
}


struct clock_12 convert(int hours, int mins) 
{
    clock_12 time;
    time.mins = mins;
    if(hours == 12)
    {
        time.noon = 'P';
        time.hours = hours;
        return time;
    }
    else if (hours > 12)
    {
        time.noon = 'P';
        time.hours = hours - 12;
        return time;
    }
    else
    {
        time.noon = 'A';
        time.hours = hours;
        return time;
    }
}

void output(struct clock_12 time)
{
    if(time.noon == 'A')
    {
        cout << time.hours << ':' << time.mins << ' ' << "A.M.";
    }
    else
    {
        cout << time.hours << ':' << time.mins << ' ' << "P.M.";
    }
}