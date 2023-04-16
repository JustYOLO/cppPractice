#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter(int max);
        void reset();
        void incr1();
        void incr10();
        void incr100();
        void incr1000();
        bool overflow();
    private:
        int max;
        int count;
};

int main()
{
    Counter c1(9999);
    char key;
    while(c1.overflow())
    {
        cin >> key;
        switch (key)
        {
        case 'f':
            c1.incr1();
            break;
        case 'd':
            c1.incr10();
            break;
        case 's':
            c1.incr100();
            break;
        case 'a':
            c1.incr1000();
            break;
        default:
            break;
        }
    }
    cout << "overflowed\n";
    return 0;
}

Counter::Counter(int max): max(max), count(0)
{}
void Counter::reset() {Counter::count = 0;}
void Counter::incr1() {Counter::count += 1;}
void Counter::incr10() {Counter::count += 10;}
void Counter::incr100() {Counter::count += 100;}
void Counter::incr1000() {Counter::count += 1000;}
bool Counter::overflow()
{
    if(max >= count) return true;
    else return false;
}