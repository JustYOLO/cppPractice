#include <iostream>
using namespace std;

class CounterType
{
    public:
        void setCount(int count);
        int getCount();
        void output();
        void countUp();
        void countDown();
    private:
        unsigned int count;
};

int main()
{
    CounterType c;
    c.setCount(100);
    int a;
    a = c.getCount();
    cout << a << '\n';
    c.output();
    c.countUp();
    c.output();
    c.countDown();
    c.countDown();
    c.output();
    c.setCount(0);
    c.countDown();
    c.output();
    return 0;
}
void CounterType::setCount(int count)
{
    if(count < 0)
    {
        cout << "input count is negative.\n";
        CounterType::count = 0;
        return;
    }
    CounterType::count = count;
}
int CounterType::getCount()
{
    return CounterType::count;
}
void CounterType::output()
{
    cout << CounterType::count << '\n';
}
void CounterType::countUp() 
{
    CounterType::count++;
}
void CounterType::countDown()
{
    if(CounterType::count <= 0)
    {
        cout << "count is already zero. \n";
        return;
    }
    CounterType::count--;
}