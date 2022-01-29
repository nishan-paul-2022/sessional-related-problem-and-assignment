#include<iostream>
using namespace std;

void example() {

	int x[3][2] = { {1,2}, {3,4}, {5,6} }; // an array with 3 rows and 2 columns

	for (int i = 0; i < 3; i++) {  // output each array element's value
		for (int j = 0; j < 2; j++) 
			cout << x[i][j] << ' ';
		cout << endl;
	}
}

void example2() {

    int y[2][3][2] = { 	{ {0,1}, {2,3}, {40,50} },  // initializing the 3-dimensional array
        				{ {6,7}, {8,9}, {10,11} }};
  
    for (int i = 0; i < 2; ++i) { // output each element's value
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k)
                cout << y[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	cout << "\nexample\n\n"; example();
	cout << "\nexample2\n\n"; example2();

	return 0;
}
