#include<iostream>
using namespace std;


int max(int x, int y) {  // An example function that takes two parameters 'x' and 'y' as input and returns max of two input numbers
	if (x > y)
	    return x;
	else
	    return y;
}

int sum(int x, int y, int z=0, int w=0) {  // A function with default arguments, it can be called with 2 / 3 / 4 arguments
	return (x + y + z + w);
}

void pass_by_reference(int *address) {
	*address = 30;
}

void swap(int *value1, int *value2) {  // A function that takes two int pointer and swap them
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int main(void)
{
	int a = 10, b = 20;
	int m = max(a, b);
	cout << "maximum: " << m << endl;

	cout << sum(10, 15) << endl;
	cout << sum(10, 15, 25) << endl;
	cout << sum(10, 15, 25, 30) << endl;

    int x = 20;
    cout << "before: " <<  x << endl;
    pass_by_reference(&x);
    cout << "after: " <<  x << endl;

    int p = 100, q = 200;
    cout << "before swap: " << p << " " << q << endl;
    swap(&p, &q);
    cout << "after swap: " << p << " " << q << endl;
	return 0;
}
