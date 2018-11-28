//
// Created by zbox on 18-7-16.
//

#include "CheckBook.h"

template<class DataType>
CheckBook<DataType>::CheckBook(float initBalance)
        : balance(initBalance), lastIndex(-1), checks(2)    //constructor with initializer list
{

}


template<class DataType>
bool CheckBook<DataType>::writeCheck(const DataType &amount)
{
    if (amount > balance)
    {
        return false
    }

    balance -= amount;
    if(lastIndex == checks.length() - 1)
    {
        checks.changeSize(2 * checks.length());
    }

    lastIndex++;
    checks[lastIndex] = amount;

    return true;
}

template<class DataType>
Array<DataType> CheckBook::getChecks()
{
    Array<DataType> info(lastIndex + 1);
    for (int i = 0, j = lastIndex ; j >= 0; i++, j--)
    {
        info[i] = checks[j];
    }

    return info;
}

template <class DataType>
float CheckBook<DataType>::getBalance() const
{
    return balance;
}

template <class DataType>
void CheckBook<DataType>::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;
}

template<class DataType>
float CheckBook<DataType>::getLastDeposit() const
{
    return lastDeposit;
}

























