#include <iostream>
using namespace std;
typedef int elementtype;
struct celltype 
{
    elementtype element;
    celltype * next;
};
typedef celltype * position;
class Lista
{
    protected :
        position l;
    public:
        Lista();
        ~Lista(); 
        void Insert(elementtype x, position p);
        void Delete(position p);
        elementtype Retrieve(position p);
        position Locate(elementtype x);
        position First();
        position Next(position p);
        position Previous(position p);
        position END();
        void Print();
        void Duplicate();
        void Purge();
};

Lista::Lista()
{
    l=new celltype;
    l->next=nullptr;
}
Lista::~Lista()
{
    position start = First();
    while(start!=nullptr)
    {
        position removable = start;
        start = start->next;
        delete removable;
    }
}

position Lista::First()
{
    return l;
}

position Lista::Next(position p)
{
    return p->next;
}

position Lista::Previous(position p)
{
    position position = First();
    while (position->next!=p) 
    {
        position=position->next;
    }
    return position;
}

void Lista::Insert(elementtype x,position p)
{
    position position = Next(p);
    p->next=new celltype;
    p->next->element=x;
    p->next->next=position;
}

void Lista::Delete(position p)
{
    position position = Next(p);
    p->next=p->next->next;
    delete position;
}

position Lista::Locate(elementtype x)
{
    position position = First();
    while (position->next!=nullptr)
    {
        if (position->next->element==x) 
        {
            return position;
        }
        position=position->next;
    }
    return position; 
}

elementtype Lista::Retrieve(position p)
{ 
    if (p->next!=nullptr)
    {
        return p->next->element;
    }
    return -1000000000;
}

position Lista::END()
{
    position position = First();
    while (position->next!=nullptr) 
    {
        position=position->next;
    }
    return position;
}


void Lista::Print() 
{
    position position = Next(First());
    while (position != nullptr) 
    {
        cout << position->element << " ";
        position = position->next;
    }
    cout << endl;
}

void Lista::Duplicate()
{
    position x = First();
    position last = END();
    while(x->next!=last->next)
    {
        Insert(x->next->element,END());
        x = x->next;
    }
}

void Lista::Purge()
{
    position current = First();
    while(current!=nullptr)
    {
        position runner = current;
        while(runner->next!=nullptr)
        {
            if(runner->next->element == current->element)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
