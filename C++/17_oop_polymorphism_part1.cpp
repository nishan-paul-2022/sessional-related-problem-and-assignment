#include <bits/stdc++.h>
using namespace std;

// Compile Time Polymorphism [ Function Overloading ]
void example() {

    class Addition {

        public:
            // Function with parameter | addition of two Integer value is performed
            void ADD(int x, int y) {
                int z = x + y;
                cout << z << endl;
            }

            // Function with same name but without parameter | concatenation is performed
            void ADD(string x, string y) {
                string z = x + y;
                cout << z << endl;
            }
    };

    Addition obj;                   // Object is created  
    obj.ADD(128, 15);               // first method is called
    obj.ADD("hello ", "world");     // second method is called
}

// Compile Time Polymorphism [ Operator Overloading ]
void example2() {

    class A {

        public:
            string x;

            A(){}

            A(string i) { x = i; }

            void operator+(A object) {
                string m = x + object.x;  
                cout << "The result of the addition of two objects is : " << m;  
            }
    };

    A a1("Welcome ");  
    A a2("back");
    a1 + a2;
}

// Runtime Polymorphism [ Function overriding ]
void example3() {

    class Animal {  
        public:  
            void function() {    
                cout << "Eating..." << endl;    
            }      
    };

    class Man: public Animal {    
        public:
            void function() {    
                cout << "Walking ..." << endl;    
            }    
    };

    Animal A;
    A.function();            // parent class object 
    Man m = Man();    
    m.Man::function();       // child class object
    m.Animal::function();
}


int main(void)
{
    example();
    example2();
    example3();

    return 0;
}