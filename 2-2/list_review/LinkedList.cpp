#include <iostream>
using std::cout;
using std::endl;

template <class T>
class LinkedList;
// forward statement

template <class T>
class DNode
{
    private:
        DNode<T>* next;
        T data;
    friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
    private:
        DNode<T>* head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        const T& front() const;
        int getSize() const;
        void addFront(const T& data);
        void removeFront();
        bool isEmpty() const;
};

int main()
{
    LinkedList<int> list = LinkedList<int>();
    list.addFront(1);
    list.addFront(2);
    cout << list.front() << endl;
    list.removeFront();
    cout << list.front() << endl;
    cout << list.isEmpty() << endl;
    cout << list.getSize() << endl;
    list.removeFront();
    cout << list.isEmpty() << endl;
    cout <<list.getSize() << endl;
    
    return 0;
}

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{}

template <class T>
LinkedList<T>::~LinkedList()
{
    while(!isEmpty())
        removeFront();
}

template <class T>
const T& LinkedList<T>::front() const
{
    return head->data;
}

template <class T>
int LinkedList<T>::getSize() const
{
    return size;
}

template <class T>
void LinkedList<T>::addFront(const T& data)
{
    DNode<T>* n = new DNode<T>(); // make a new node
    n->data = data; // insert data in new node
    n->next = head; // insert head's pointer to new node
    head = n; // change head into new node
}

template <class T>
void LinkedList<T>::removeFront()
{
    DNode<T>* n = head; // make n points to head
    head = head->next; // change head into next node of head
    delete n; // delete original head
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr;
}
