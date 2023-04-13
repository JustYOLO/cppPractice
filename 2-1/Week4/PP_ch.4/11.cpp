#include <iostream>
#include <random>
using namespace std;

bool* prizeDoorSelection(bool* arr[3]);
int doorSelection();
bool isWin(bool* arr, int selection);

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 2);

int main(void)
{
    int change, nChange, selection;
    bool* arr[3];
    change = 0; nChange = 0;
    
    for(int i = 0; i < 10'000; i++)
    {
        for(int i = 0; i < 3; i++) *arr[i] = false;
        *arr = prizeDoorSelection(arr);
        //for(int i = 0; i < 3; i++) cout << *arr[i] << '\n';
        selection = doorSelection();
        if(isWin(*arr, selection)) change++;
        else nChange++;
    }
    cout << change << " : " << nChange;
    return 0;
}

bool* prizeDoorSelection(bool* arr[3])
{
    int rand = dis(gen);
    *arr[rand] = true;
    return *arr;
}
int doorSelection()
{
    return dis(gen);
}
bool isWin(bool* arr, int selection)
{
    if(arr[selection]) return false;
    else return true;
}