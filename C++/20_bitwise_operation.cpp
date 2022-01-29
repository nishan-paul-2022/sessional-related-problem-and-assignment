#include <bits/stdc++.h>
using namespace std;


void example() {
	int a = 5, b = 9;  // a = 5(00000101), b = 9(00001001)

	// The result is 00000001 | and
	printf("a = %d, b = %d\n", a, b);
	printf("a & b = %d\n", a & b);

	// The result is 00001101 | or
	printf("a | b = %d\n", a | b);

	// The result is 00001100 | xor
	printf("a ^ b = %d\n", a ^ b);

	// The result is 11111010 | not
	printf("~a = %d\n", a = ~a);

	// The result is 00010010 | left-shift
	printf("b << 1 = %d\n", b << 1);

	// The result is 00000100 | right-shift
	printf("b >> 1 = %d\n", b >> 1);
}


// Function to return the only odd occurring element | xor
int findOdd(int arr[], int n) {
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}


// C++ code to swap using XOR
void swap() {
	int x = 10, y = 5;  // Code to swap 'x' (1010) and 'y' (0101)
	x = x ^ y; // x now becomes 15 (1111)
	y = x ^ y; // y becomes 10 (1010)
	x = x ^ y; // x becomes 5 (0101)
	cout << "After Swapping: x =" << x << ", y=" << y;
}


int main()
{
    example();

    int arr[] = {12, 12, 14, 14, 14, 14, 100, 100, 100};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The odd occurring element is %d\n", findOdd(arr, n));

    swap();

	return 0;
}
