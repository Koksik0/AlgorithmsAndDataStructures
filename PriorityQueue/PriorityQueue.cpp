#include <iostream>
#include <stdexcept> 
#include <exception>
using namespace std;
template<typename T>
struct Item
{
    T element;
    int priority;
    Item() : element(T()), priority(0) {}
    Item(const T& e, int p) : element(e), priority(p) {}
};

template<typename T>
class PriorityQueue
{
    private:
        int length = 10; 
        int currentSize;
        Item<T>** array = new Item<T>*[length];
    public:
        PriorityQueue();
        ~PriorityQueue();
        int Parent(int index);
        int LeftChild(int index);
        int RightChild(int index);
        void put(T element);
        bool isEmpty();
        T front();
        void swapItem(int index, int index2);
        void fixHeapAfterAddingNewItem(int index);
        void IncreaseSizeOfArray();
        void Put(T element, int priority);
        int max(int index);
        void fixHeapAfterRemovingItem(int index);
        T Get();
        void Makenull();
        void Print();
        void DeleteArray();
};

template <typename T>  PriorityQueue<T>::PriorityQueue()
{
    currentSize = 0;
}

template <typename T> PriorityQueue<T>::~PriorityQueue()
{

}

template <typename T> int PriorityQueue<T>::Parent(int index)
{
    if (index % 2 == 0)
    {
        return (index / 2) - 1;
    }
    return index / 2;
}

template <typename T> int PriorityQueue<T>::LeftChild(int index)
{
    return (2 * index) + 1;
}

template <typename T> int PriorityQueue<T>::RightChild(int index)
{
    return (2 * index) + 2;
}

template <typename T> bool PriorityQueue<T>::isEmpty()
{
    if(currentSize==0)
    {
        return true;
    }
    return false;
}

template <typename T> T PriorityQueue<T>::front()
{
    if(!isEmpty())
    {
        return array[0]->element;
    }
    else
    {
        throw std::out_of_range("Kolejka priorytetowa jest pusta");
    }
}

template <typename T> void PriorityQueue<T>::swapItem(int index, int index2) 
{
    Item<T>* temp = array[index];
    array[index] = array[index2];
    array[index2] = temp;
}

template <typename T> void PriorityQueue<T>::fixHeapAfterAddingNewItem(int index) 
{
    while (index > 0 && (array[Parent(index)]->priority < array[index]->priority)) 
    {
      swapItem(index, Parent(index));
      index = Parent(index);
    }
}

template <typename T> void PriorityQueue<T>::IncreaseSizeOfArray()
{
    Item<T>** newArray = new Item<T>*[length + 10];
    for(int x = 0;x<length;x++)
    {
        newArray[x] = array[x];
    }
    delete array;
    array = newArray;
    length += 10;
} 

template <typename T> void PriorityQueue<T>::Put(T element, int priority)
{
    if(currentSize==length-1)
    {
        IncreaseSizeOfArray();
    }
    array[currentSize] = new Item<T>(element,priority);
    currentSize++;
    fixHeapAfterAddingNewItem(currentSize-1);
}

template <typename T> int PriorityQueue<T>::max(int index) 
{
    if (RightChild(index) <= currentSize) 
    {
      if (array[LeftChild(index)]->priority > array[RightChild(index)]->priority) 
      {
        return LeftChild(index);
      }
    } 
    else 
    {
      return index;
    }
    if(currentSize==2)
    {
        if(array[0]->priority<array[1]->priority)
        {
            return 1;
        }
    }
    return RightChild(index);
  }

template <typename T> void PriorityQueue<T>::fixHeapAfterRemovingItem(int index) 
{
    
    int max1 = max(index);
    while (index < currentSize && array[index]->priority < array[max1]->priority && max1 < currentSize) 
    { 
      int temp = max1;
      swapItem(index, max1);
      index = temp;
      max1 = max(index);
    }
  }

template <typename T> T PriorityQueue<T>::Get()
{
    
    if(currentSize==0)
    {
        throw std::out_of_range("Kolejka priorytetowa jest pusta");
    }
    currentSize--;
    Item<T>* max = array[0];
    T element = max->element;
    swapItem(0, currentSize);
    delete array[currentSize];
    fixHeapAfterRemovingItem(0);
    return element;
    
}

template <typename T> void PriorityQueue<T>::Makenull()
{
    int end = currentSize;
    for(int x = 0;x<end;x++)
    {
        delete array[x];
        currentSize--;
    }
}

template <typename T> void PriorityQueue<T>::Print()
{
    for(int x = 0;x<currentSize;x++)
    {
        cout<<array[x]->element<<endl;
    }
}

template <typename T> void PriorityQueue<T>::DeleteArray()
{
    delete array;
}
