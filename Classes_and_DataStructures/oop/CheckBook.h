//
// Created by zbox on 18-7-16.
//

#ifndef OOP_CHECKBOOK_H
#define OOP_CHECKBOOK_H

#include "Array.h"
template<class DataType>
class CheckBook {
public:
    CheckBook( float initBalance);
    bool writeCheck( const DataType & amount ); // returns false if amount is greater than balance;otherwise returns true
    void deposit( float amount);
    float getBalance() const;
    Array<DataType> getChecks();
    float getLastDeposit() const;

protected:
    float balance;

private:
    int lastIndex;      // the index of the last check that wa written
    Array<DataType> checks;
    float lastDeposit;

};

#include "CheckBook.cpp"



#endif //OOP_CHECKBOOK_H
