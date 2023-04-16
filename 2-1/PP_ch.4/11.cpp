#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,2);
    int changeWin = 0;
    int notChangeWin = 0;
    for(int i = 0; i < 10000; i++) 
    {
        int pDoor = dis(gen);
        int sDoor = dis(gen);
        if(pDoor == sDoor) notChangeWin++;
        else changeWin++;
    }
    cout << "change Win: " << changeWin << "\n"
    << "not change Win: " << notChangeWin << "\n";
    return 0;
}