#include <iostream>
using namespace std;
typedef int Telement;
    struct Node
{
Telement info;
Node * left;
Node * right;
};
typedef Node *PNode;



class BinaryTree
{
protected:
PNode T;
public:
BinaryTree();
~BinaryTree();
PNode PARENT(PNode n);
PNode PARENT1(PNode n,PNode T);
PNode LEFT_CHILD(PNode n);
PNode RIGHT_CHILD(PNode n);
Telement GetLabel(PNode n);
PNode BuildTree1(int m);
void BuildTree(int m);
PNode ROOT();
void MAKENULL(PNode p);
void PreOrder(PNode t);
void InOrder(PNode t);
void PostOrder(PNode t);
};

BinaryTree::BinaryTree()
{
    T=nullptr;
}

BinaryTree::~BinaryTree()
{
    MAKENULL(T);
    }

void BinaryTree::MAKENULL(PNode p)
{
    if (p!=nullptr)
    {
        if (p->left!=nullptr) 
        {
            MAKENULL(p->left);
        }
        
        if (p->right!=nullptr)
        {
            MAKENULL(p->right);
        }
        delete p;
        p=nullptr;
    }
}

PNode BinaryTree::ROOT()
{
    return T;
}

PNode BinaryTree::PARENT(PNode n)
{
    if (n==T) {
        return nullptr;
    }
    return PARENT1(n,T);
}

PNode BinaryTree::PARENT1(PNode n ,PNode T)
{
    if ((T->left==n) || (T->right==n))
    {
        return T;
    }
    PNode tmp1 = nullptr;
    PNode tmp2 = nullptr;
    if (T->left!=nullptr)
    {
        tmp1=PARENT1(n,T->left);
    }
    if (T->right!=nullptr)
    {
        tmp2=PARENT1(n,T->right);
    }
    return (tmp1!=nullptr)?tmp1 :tmp2;
}

PNode BinaryTree::LEFT_CHILD(PNode n)
{
    return n->left;
}

PNode BinaryTree::RIGHT_CHILD(PNode n)
{
   
    return n->right;
    
}

Telement BinaryTree::GetLabel(PNode n)
{
    if (n!=nullptr) 
    {
        return n->info;
    }
    return -1000000000;
}

PNode BinaryTree::BuildTree1(int n)
{
    if (n==0)
    {
        return nullptr;
    }
    int nodeLeft, nodeRight;
    Telement x;
    PNode tmp;
    nodeLeft=n/ 2;
    nodeRight= n-nodeLeft-1;
    cout <<"Podaj wartość: ";
    cin >>x;
    tmp=new Node;
    tmp->info=x;
    tmp->left=BuildTree1(nodeLeft);
    tmp->right=BuildTree1(nodeRight);
    return tmp;
}
void BinaryTree::BuildTree(int n)
{
    T=BuildTree1(n);
}

void BinaryTree::PreOrder(PNode t)
{
    if (t!= nullptr)
    {
        cout << t->info<< " ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void BinaryTree::InOrder(PNode t)
{
    if (t!= nullptr)
    {
        InOrder(t->left);
        cout << t->info<< " ";
        InOrder(t->right);
    }
}

void BinaryTree::PostOrder(PNode t)
{
    if (t!= nullptr)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->info<< " ";
    }
}
