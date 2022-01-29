// question 01 [ii]
#include <bits/stdc++.h>
#define spc ' '
using namespace std;


class Teacher {

    public:
        string name;

        Teacher(string name) {
            this->name = name;
        }

        string getName() {    
            return this->name;    
        }    
};


class Department {

    public:
        vector<Teacher> v;

        void add(Teacher *t) {    
            v.push_back(*t);    
        }

        friend ostream& operator<<(ostream& os, const Department dt);
};


ostream& operator<<(ostream& os, const Department dt) {

    vector<Teacher> v = dt.v;
    cout << "Software Eng Department:" << spc;

    for(int i = 0; i < v.size(); i++) {
        cout << v[i].name << spc;
    }

    cout << endl;
    return os;
}


int main()
{
    // Create a teacher outside the scope of the Department
    Teacher *t1 = new Teacher("Ali"); // create a teacher
    Teacher *t2 = new Teacher("Abu");
    Teacher *t3 = new Teacher("Alyssa");

    {
    // Create a department and use the constructor parameter to pass the teacher to it.
        Department dept; // create an empty Department
        dept.add(t1);
        dept.add(t2);
        dept.add(t3);
        cout << dept;

    } // dept goes out of scope here and is destroyed

    cout << t1->getName() << " still exists!\n";
    cout << t2->getName() << " still exists!\n";
    cout << t3->getName() << " still exists!\n";

    delete t1;
    delete t2;
    delete t3;

    return 0;
}