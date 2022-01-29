#include<bits/stdc++.h>
using namespace std;


void example() {
	int var = 10;  // A normal integer variable
	int *ptr = &var;  // A pointer variable that holds address of var.
	cout << "Value of var = "<< *ptr << endl;  // This line prints value at address stored in ptr.
	cout << "Address of var = " << ptr << endl;  // The output of this line may be different in different runs even on same machine.
	*ptr = 20; // Value at address is now 20
	cout << "After doing *ptr = 20, *ptr is "<< *ptr << endl;  // This prints 20
    cout << "After doing *ptr = 20, var is "<< var << endl;  // This also prints 20
    cout << "\n---- example -----\n" << endl;
}


void example2() {
	int v[3] = {10, 100, 200};  // Declare an array
	int *ptr;  // Declare pointer variable
	ptr = v;  // Assign the address of v[0] to ptr | v or &v[0]

    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;

	for (int i = 0; i < 3; i++) {
		cout << "*ptr: " << *ptr << " and ptr: " << ptr << endl;
		ptr++;  // Increment pointer ptr by 1
	}

    cout << v[0] << " " << v[1] << " " << v[2] << endl;  // valid
    // cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl; // not valid
    cout << "\n---- example2 -----\n" << endl;
}


void example3() {
    char *str1 = "HELLO";
    char *str2 = "FOR GEEKS";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = "<< str2 << endl;
    cout << "\n---- example4 -----\n" << endl;
}


int main()
{
	example();
    example2();
    example3();

	return 0;
}

// A pointer can be re-assigned