//
// Created by zbox on 18-11-20.
//
// stack.h - the array implementation of a stack
// note: the constructor, the default copy constructor, the default assignment operator, and the push function can cause exception
// to be thrown if heap memory is exhausted

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "Array.h"

template <class DataType>
class stack
{
public:
    stack();
    void push(DataType elementToPush);

    // removes an element from the top of the stack and returns it in popElement; returns false if called on an empty stack;
    // otherwise, returns true
    bool poop(DataType& poppedElement);

    // return an element from the top of the stack in topElement without removing it; returns false if called on an empty stack;
    // otherwise, returns true
    bool peek(DataType& topElement);
    bool isEmpty(); // returns true if the stack is empty; otherwise, returns false

    void makeEmpty();

private:
    Array<DataType> elements;
    int top;
};

#include "stack.cpp"


#endif //STACK_STACK_H
