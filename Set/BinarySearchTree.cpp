#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T value;
    Node<T>* parent;
    Node<T>* leftChild;
    Node<T>* rightChild;
    Node(T value) : value(value), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
    Node(T value, Node<T>* parent) : value(value), parent(parent), leftChild(nullptr), rightChild(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
    private:
        Node<T>* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        Node<T>* Search(Node<T>* x,T value);
        void Add(T element);
        Node<T>* ReturnRoot();
        void PrintInOrder(Node<T>* pointer);
        void Delete(T element);
        Node<T>* Minimum(Node<T>* pointer);
        void InOrder(Node<T>* x, BinarySearchTree<T> &set);
        void InOrder2(Node<T>* x, BinarySearchTree<T> &set, BinarySearchTree<T> set2);
        void InOrder3(Node<T>* x, BinarySearchTree<T> &set, BinarySearchTree<T> set2);
        BinarySearchTree<T> Union(BinarySearchTree<T> first, BinarySearchTree<T> second);
        BinarySearchTree<T> Difference(BinarySearchTree<T> first, BinarySearchTree<T> second);
        BinarySearchTree<T> Intersection(BinarySearchTree<T> first, BinarySearchTree<T> second);
};

template <typename T> BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <typename T> BinarySearchTree<T>::~BinarySearchTree(){}

template <typename T> Node<T>* BinarySearchTree<T>::Search(Node<T>* x,T value)
{
    if(x==nullptr || x->value==value)
        return x;
    if(value<x->value)
        return Search(x->leftChild,value);
    return Search(x->rightChild,value);
}

template <typename T> void BinarySearchTree<T>::Add(T value)
{
    Node<T>* pointerY = nullptr;
    Node<T>* pointer = root;
    if(Search(root,value)==nullptr)
    {
        while(pointer!=nullptr)
        {
            pointerY = pointer;
            if(pointer->value<value)
                pointer = pointer->rightChild;
            else
                pointer = pointer->leftChild;
        }
        if(pointerY==nullptr)
            root = new Node<T>(value);
        else if(value<pointerY->value)
            pointerY->leftChild = new Node<T>(value,pointerY);
        else
            pointerY->rightChild = new Node<T>(value,pointerY);
    }
}

template <typename T> void BinarySearchTree<T>::PrintInOrder(Node<T>* pointer)
{
    if (pointer!= nullptr)
    {
        PrintInOrder(pointer->leftChild);
        cout << pointer->value<<endl;
        PrintInOrder(pointer->rightChild);
    }
}

template <typename T> Node<T>* BinarySearchTree<T>::ReturnRoot()
{
    return root;
}

template <typename T> Node<T>* BinarySearchTree<T>::Minimum(Node<T>* pointer)
{
    Node<T>* temp = pointer;
    while(temp->leftChild!=nullptr)
    {
        temp = temp->leftChild;
    }
    return temp;
}

template <typename T> void BinarySearchTree<T>::Delete(T element)
{
    Node<T>* pointer = Search(ReturnRoot(), element);
    if(pointer!=nullptr)
    {
        if(pointer->leftChild==nullptr && pointer->rightChild==nullptr)
        {
            if(pointer->parent==nullptr)
            {
                root = nullptr;
            }
            else if(pointer->parent->value>pointer->value)
            {
                pointer->parent->leftChild = nullptr;
            }
            else
            {
                pointer->parent->rightChild = nullptr;
            }
            delete pointer;
        }
        else if(pointer->leftChild==nullptr)
        {
            Node<T>* parent = pointer->parent;
            Node<T>* child = pointer->rightChild;
            if(parent==nullptr)
            {
                root = child;
                child->parent = nullptr;
            }
            else if(parent->value > pointer->value)
            {
                parent->leftChild = child;
                child->parent = parent;
            }
            else
            {
                parent->rightChild = child;
                child->parent = parent;
            }
            delete pointer;
        }
        else if(pointer->rightChild==nullptr)
        {
            Node<T>* parent = pointer->parent;
            Node<T>* child = pointer->leftChild;
            if(parent==nullptr)
            {
                root = child;
                child->parent = nullptr;
            }
            else if(parent->value > pointer->value)
            {
                parent->leftChild = child;
                child->parent = parent;
            }
            else
            {
                parent->rightChild = child;
                child->parent = parent;
            }
            delete pointer;
        }
        else
        {
            Node<T>* min = Minimum(pointer->rightChild); 
            if(min->parent != pointer)
            {
                Node<T>* minParent = min->parent;
                minParent->leftChild = min->rightChild;
                if(min->rightChild != nullptr)
                {
                    min->rightChild->parent = minParent;
                }
                pointer->value = min->value;
            }
            else
            {
                pointer->rightChild = min->rightChild;
                if(min->rightChild != nullptr)
                {
                    min->rightChild->parent = pointer;
                }
                pointer->value = min->value;
            }
            delete min;
        }
    }
}

template <typename T> void BinarySearchTree<T>::InOrder(Node<T>* x, BinarySearchTree<T> &set)
{
    Node<T>* pointer = x;
    if (pointer!= nullptr)
    {
        InOrder(pointer->leftChild, set);
        set.Add(pointer->value);
        InOrder(pointer->rightChild, set);
    }
}

template <typename T> BinarySearchTree<T> BinarySearchTree<T>::Union(BinarySearchTree<T> first, BinarySearchTree<T> second)
{
    BinarySearchTree<T> result;
    result.InOrder(first.ReturnRoot(),result);
    result.InOrder(second.ReturnRoot(),result);
    return result;  
}

template <typename T> void BinarySearchTree<T>::InOrder2(Node<T>* x, BinarySearchTree<T> &set, BinarySearchTree<T> set2)
{
    Node<T>* pointer = x;
    if (pointer!= nullptr)
    {
        InOrder2(pointer->leftChild, set, set2);
        if(set.Search(set2.ReturnRoot(),pointer->value)==nullptr)
        {
            set.Add(pointer->value);
        }
        InOrder2(pointer->rightChild, set, set2);
    }
}

template <typename T> BinarySearchTree<T> BinarySearchTree<T>::Difference(BinarySearchTree<T> first, BinarySearchTree<T> second)
{
    BinarySearchTree<T> result;
    result.InOrder2(first.ReturnRoot(),result,second);
    return result;
}


template <typename T> void BinarySearchTree<T>::InOrder3(Node<T>* x, BinarySearchTree<T> &set, BinarySearchTree<T> set2)
{
    Node<T>* pointer = x;
    if (pointer!= nullptr)
    {
        InOrder3(pointer->leftChild, set, set2);
        if(set.Search(set2.ReturnRoot(),pointer->value)!=nullptr)
        {
            set.Add(pointer->value);
        }
        InOrder3(pointer->rightChild, set, set2);
    }
}

template <typename T> BinarySearchTree<T> BinarySearchTree<T>::Intersection(BinarySearchTree<T> first, BinarySearchTree<T> second)
{
    BinarySearchTree<T> result;
    result.InOrder3(first.ReturnRoot(),result,second);
    return result;
}
