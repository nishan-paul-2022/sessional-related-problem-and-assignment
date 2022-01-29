// question 04 [d]
#include <bits/stdc++.h>
using namespace std;


class Test {
    static int count;
    int id;

    public:
        Test() {
            count++;
            id = count;
            cout << "Constructing object number " << id << endl;
            if(id == 4)
                throw 4;
        }
        
        ~Test() { 
            cout << "Destructing object number " << id << endl; 
        }
};

int Test::count = 0;

int main(void)
{
    try {
        Test array[5];
    }
    catch(int i) { 
        cout << "Caught " << i << endl;
    }

    return 0;
}


// Constructing object number 1
// Constructing object number 2
// Constructing object number 3
// Constructing object number 4
// Destructing object number 3
// Destructing object number 2
// Destructing object number 1
// Caught 4