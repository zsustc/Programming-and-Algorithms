//
// Created by zbox on 18-11-20.
//

#include "stack.h"

template <class DataTpe>
stack<DataTpe>::stack() : elements(2), top(-1)
{

}

template<class DataType>
bool stack<DataType>::isEmpty()
{
    /*if (-1 == top)
    {
        return true;
    }
    else
    {
        return false;
    }*/

    return (-1 == top);
}

template<class DataType>
void stack<DataType>::makeEmpty()
{
    if (-1 == top)
    {
        return;
    }
    else
    {
        top = -1;
        try {
            elements.changeSize(2);     // 将栈的容量设置成2
        }
        catch(...) {}
    }
}

template<class DataType>
bool stack<DataType>::peek(DataType &topElement)
{
    if (-1 == top)
    {
        return false;
    }
    else
    {
        topElement = elements[top];
        return true;
    }

}

template <class DataType>
bool stack<DataType>::poop(DataType &poppedElement)
{
    if (-1 == top)
    {
        return false;
    }
    else
    {
        poppedElement = elements[top];
        top--;

        // pop 后，判断是否需要将栈进行缩容
        int trysize = elements.length();
        while((top+1) <= (trysize >> 2) && (trysize > 2))
            trysize >>= 1;

        if (trysize < elements.length())
        {
            try {
                elements.changeSize(trysize);
            }
            catch (...) {}
        }

        return true;
    }
}

template<class DataType>
void stack<DataType>::push(DataType elementToPush)
{
    if (++top == elements.length())
    {
        elements.changeSize(elements.length() << 1);
    }

    elements[top] = elementToPush;
}


