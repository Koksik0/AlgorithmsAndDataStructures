#include <iostream>
using namespace std;
const int maxlength=50;
typedef int elementtype;
typedef int position;
class Kolejka
{
    protected :
        elementtype Queue[maxlength];
        position Front; // Indeks elementu czołowego
        position Rear; // Indeks ostatniego elementu
    public:
        Kolejka();
        int AddOne(int i);
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        void Makenull();
        bool Empty();
        void Print();
};

Kolejka::Kolejka()
{
    Front = 0;
    Rear = maxlength-1;
}

int Kolejka::AddOne(int i)
{
    return (i+1)%maxlength;
}

bool Kolejka::Empty()
{
    if(Front-Rear==1)
    {
        return true;
    }
    if(Front==0 && Rear==49)
    {
        return true;
    }
    return false;
}

void Kolejka::Enqueue(elementtype x)
{
    if(AddOne(AddOne(Rear))==Front)
    {
        cout<<"Kolejka jest pełna, nie można wstawić kolejnego"<<endl;
    }
    else
    {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
    
}

elementtype Kolejka::FrontElem()
{
    if(Empty())
    {
        cout<<"Kolejka jest pusta, nie posiada elemntu do wyświetlenia"<<endl;
        return -1000000000;
    }
    return Queue[Front];
}

void Kolejka::Dequeue()
{
    if(Empty())
    {
        cout<<"Kolejka jest pusta, nie posiada elemntu do usunięcia"<<endl;
    }
    else
    {
        Front = AddOne(Front);
    }
    
}

void Kolejka::Makenull()
{
    Front = 0;
    Rear = maxlength-1;
}

void Kolejka::Print()
{
    for(int x = Front; x<=Rear;x++)
    {
        cout<<Queue[x]<<endl;
    }
}
