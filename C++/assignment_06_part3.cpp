// question 04 [e]
#include <bits/stdc++.h>
using namespace std;


void test(int x) { 
    try { 
        if (x > 0)
            throw x;
        else
            throw 'x';
    }

    catch(int x) {
        cout << "integer: " << x;
    }
    catch(char x) {
        cout << "\ncharacter: " << x;
    }
}


int main()
{
    test(10);
    test(0);

    return 0;
}


// integer: 10
// character: x