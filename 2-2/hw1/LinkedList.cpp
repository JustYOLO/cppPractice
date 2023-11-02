#include <iostream>
using std::cout, std::endl;

template <class T>
class LinkedList;

template <class T>
class Node
{
    private:
        T elem;
        Node* next;
    friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
    private:
        int size; // 노드의 숫자를 저장할 변수
        Node<T>* head;
    public:
        LinkedList();
        ~LinkedList();
        bool empty() const;
        const T& front() const;
        void addFront(const T& e);
        void removeFront();
        int getSize() const;
};

int main()
{
    LinkedList<int> list;
    cout << list.getSize() << endl;
    list.addFront(1);
    list.addFront(2);
    cout << list.getSize() << endl;
    list.removeFront();
    cout << list.getSize() << endl;
    list.removeFront();


}

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <class T>
LinkedList<T>::~LinkedList()
{
    while(!empty())
        removeFront();
}

template <class T>
bool LinkedList<T>::empty() const
{
    return head == nullptr;
}

template <class T>
const T& LinkedList<T>::front() const
{
    return head->elem;
}

template <class T>
void LinkedList<T>::addFront(const T& e)
{
    Node<T> *v = new Node<T>();
    v->elem = e;
    v->next = head;
    head = v;
    size++;
}

template <class T>
void LinkedList<T>::removeFront()
{
    Node<T>* old = head;
    head = old->next;
    delete old;
    size--;
}

template <class T>
int LinkedList<T>::getSize() const
{ return size; }
