#include <iostream>
using namespace std;
template <typename T>
struct Node {
    T element;
    Node<T>* next;
    Node(T value) : element(value), next(nullptr) {}
};

template <typename T>
class Set
{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        Set();
        ~Set();
        void Add(T element);
        Node<T>* Locate(T element);
        Node<T>* Previous(Node<T>* node);
        void Delete(T element);
        Set<T> Union(Set<T> first, Set<T> second);
        Set<T> Intersection(Set<T> first, Set<T> second);
        Set<T> SetDifference(Set<T> first, Set<T> second);
        void Print();
};

template <typename T> Set<T>::Set()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T> Set<T>::~Set()
{

}

template <typename T> Node<T>* Set<T>::Locate(T element)
{
    Node<T>* node = head;
    while(node!=nullptr)
    {
        if(node->element==element)
        {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

template <typename T> void Set<T>::Add(T element)
{
    Node<T>* newNode = new Node<T>(element);
    if(size==0)
    {
        head = newNode;
        tail = newNode;
        size++;
    }
    else
    {
        if(Locate(element)==nullptr)
        {
            tail-> next = newNode;
            tail = newNode;
            size++;
        }
            
    }
}

template <typename T> Node<T>* Set<T>::Previous(Node<T>* node)
{
    Node<T>* position = head;
    while(position->next!=node)
    {
        position = position->next;
    }
    return position;    
  
}
    
template <typename T> void Set<T>::Delete(T element)
{
    Node<T>* node = Locate(element);
    if(node != nullptr)
    {
        if(node != head)
        {
            Node<T>* previousNode = Previous(node);
            previousNode -> next = node -> next;
            delete node;
        }
        else
        {
            Node<T>* tmp = head;
            head = head -> next;
            delete tmp;
        }
    }
}

template <typename T> Set<T> Set<T>::Union(Set<T> first, Set<T> second)
{
    Set<T> result;
    Node<T>* secondSet = second.head;
    Node<T>* firstSet = first.head;
    while(firstSet!=nullptr)
    {
        result.Add(firstSet->element);
        firstSet = firstSet->next; 
    }
    while(secondSet!=nullptr)
    {
        result.Add(secondSet->element);
        secondSet = secondSet->next; 
    }
    return result;
}

template <typename T> Set<T> Set<T>::Intersection(Set<T> first, Set<T> second)
{
    Set<T> result;
    Node<T>* firstSet = first.head;
    while(firstSet!=nullptr)
    {
        if(second.Locate(firstSet->element)!=nullptr)
        {
            result.Add(firstSet->element);
        }
        firstSet = firstSet->next;
    }
    return result;
}

template <typename T> Set<T> Set<T>::SetDifference(Set<T> first, Set<T> second)
{
    Set<T> result;
    Node<T>* firstSet = first.head;
    while(firstSet!=nullptr)
    {
        if(second.Locate(firstSet->element)==nullptr)
        {
            result.Add(firstSet->element);
        }
        firstSet = firstSet->next;
    }
    return result;
}

template <typename T> void Set<T>::Print()
{
    Node<T>* node = head;
    while(node!=nullptr)
    {
        cout<< node->element<<endl;
        node = node -> next;
    }
}
