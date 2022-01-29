#include <bits/stdc++.h>
using namespace std;

// Runtime Polymorphism [ Virtual Function ]

// without virtual Function
void example4() {
  
    class Add {
        int x = 5, y = 20;  

        public:  
            void display() {
                int ans = x + y;
                cout << "value: " << x + y << endl;  
            }  
    };

    class Substract: public Add {
        int y = 10, z = 30;

        public:
            // overridden function
            void display() {
                int ans = y + z;
                cout << "value: " << ans << endl;  
            }  
    };

    Add *m;             // base class pointer .it can only access the base class members
    Substract s;        // making object of derived class
    m = &s;  
    m->display();       // Accessing the function by using base class  pointer 
}

// with virtual Function
void example5() {

    class Add {
        public: 
            virtual void print() {
                int a = 20, b = 30;
                cout << " base class Action is:" << a+b << endl;
            }
        
            void show() {
                cout<< "show base class" << endl;
            } 
    }; 

    class Sub: public Add {
        public:
            // print() is already virtual function in derived class, we could also declared as virtual void print() explicitly
            void print() { 
                int x = 20, y = 10;
                cout<< "derived class Action: " << x+y <<endl;
            } 

            void show () {
                cout << "show derived class" << endl;
            } 
    }; 
 
    Add *aptr; 
    Sub s; 
    aptr = &s; 
    aptr->print();  // virtual function, binded at runtime (Runtime polymorphism) 
    aptr->show();   // Non-virtual function, binded at compile time 
}

// Runtime Polymorphism [ Pure virtual Function ]
void example6() {

    class Animal {  
        public:  
            virtual void show() = 0;  // Pure virtual function declaration.
    };

    class Man: public Animal {
        public:  
            void show() { 
                cout << "Man is the part of animal husbandry " << endl;  
            }  
    };

    Animal *aptr;   // Base class pointer 
    Man m;          // derived class object creation.
    aptr = &m;  
    aptr->show();  
}


int main(void)
{
    example4();
    example5();
    example6();

    return 0;
}