//
// Created by zbox on 18-7-17.
//

#ifndef OOP_MINBALCHECKBOOK_H
#define OOP_MINBALCHECKBOOK_H

// MinBalCheckBook.h - a class template derived from the checkBook class template.
// The constructor and the the writecheck functions can throw exceptions if out of memory.
// to use a struct for the DataType, you must overloaded the following operators:
// > left operand: struct object  right operand: float
// used to compare the amount of the check in the struct object with the balance
// -= left operand: float right operand:struct object
// used to subtract the amount of the check in the struct object from the balance

#include "CheckBook.h"
template <class DataType>
class MinBalCheckBook : public CheckBook<DataType> {
public:
    MinBalCheckBook(float initBalance, float minBalance, float sfee, float cfee);
    bool writeCheck(const DataType& amount);
    void deductServiceFee();

private:
    float minBalance;
    float serviceFee;
    float checkFee;
};

#include "MinBalCheckBook.cpp"

#endif //OOP_MINBALCHECKBOOK_H
