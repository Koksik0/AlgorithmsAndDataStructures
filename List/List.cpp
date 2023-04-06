#include <iostream>
using namespace std;
typedef int elementtype, position ;
const int maxlength=10;
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{ 
    return l.last +1;
}

position First(List l) 
{
	return 0;
}

position Next(position p,List l)
{
	//if((p+1)<=l.last+1)
	if(p<l.last)
	{
		return p+1;
	}
	else
	{
		return -1;
	}
}

position Previous(position p,List l) 
{
	if((p-1)!=0)
	{
		return p-1;
	}
	else
	{
		return -1;
	}
}

position Locate(elementtype x, List l) 
{
	for(int y = 0;y<=l.last;y++){
		if(l.elements[y]==x){
			return y;
		}
	}
	return END(l);
}

elementtype Retrieve(position p, List l) 
{
	if(p>=0 && p<=l.last){
		return l.elements[p];
	}
	return -10000000;
}

bool Insert(int x, position p, List &l)
{
	if(l.last!=maxlength-1 && p>=0 && p<=l.last+1)
	{
		l.last++;
		for(int y = l.last;y>p;y--)
		{
			l.elements[y] = l.elements[y-1];
		}
		l.elements[p] = x;
		return true;
	}
	return false;
}

bool Delete(position p, List &l)
{
	if(p>=0 && p<=l.last){
		for(int x = p;x<l.last;x++){
			l.elements[x] = l.elements[x+1];
		}
		l.last--;
		return true;
	}
	return false;
}

void Duplicate(List &l)
{
	int last = l.last;
	for(int x = 0; x<=last;x++)
	{
		Insert(Retrieve(x,l),END(l),l);
	}
}

void Purge(List &l)
{
	for(int x = 0;x<END(l);x++)
	{
		for(int y = Next(x,l);y<END(l);y++)
		{
			if(Retrieve(x,l)==Retrieve(y,l))
			{
				Delete(y,l);
			}
		}
	}
}
void print(List l)
{
	position i=First(l);
	while (i<END(l) && i>=0)
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");
}
