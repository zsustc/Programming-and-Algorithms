//
// Created by zbox on 18-11-21.
//
// queue.h -- class template for the linked list implementation of a queue note:
// use of the copy constructor, overloaded assignment operator, or enqueue function
// can cause an exception to be thrown when heap memory is exhausted
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<class DataType>
struct Node
{
    DataType info;
    Node<DataType>* next;
};

template <class DataType>
class Queue
{
    Queue();
    Queue(const Queue<DataType>& apqueue);
    ~Queue();
    Queue<DataType>& operator = (const Queue<DataType>& rqueue);
    void enqueue(const DataType& element);  // insert element into the queue
    bool dequeue(DataType & deqElement);    // returns element at the front of the queue into deqElement

    // returns element at the front of the queue into frontElement without removing it
    // returns false if called on an empty queue; otherwise returns true
    bool peek(DataType& frontElement);
    bool isEmpty() const;   // returns true if the queue is empty, otherwise returns false
    void makeEmpty();

private:
    Node<DataType>* front;
    Node<DataType>* back;
    Node<DataType> header;
    inline void deepcopy(const Queue<DataType>& original);
};

#include "queue.cpp"
#endif //QUEUE_QUEUE_H
