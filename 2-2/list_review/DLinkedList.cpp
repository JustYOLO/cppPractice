#include <iostream>
using std::cout;
using std::endl;

template <class T>
class DLinkedList; // forward statement

template <class T>
class DNode
{
    private:
        DNode<T>* prev;
        DNode<T>* next;
        T data;
    friend class DLinkedList<T>;
};

template <class T>
class DLinkedList
{
    private:
        DNode<T>* head;
        DNode<T>* trailer; // make two dummy nodes
        int size;
    protected:
        void add(DNode<T>* target, const T& data);
        void remove(DNode<T>* target);
    public:
        DLinkedList();
        ~DLinkedList();
        const T& front() const;
        const T& back() const;
        int getSize() const;
        bool isEmpty() const;
        void addFront(const T& data);
        void addBack(const T& data);
        void removeFront();
        void removeBack();
};

template <class T>
DLinkedList<T>::DLinkedList(): size(0)
{
    head = new DNode<T>();
    trailer = new DNode<T>();
    head->prev = nullptr;
    head->next = trailer;
    trailer->prev = head;
    trailer->next = nullptr;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    while(!isEmpty())
        removeFront();
    delete head;
    delete trailer;
}

template <class T>
const T& DLinkedList<T>::front() const
{ return head->next->data; }

template <class T>
const T& DLinkedList<T>::back() const
{ return trailer->prev->data; }

template <class T>
int DLinkedList<T>::getSize() const
{ return size; }

template <class T>
bool DLinkedList<T>::isEmpty() const
{ return head->next == trailer; }

template <class T>
void DLinkedList<T>::add(DNode<T>* target, const T& data)
{
    DNode<T>* n = new DNode<T>();
    n->data = data;
    n->prev = target;
    n->next = target->next;
    target->next->prev = n;
    target->next = n;
}

template <class T>
void DLinkedList<T>::addFront(const T& data)
{ add(head, data); }

template <class T>
void DLinkedList<T>::addBack(const T& data)
{ add(trailer->prev, data); }

template <class T>
void DLinkedList<T>::remove(DNode<T>* target)
{
    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete target;
}

template <class T>
void DLinkedList<T>::removeFront()
{ remove(head->next); }

template <class T>
void DLinkedList<T>::removeBack()
{ remove(trailer->prev); }