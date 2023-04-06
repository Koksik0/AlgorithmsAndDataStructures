#include <iostream>
using namespace std;
const int maxlength=20;
typedef int elementtype;
typedef int position;
class Stos
{
    int S[maxlength];
    position Top;//szczyt stosu
    public:
        Stos();
        void Push(elementtype x);
        void Pop();
        bool Empty();
        elementtype TopElem();
        void Makenull();
        void Print();
};

Stos::Stos()
{
    Top = -1;
}

bool Stos::Empty()
{
    if(Top==-1)
    {
        return true;
    }
    return false;
}
void Stos::Push(elementtype x)
{
    if(Top<20)
    {
        Top += 1;
        S[Top] = x;
    }
    else
    {
        cout<<"Brak miejsca na stosie"<<endl;
    }
}

void Stos::Pop()
{
    if(!Empty())
    {
        Top -= 1;
    }
    else
    {
        cout<<"Brak elementów do usunięcia na stosie"<<endl;
    }
}

elementtype Stos::TopElem()
{
    if(!Empty())
    {
        return S[Top];
    }
    else
    {
        return -100000000;
    }
}
void Stos::Makenull()
{
    Top = -1;
}
void Stos::Print()
{
    cout<<"Cały stos: "<<endl;
    for(int x = 0; x<=Top;x++)
    {
        cout<<S[x]<<" ";
    }
    cout << endl;
}
