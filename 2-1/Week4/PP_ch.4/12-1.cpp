#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());

bool head2Head(uniform_int_distribution<int>& p1, uniform_int_distribution<int>& p2);

class Gunner
{
    public:
        Gunner(uniform_int_distribution<int>& chance);
        bool isHit();
        bool isAlive() const;
        void kia();
    private:
        bool life;
        uniform_int_distribution<int> chance;
};

int main()
{
    uniform_int_distribution<int> aaron(0,2);
    uniform_int_distribution<int> bob(0,1);
    uniform_int_distribution<int> charlie(0,0);
    int aaronWin = 0;
    int aaronLose = 0;
    bool life[3]; // Aaron, Bob, Charlie seq
    for(int i = 0; i < 10000; i++) 
    {
        life[0] = true; life[1] = true; life[2] = true;
        while(1)
        {
            for(int j = 0; j < 3; j++)
            {
                if(!life[j]) continue;
            }
            if((!life[1] && !life[2]) || (!life[1] && !life[0]) || (!life[0] && !life[2])) break;
        }

        if(life[0]) aaronWin++;
        else aaronLose++;
    }

    cout << "Aaron wins: " << aaronWin << '\n'
    << "Aaron loses: " << aaronLose;
    
    return 0;
}

Gunner::Gunner(uniform_int_distribution<int>& chance): chance(chance), life(true)
{}
bool isHit()
{
    if(Gunner::chance(gen) == 0) return true;
    else false;
}
bool isAlive() const
{
    return Gunner::life;
}
void kia()
{
    Gunner::life == false;
}