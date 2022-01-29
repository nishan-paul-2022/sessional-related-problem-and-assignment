#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[10];  // Array declaration by specifying size

    // With recent C/C++ versions, we can also declare an array of user specified size
    int n = 10;
    int arr2[n];

    
    int arr3[] = {10, 20, 30, 40};  // Array declaration by initializing elements
    int arr4[6] = {10, 20, 30, 40}; // Compiler creates an array of size 6, initializes first 4 elements as specified by user and rest two elements as 0


	int arr5[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int arrSize = sizeof(arr5) / sizeof(arr5[0]);

	cout << "Size of arr5: " << arrSize << "\n\n";

    cout << "members of arr5: ";
	for (int i = 0; i < arrSize; i++)
		cout << arr5[i] << ' ';

	return 0;
}