#include <iostream>
#include "sequence.h"

void test()
{
    Sequence sequence; 
    char response = '1';
    while (response != '0')
    {
        sequence.read();
        sequence.print();

        cout << "Enter '0' to exit or '1' to start again: " << endl;
        cin >> response;
    }
} 