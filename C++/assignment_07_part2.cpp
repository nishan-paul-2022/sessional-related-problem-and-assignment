#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class class_1 { // declare a class 

    public:

        int c1;

        void setClass1(int d1) {
            c1 = d1; // assignment
            cout<<"Number1 = "<<c1<<endl;
        }

        int getData1(){ return c1; }

};


class class_2: public class_1 { // declare a class

    public:

        int c2;

        void setClass2(int d2) {
            c2 = d2; // assignment
            cout<<"Number2 = "<<c2<<endl;
        }

        int getData2() { return c2; }

};


class class_3: public class_2 { // declare a class

    public:
        int c3;

        void setClass3(int d3) {
            c3 = d3; // assignment
            cout<<"Number3 = "<<c3<<endl;
        }

        int getData3() { return c3; }

        void display() { 
            cout<<"Number1 + Number2 + Number3 = "<<c1+c2+c3; 
        }

};

 

int main() 
{

    string answer1, answer2, answer3;

    class_3 value; // declare object for the class
    
    value.setClass1(1000);
    value.setClass2(20);
    value.setClass3(3);

    value.display(); // call the display function

    cout<<"\n\nWhat is the concept applied in Program 1? \nAnswer: ";

    getline (std::cin,answer1);

    cout<<"Which class(es) is/are the base class in Program 1? \nAnswer: ";

    getline (std::cin,answer2);

    cout<<"Which class(es) is/are the derived class in Program 1? \nAnswer: ";

    getline (std::cin,answer3);

    return 0;
}


/*

Sample of Output:

Number1 = Answer

Number2 = Answer

Number3 = Answer

Number1 + Number2 + Number3 = Answer 

What is the concept applied in Program 1?
Answer: Answer

Which class(es) is/are the base class in Program 1?
Answer: Answer

Which class(es) is/are the derived class in Program 1?
Answer: Answer

*/