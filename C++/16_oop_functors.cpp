#include <bits/stdc++.h>
using namespace std;

int increment(int x) { 
    return x+1; 
}


class FUN {

    public:
        void operator () (int *arr, int arrSize) {

            for(int i = 0; i < arrSize; i++)
                arr[i] = (arr[i] * arr[i]);
        }
};


// A C++ program uses transform() in STL to add 1 to all elements of arr[]
void functor_example() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	// Apply increment to all elements of arr[] and store the modified elements back in arr[]
	transform(arr, arr+n, arr, increment);

	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
    cout << endl;
}


void functor_example2() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    FUN kkr;
    kkr(arr, arrSize);

    for(int i = 0; i < arrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


int main()
{
    functor_example();
    functor_example2();

	return 0;
}
