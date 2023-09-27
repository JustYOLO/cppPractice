#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node
{
    private:
        T elem;
        Node<T>* next;
    friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
    private:
        int size;
        Node<T>* head;
    public:
        LinkedList<T>();
        ~LinkedList<T>();
        void addFront(const T& elem);
        void removeFront();
        int size() const;
        const T& front() const;
        bool empty() const;
};

int main()
{
    LinkedList<int> list;
    list.addFront(2);
    list.addFront(1);
    cout << list.empty();
    cout << list.front() << endl; list.removeFront();
    cout << list.front() << endl; list.removeFront();
    cout << list.size();


    return 0;
}



template <class T>
LinkedList<T>::LinkedList() : size(0), head(nullptr)
{}

template <class T>
LinkedList<T>::~LinkedList()
{
    while(!empty())
        removeFront();
}

template <class T>
void LinkedList<T>::addFront(const T& elem)
{
    Node<T> v = new Node<T>();
    v->elem = elem;
    v-> next = head->next;
    head = v;
    size++;
}

template <class T>
void LinkedList<T>::removeFront()
{
    Node<T>* old = head;
    head = head->next;
    delete old;
    size--;
}

template <class T>
int LinkedList<T>::size() const
{
    return size;
}

template <class T>
const T& LinkedList<T>::front() const
{
    return head->elem;
}

template <class T>
bool LinkedList<T>::empty() const
{
    return head == nullptr;
}