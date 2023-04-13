#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    public:
        Stack();
        void push(int n);
        int pop();
        int top() const;
        int size() const;
        bool empty() const;
    private:
        vector<int> v;
};

int main()
{
    Stack s;
    s.push(5);
    s.push(3);
    s.pop();
    s.push(7);
    s.pop();
    s.top();
    s.pop();
    cout << s.empty() << '\n';
    return 0;
}
Stack::Stack()
{
    v.clear();
}
void Stack::push(int n)
{
    v.push_back(n);
}
int Stack::pop()
{
    assert(v.size() > 0 && "Cannot pop() because stack is empty");
    int num = v.back();
    v.pop_back();
    cout << num << '\n';
    return num;
}
int Stack::top() const
{
    assert(v.size() > 0 && "Cannot top() because stack is empty");
    cout << v.back() << '\n';
    return v.back();
}
int Stack::size() const
{
    cout << v.size() << '\n';
    return v.size();
}
bool Stack::empty() const
{
    if(v.size() == 0) return true;
    else return false;
}