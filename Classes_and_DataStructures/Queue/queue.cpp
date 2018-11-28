//
// Created by zbox on 18-11-21.
//

#include "queue.h"
template <class DataType>
Queue<DataType>::Queue()
{
    front = back = &header;
}


template <class DataType>
Queue<DataType>::Queue(const Queue<DataType> &apqueue)
{
    deepcopy(apqueue);
}

template <class DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType> &rqueue)
{
     if (this == &rqueue)
         return *this;
     makeEmpty();
     deepcopy(rqueue);
     return *this;
}

template <class DataType>
void Queue<DataType>::enqueue(const DataType &element)
{
    Node<DataType>* ptr = new Node<DataType>;
    ptr->info = element;
    back->next = ptr;
    back = ptr;
}

template<class DataType>
bool Queue<DataType>::dequeue(DataType &deqElement)
{
    if (front == back == &header)
        return false;

    Node<DataType>* ptr = front->next;;
    deqElement = ptr->info;
    front->next = front->next->next;
    if (back == ptr)
    {
        back = front;
    }

    delete ptr;
    return true;
}

template <class DataType>
bool Queue<DataType>::isEmpty() const
{
    if (front == back)
    {
        return true;
    }
    else
    {
        return false;
    } // return front == back
}

template <class DataType>
bool Queue<DataType>::peek(DataType &frontElement)
{
    if (front == back)
        return false;
    frontElement = front->next->info;
    return true;
}

template <class DataType>
void Queue<DataType>::makeEmpty()
{
    DataType temp;
    while(dequeue(temp));   // dequeue等于false时候，代表队列已清空
}

template <class DataType>
Queue<DataType>::~Queue()
{
    makeEmpty();
}



template <class DataType>
void Queue<DataType>::deepcopy(const Queue<DataType> &original)
{
    Node<DataType>* pThis = front;
    Node<DataType>* pOriginal = original.front;

    while(pOriginal != original.back)
    {
        Node<DataType>* newNode = new Node<DataType>;
        newNode->info = pOriginal->next->info;
        pThis->next = newNode;
        pOriginal = pOriginal->next;
        pThis = pThis->next;
    }

    back = pThis;
}