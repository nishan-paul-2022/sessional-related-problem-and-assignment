#include<bits/stdc++.h>
using namespace std;


void example() {
    int org = 10;

    int &ref = org;  // ref is a reference to org

    ref = 20;  // Value of org is now changed to 20
    cout << "x = " << org << endl;

    org = 30;  // Value of org is now changed to 30
    cout << "ref = " << ref << endl;

    cout << "\n---- example -----\n" << endl;
}


void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}


int main()
{
    example();

    int a = 2, b = 3;
    swap(a, b);
    cout << "swap(): " << a << " and " << b << endl;

    return 0;
}

// we should declare and initialize references at single step
// a reference cannot be re-assigned, and must be assigned at initialization