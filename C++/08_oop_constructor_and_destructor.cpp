// C++ program to demonstrate constructors
#include <bits/stdc++.h>
using namespace std;

class Geeks {
	public:
        int number;
        string name;

        Geeks() {  // default Constructor
            cout << "\nGeeks()\n";
            number = -1;
        }

        Geeks(int value) {  // parametrized Constructor
            cout << "\nGeeks(int value)\n";
            number = value;
        }

        Geeks(string value) {  // function overloading
            cout << "\nGeeks(string value)\n";
            name = value;
        }

        Geeks(int value1, string value2) {
            cout << "\nGeeks(int value1, char value2)\n";
            number = value1;
            name = value2;
        }
};

void sum(int x, int y) {
    cout << "sum(int x, int y): " << x+y << endl;
}

int sum(int x, int y, int z) {
    return x+y+z;
}

class Norse {
    public:
        int id;

        Norse() {  // definition for Destructor
            cout << "Constructor called " << endl; 
        }

        ~Norse() {  // definition for Destructor
            cout << "Destructor called: " << id << endl; 
        }
};

int main() 
{	
	Geeks gpp;
	cout << "gpp: " << gpp.number << endl;

	Geeks gpp2(21);
	cout << "gpp2: " << gpp2.number << endl;

    Geeks gpp3("ww");
	cout << "gpp3: " << gpp3.name << endl;

	Geeks gpp4(21, "bucky");
	cout << "gpp2: " << gpp4.number << " and " << gpp4.name << endl;

    sum(10, 20);

    cout << "sum(int x, int y, int z): " << sum(10, 20, 30) << endl;

    Norse npp;
    npp.id = 7;
    npp.id = 100;

    int i = 0;
    while( i < 5 ) {
        Norse nppi;
        nppi.id = i;  // scope for obj2 ends here
        i++;
    }

	return 0;
}
