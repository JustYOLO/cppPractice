#include <iostream>
#include <string>
using namespace std;

template<class T>
class DLinkedList;

template <class T>
void printAll(DLinkedList<T>& list);

template <class T>
class DNode
{
    private:
        T elem;
        DNode<T>* prev;
        DNode<T>* next;
        friend class DLinkedList<T>;
};

template <class T>
class DLinkedList
{
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack(const T& e);
        void removeFront();
        void removeBack();
    private:
        DNode<T>* header;
        DNode<T>* trailer;
    protected:
        void add(DNode<T>* v, const T& e);
        void remove(DNode<T>* v);
};

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
void printAll(DLinkedList<T>& list)
{
    while(!list.empty())
    {
        cout << list.front() << ", ";
        list.removeFront();
    }
    cout << endl;
}

template <class T>
DLinkedList<T>::DLinkedList()
{
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    while(!empty())
        removeFront();
    delete header;
    delete trailer;
}

template <class T>
bool DLinkedList<T>::empty() const
{ return (header->next == trailer); }

template <class T>
const T& DLinkedList<T>::front() const
{ return header->next->elem; }

template <class T>
const T& DLinkedList<T>::back() const
{ return trailer->prev->elem; }

template <class T>
void DLinkedList<T>::add(DNode<T>* v, const T& e)
{
    DNode<T>* u = new DNode<T>; u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev = u;
    u->prev->next = u;
}

template <class T>
void DLinkedList<T>::addFront(const T& e)
{ add(header->next, e); }

template <class T>
void DLinkedList<T>::addBack(const T& e)
{ add(trailer, e); }

template <class T>
void DLinkedList<T>::remove(DNode<T>* v)
{
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <class T>
void DLinkedList<T>::removeFront()
{ remove(header->next); }

template <class T>
void DLinkedList<T>::removeBack()
{ remove(trailer->prev); }