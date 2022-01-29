#include <bits/stdc++.h>
using namespace std;

void example() {
    class Base {
        public:
            ~Base() {
                cout << "destructor is called" << endl;
            }
    };

    class Derived : public Base {
        public:
            ~Derived() {
                cout << "~Derived() is executed" << endl;
            }
    };

    Base *b = new Derived();
	delete b;
    cout << endl;
}

void example2() {
    class Base {
        public:
            virtual ~Base() {
                cout << "virtual destructor is called" << endl;
            }
    };

    class Derived : public Base {
        public:
            ~Derived() {
                cout << "~Derived() is executed" << endl;
            }
    };

    Base *b = new Derived();
	delete b;
    cout << endl;
}

int main()
{
    example();
    example2();

	return 0;
}
