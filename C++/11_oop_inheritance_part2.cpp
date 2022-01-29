#include <bits/stdc++.h>
using namespace std;

// C++ program to explain Single inheritance
void single_inheritance() {

    class Vehicle {  // base class
        public:
            void nothing() {
                cout << "\nI1: single_inheritance" << "\n\n";
            }

            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }
    };

    class Car: public Vehicle {  // sub class derived from a single base classes

    };

	Car obj;  // creating object of sub class will invoke the constructor of base classes
    obj.nothing();
}

// C++ program to explain multiple inheritance
void multiple_inheritance() {

    class Vehicle {  // first base class
        public:
            void nothing() {
                cout << "\nI2: multiple_inheritance" << "\n\n";
            }

            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }
    };

    class FourWheeler {  // second base class
        public:
            FourWheeler() {
                cout << "This is a 4 wheeler Vehicle" << endl;
            }
    };

    class Car: public Vehicle, public FourWheeler {  // sub class derived from two base classes

    };

    Car obj;
    obj.nothing();
}

// C++ program to implement Multilevel Inheritance
void multilevel_inheritance() {

    class Vehicle {  // base class
        public:
            void nothing() {
                cout << "\nI3: multilevel_inheritance" << "\n\n";
            }

            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }
    };

    class fourWheeler: public Vehicle {  // first sub_class derived from class vehicle
        public:
            fourWheeler() {
                cout << "Objects with 4 wheels are vehicles" << endl;
            }
    };

    class Car: public fourWheeler {  // sub class derived from the derived base class fourWheeler
        public:
            Car() {
                cout << "Car has 4 Wheels" << endl;
            }
    };

    Car obj;
    obj.nothing();
}

// C++ program to implement Hierarchical Inheritance
void hierarchical_inheritance() {

    class Vehicle {  // base class
        public:
            void nothing() {
                cout << "\nI4: hierarchical_inheritance" << "\n\n";
            }

            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }
    };

    class Car: public Vehicle {  // first sub class

    };
    
    class Bus: public Vehicle {  // second sub class

    };

	Car obj1; obj1.nothing();
	Bus obj2; obj2.nothing();

}

// Hybrid Inheritance is implemented by combining more than one type of inheritance
void hybrid_inheritance() {
    class Vehicle {  // base class
        public:
            void nothing() {
                cout << "\nI5: hybrid_inheritance" << "\n\n";
            }

            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }
    };

    class Fare {  //base class
        public:
            Fare() {
                cout<<"Fare of Vehicle\n";
            }
    };

    class Car: public Vehicle { // first sub class

    };

    class Bus: public Vehicle, public Fare { // second sub class

    };

    Bus obj;
    obj.nothing();
}

// C++ program demonstrating ambiguity in Multipath Inheritance
void multipath_inheritance() {

    class ClassA {
        public:
            int a;
    };

    class ClassB : public ClassA {
        public:
            int b;
    };

    class ClassC : public ClassA {
        public:
            int c;
    };

    class ClassD : public ClassB, public ClassC {
        public:
            int d;
    };

	ClassD obj;

	// obj.a = 1;  // Statement 1, Error
	// obj.a = 2;  // Statement 2, Error

	obj.ClassB::a = 1; // Statement 3
	obj.ClassC::a = 1; // Statement 4

	obj.b = 20;
	obj.c = 30;
	obj.d = 40;

	cout << "A from ClassB : " << obj.ClassB::a << endl;
	cout << "A from ClassC : " << obj.ClassC::a << endl;

	cout << "B : " << obj.b << endl;
	cout << "C : " << obj.c << endl;
	cout << "D : " << obj.d << endl;

    cout << "\nI6: multipath_inheritance" << "\n\n";
}

int main()
{
	single_inheritance();
    multiple_inheritance();
    multilevel_inheritance();
    hierarchical_inheritance();
    hybrid_inheritance();
    multipath_inheritance();

	return 0;
}