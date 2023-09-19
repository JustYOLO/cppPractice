#include <iostream>
#include <string>
#include "DLinkedList.cpp"
using std::cout, std::cin, std::string, std::to_string, std::endl;

template <class T>
void printAll(DLinkedList<T> list);

int main()
{
    DLinkedList<char> cList;
    DLinkedList<string> sList;
    string testCase[] = {"apple", "bleach", "cat", "data", "electron", "fan", "guns", "hex", "iridium", "jacket"};
    DLinkedList<int> iList;
    for(int i = 0; i < 10; i++)
    {
        cList.addBack((char) (97 + i));
        sList.addBack(testCase[i]);
        iList.addBack(i);
    }
    cout << cList.front() << ", " << cList.back() << endl;
    cout << sList.front() << ", " << sList.back() << endl;
    cout << iList.front() << ", " << iList.back() << endl;
    printAll(cList);
    printAll(sList);
    printAll(iList);

    return 0;
}

template <class T>
void printAll(DLinkedList<T> list)
{
    while(!list.empty())
    {
        cout << list.front() << ", ";
        list.removeFront();
    }
    cout << endl;
}
