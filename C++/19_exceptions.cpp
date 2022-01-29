// Exception handling in C++ consist of three keywords: try, throw and catch:
// The try statement allows you to define a block of code to be tested for errors while it is being executed.
// The throw keyword throws an exception when a problem is detected, which lets us create a custom error.
// The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.
// The try and catch keywords come in pairs

#include <bits/stdc++.h>
using namespace std;

void example() {
    try {
        int age = 15;
        if (age >= 18)
            cout << "access granted - you are old enough" << endl;
        else
            throw age;
    }

    catch (int myNum) {
        cout << "access denied - You must be at least 18 years old" << endl;
        cout << "age is: " << myNum << endl;
    }

    cout << "example\n\n" << endl;
}


void example2() {
    try {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            string message = "divide by zeo is not allowed";
            throw message;
        }
        else
            cout << "ans: " << x/y << endl; 
            
    }

    catch (string message) {
        cout << message << endl;
    }

    cout << "example2\n\n" << endl;
}


// handle any type of exceptions
void example3() {
    try {
        int age = 15;
        if (age >= 18)
            cout << "access granted - you are old enough" << endl;
        else
            throw (age);
    }

    catch (...) {
        cout << "access denied - you must be at least 18 years old\n";
    }

    cout << "example3\n\n" << endl;
}


int main()
{
    example();
    example2();
    example3();

    return 0;
}