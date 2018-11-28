//
// Created by zbox on 18-7-17.
// MinBalCheckBook.cpp -- the function definition of the class template for MinBalCheckBook
//

#include "MinBalCheckBook.h"

template <class DataType>
MinBalCheckBook<DataType>::MinBalCheckBook(float initBalance, float minBalance, float sfee, float cfee)
: CheckBook<DataType>(initBalance), minBalance(minBalance), serviceFee(sfee), checkFee(cfee)
{

}


template <class DataType>
bool MinBalCheckBook<DataType>::writeCheck(const DataType &amount)
{
    bool success = CheckBook<DataType>::writeCheck(amount);
    if (success && balance < minBalance)
    {
        balance -= checkFee;
    }

    return success;
}

template <class DataType>
void MinBalCheckBook<DataType>::deductServiceFee()
{
    if (balance < minBalance)
    {
        balance -= serviceFee;
    }
}

