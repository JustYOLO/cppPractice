#include <iostream>
using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);

int main(void)
{
    int coins;
    int number, amountLeft;
    int quarters, dimes, pennies;
    cout << "input 0 to exit\n";
    while(true)
    {
        cout << "input: ";
        cin >> coins;
        if(coins == 0) break;
        amountLeft = coins;
        computeCoin(25, number, amountLeft);
        quarters = number;
        computeCoin(10, number, amountLeft);
        dimes = number;
        computeCoin(1, number, amountLeft);
        pennies = number;
        cout << coins << " cents can be given as\n";
        cout << quarters << " quarter (s) "<< dimes << " dime (s) and " << pennies << " penny (pennies)\n";
    }
    return 0;
}

void computeCoin(int coinValue, int& number, int& amountLeft)
{
    number = static_cast<int>(amountLeft/coinValue);
    //amountLeft -= number * coinValue;
    amountLeft %= coinValue;
}