#include <bits/stdc++.h>
using namespace std;


// cpp program to illustrate concept of Virtual Inheritance
void example() {

    class A {
        public:
            void show() {
                cout << "Hello from A \n";
            }
    };

    class B : public virtual A {};
    class C : public virtual A {};
    class D : public B, public C {};

    D object;
    object.show();
}

// cpp program to illustrate concept of Virtual Functions
void example2() {

    class base {
        public:
            void fun_1() { cout << "base-1\n"; }
            virtual void fun_2() { cout << "base-2\n"; }
            virtual void fun_3() { cout << "base-3\n"; }
            virtual void fun_4() { cout << "base-4\n"; }
    };

    class derived : public base {
        public:
            void fun_1() { cout << "derived-1\n"; }
            void fun_2() { cout << "derived-2\n"; }
            void fun_3() { cout << "derived-3\n"; }
            void fun_4(int x) { cout << "derived-4\n"; }
    };

	base *p;
	derived obj1;
	p = &obj1;

	p->fun_1();  // Early binding because fun1() is non-virtual in base
	p->fun_2();  // Late binding (RTP)
	p->fun_3();  // Late binding (RTP)
	p->fun_4();  // Late binding (RTP)

    obj1.fun_4(100);

	// Early binding but this function call is illegal(produces error) becasue pointer is of base type and function is of derived class
	// p->fun_4(5);
}

int main()
{
    example();
    example2();

	return 0;
}
