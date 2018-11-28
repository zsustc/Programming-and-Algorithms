//
// Created by nuc on 18-7-11.
// Array.h -- class template for an adjustable array
// when debugging, use #define DEBUG_ARRAY above your #include Array line
// when done debugging, comment out #define DEBUG_ARRAY for better performance
// The constructor and the changesize function can cause an exception to be thrown if out of
// heap memory
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <string>
using namespace std;

template <class DataType>
class Array
{
public:
    Array( int size );
    Array(const Array<DataType>& ap );
    inline DataType & operator [ ] ( int index );
    Array<DataType> & operator = ( const Array<DataType> & right );
    void changeSize( int newSize ); // will not alter values unless newSize is smaller than current capacity,
                                    // in this case, the values from 0 to newSize -1 will not be altered

    inline int length( ) const; // returns the current capacity of the array
    string err() const;     // returns error message from errorCode

    ~Array();

private:
    DataType *elements; // points to the dynamic array
    int capacity;
    DataType dud;   // returned from operator [ ] if index error occurs
    int errorCode;  // contains code for error if array misuse occurs
    inline void deepCopy( const Array<DataType> & original );
};

#include "Array.cpp"

#endif //ARRAY_ARRAY_H
