#include<iostream>
using namespace std;

// C++ code to demonstrate the working of begin(), end(), rbegin(), rend()

void string_example() {
    string str;
    cin >> str;

	// Displaying string
	cout << "The string using forward iterators is : ";
    string::iterator it;

	for (it = str.begin(); it != str.end(); it++) // Declaring iterator
	    cout << *it << ' ';

	cout << endl;

	// Displaying reverse string
	cout << "The reverse string using reverse iterators is : ";
    string::reverse_iterator it1;

	for (it1 = str.rbegin(); it1 != str.rend(); it1++) // Declaring reverse iterator
	    cout << *it1 << ' ';

	cout << endl;
}

void string_example2() {
    string str1 = "geeksforgeeks is for geeks"; // Initializing 1st string
    string str2 = "geeksforgeeks rocks"; // Declaring 2nd string
    
    char ch[80]; // Declaring character array
    str1.copy(ch, 13, 0);  // using copy() to copy elements into char array copies "geeksforgeeks"
    cout << "The new copied character array is : " << ch << "\n\n";  // Diplaying char array
  
    cout << "before swapping: " << str1 << " and " << str2 << endl;  // Displaying strings before swapping
    str1.swap(str2); // using swap() to swap string content
    cout << "after swapping: " << str1 << " and " << str2 << endl;  // Displaying strings after swapping
}

void string_example3() {  // C++ program to demonstrate working of raw string.
	string string1 = "Geeks.\nFor.\nGeeks.\n";
	string string2 = R"(Geeks.\nFor.\nGeeks.\n)";
	cout << "A Normal string: \n" << string1 << endl;
	cout << "A Raw string: \n" << string2 << endl;
}

int main()
{
    cout << "\nexample\n"; string_example();
    cout << "\nexample2\n"; string_example2();
    cout << "\nexample3\n"; string_example3();

	return 0;
}
