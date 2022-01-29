// question 03
#include <bits/stdc++.h>
using namespace std;


int findValue(int array[], int SIZE, int value) {

    int i = 0;
    for(; i < SIZE && array[i] != value; i++) {}
    
    try {
        if(i==SIZE)
            throw "ERROR: Value not found";
    }
    catch(string message) {
        cout << message << endl;
    }

    cout << "subscript: " << i << endl;
    return i;
}


int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int SIZE = sizeof(array) / sizeof(array[0]);
    int value = 5;
    findValue(array, SIZE, value);

    return 0;
}

// -3

// 1
// exception: 2

// 10 / 5 = 2
// 10 + 5 = 15
// = is not a valid operator

