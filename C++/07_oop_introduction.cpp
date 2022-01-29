// C++ program to demonstrate accessing of members
#include <bits/stdc++.h>
using namespace std;

class Geeks {
	public:  // access specifier
		string geekname;  // property

		void printname() {  // method
			cout << "Geekname is: " << geekname << endl;
		}

		void random_method();
};

// Definition of random_method using scope resolution operator ::
void Geeks::random_method() {
    cout << "Random value is: " << rand()%100 << endl; 
}

int main()  
{
	Geeks obj1;  // Declare an object of class geeks
	obj1.geekname = "Abhi";  // accessing  property
	obj1.printname();  // accessing mthod
	obj1.random_method();

	return 0;
}
