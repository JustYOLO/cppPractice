template<typename T>
class DLinkedList;

template <typename T> // template 설정
class DNode
{
    private:    
        T elem; // template로 node의 데이터를 선언
        DNode<T>* prev;
        DNode<T>* next;
        friend class DLinkedList<T>;
};

template <typename T>
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
        void add(DNode<T>* v, const T& t);
        void remove(DNode<T>* v);
};

template <typename T>
DLinkedList<T>::DLinkedList()
{
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
DLinkedList<T>::~DLinkedList()
{
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const
{ return (header->next == trailer); }

template <typename T>
const T& DLinkedList<T>::front() const
{ return header->next->elem; }

template <typename T>
const T& DLinkedList<T>::back() const
{ return trailer->prev->elem; }

template <typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e)
{
    DNode<T>* u = new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev = u;
    u->prev->next = u;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e)
{ add(header->next, e); }

template <typename T>
void DLinkedList<T>::addBack(const T& e)
{ add(trailer, e); }

template <typename T>
void DLinkedList<T>::remove(DNode<T>* v)
{
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename T>
void DLinkedList<T>::removeFront()
{ remove(header->next); }

template <typename T>
void DLinkedList<T>::removeBack()
{ remove(trailer->prev); }
