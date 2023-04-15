#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());

bool head2Head(uniform_int_distribution<int>& p1, uniform_int_distribution<int>& p2);

int main()
{
    uniform_int_distribution<int> aaron(0,2);
    uniform_int_distribution<int> bob(0,1);
    uniform_int_distribution<int> charlie(0,0);
    int aaronWin = 0;
    int aaronLose = 0;
    for(int i = 0; i < 10000; i++) 
    {
        bool isAlive = true; // is Aaron alive
        if(bob(gen) == 0) // bob kills charlie
        {
            if(!head2Head(aaron, bob)) isAlive = false;
        }
        else // bob misses charlie
        {
            if(!head2Head(aaron, charlie)) isAlive = false;
        }
        

        if(isAlive) aaronWin++;
        else aaronLose++;
    }

    cout << "Aaron wins: " << aaronWin << '\n'
    << "Aaron loses: " << aaronLose;
    
    return 0;
}

bool head2Head(uniform_int_distribution<int>& p1, uniform_int_distribution<int>& p2)
{
    // if p1 wins: return true. else: return false. p1 shoots first
    while(1)
    {
        if(p1(gen) == 0) return true;
        if(p2(gen) == 0) return false;
    }
}