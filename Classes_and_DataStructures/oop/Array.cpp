//
// Created by nuc on 18-7-11.
//

// Array.cpp -- function definition for an array

// Error codes -- use powers of 2
// 0 no error
// 1 nonpositive size passed into constructor
// 2 Invalid index was used
// 4 Nonpositive new size passed into changeSize function

#define DEBUG_ARRAY
//#define DEBUG_ARRAY
#include <iostream>
#include "Array.h"

template <class DataType>
Array<DataType>::Array( int size )
{
    if (size < 1)
    {
        capacity = 1;
        errorCode = 1; // nonpositive size
    }
    else
    {
        capacity = size;
        errorCode = 0;
    }

    elements = new DataType [capacity];
}

template <class DataType>
inline DataType & Array<DataType>::operator [ ] ( int index )
{
#ifdef DEBUG_ARRAY
    if (index < 0 || index >= capacity)
    {
        errorCode |= 2;
        return dud;
    }
#endif

return elements[ index ];

}

template<class DataType>
void Array<DataType>::changeSize(int newSize)
{
    if (1 > newSize)
    {
        errorCode |= 4;
        return;
    }

    DataType *newArray = new DataType [newSize];
    int limit = ( newSize > capacity ) ? capacity : newSize;
    for (int i = 0; i < limit; ++i)
    {
        newArray[i] = elements[i];
    }

    delete[] elements;
    elements = newArray;
    capacity = newSize;
}


template <class DataType>
inline int Array<DataType>::length() const
{
    return capacity;
}

template <class DataType>
string Array<DataType>::err() const
{
    if (0 == errorCode)
    {
        return "No error.\n";
    }

    string errorMessage = "";
    if ( errorCode & 1)
    {
        errorMessage += "Nompositive size passed into construction.\n";
        errorMessage += "the capacity was set to 1 by default.\n";
    }
    if (errorCode & 2)
    {
        errorMessage += "Index out of range.\n";
    }
    if (errorCode & 4)
    {
        errorMessage += "Nonpositive new size passed into changeSize, so\n";
        errorMessage += "the size of the array was not changed.\n";
    }

    return errorMessage;
}

template<class DataType>
Array<DataType>::~Array()
{
    cout << "Destructor called" << endl;
    delete [] elements;
}

template <class DataType>
Array<DataType>::Array( const Array<DataType> & ap )
{
    cout << "copy constructor called" << endl;
    deepCopy( ap );
}

template<class DataType>
inline void Array<DataType>::deepCopy(const Array<DataType> &original)
{
    // 将类对象结构中的数据拷贝出来
    capacity = original.capacity;
    errorCode = original.errorCode;
    elements = new DataType [capacity];
    for (int i = 0; i < capacity; ++i)
    {
        elements[i] = original.elements[i];
    }
}

template<class DataType>
Array<DataType> & Array<DataType>::operator=(const Array<DataType> &right)
{
    cout<<"Overloaded assignment operator called." << endl;
    if (this == &right)
    {
        return *this;
    }

    delete [] elements;
    deepCopy(right);
    return *this;
}






























