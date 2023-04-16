#include <iostream>
using namespace std;

int gapInMinutes(int start, int end);
void convertTime(int fourDigitTime, int& hours, int& mins);

int main()
{
    cout << gapInMinutes(1340, 509);
    return 0;
}

int gapInMinutes(int start, int end)
{
    int sHours, sMins, eHours, eMins;
    convertTime(start, sHours, sMins);
    convertTime(end, eHours, eMins);
    if(eHours - sHours < 0)
    {
        sHours = 24 + eHours - sHours;
            if(eMins - sMins < 0) {
                sHours--;
                sMins = 60 + eMins - sMins;
            }
            else sMins = eMins - sMins;
    }
    else if(eHours == sHours)
    {
        if(eMins - sMins < 0) {
            sHours = 23;
            sMins = 60 + eMins - sMins;
        }
        else {
            sHours = 0;
            sMins = eMins - sMins;
        }
    }
    else
    {
        sHours = eHours - sHours;
        if(eMins - sMins < 0) {
            sHours--;
            sMins = 60 + eMins - sMins;
        }
        else sMins = eMins - sMins;
    }

    return sHours*60+sMins;
}
void convertTime(int fourDigitTime, int& hours, int& mins)
{
    hours = fourDigitTime/100;
    mins = fourDigitTime - hours*100;
}