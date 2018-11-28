//
// Created by nuc on 18-7-12. A program that demonstrates the use of the Array class
//

#include <iostream>
#define DEBUG_ARRAY
#include "Array.h"

using namespace std;

Array<int> getElements( );
float calcAverage( Array<int> avnums );

int main( )
{
    Array<int> nums ( 2 );

    nums = getElements(); // 重载赋值运算符

    Array<int> nums2 = nums; // 复制构造函数

    float average = calcAverage( nums2 );

    cout << "The average is: " << average << endl;

    return 0;
}

Array<int> getElements()
{
    cout << "getElements called." << endl;
    int i = 0;

    Array<int> numbers( 2 );

    cout << "Enter a positive integer: ";
    cin >> numbers[i];
    while( -1 != numbers[i])
    {
        i++;
        if ( i == numbers.length() )
        {
            numbers.changeSize( 2*i );
        }
        cout << "Enter a positive integer (enter -1 to stop): ";
        cin >> numbers[i];
    }

    numbers.changeSize(i);
    cout << "getElements: " << numbers.err();
    return numbers;
}

float calcAverage( Array<int> avnums)
{
    int sum = 0;
    for (int i = 0; i < avnums.length(); ++i)
    {
        sum += avnums[i];
    }

    cout << "calcAverage: " << avnums.err();
    return sum / float( avnums.length() );
}


