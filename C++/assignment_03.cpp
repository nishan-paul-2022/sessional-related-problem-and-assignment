#include <bits/stdc++.h>
using namespace std;

class Course {
    public:
        string cname;
        int ccode;
        Course() {}
        Course(string value1, int value2) {
            cname = value1;
            ccode = value2;
        }
};

class Student {
    public:
        string name;
        int age;
        string address;
        double cgpa;
        string id;
        Course course[6];
        int cnt;

        Student() { cnt = 0; }

        void addCourse(Course value) {
            if((cgpa < 2.5 && cnt < 4) or (cgpa >= 2.5 && cnt < 6))
                course[cnt++] = value;
            else
                cout << "sorry, you cant\n" << endl;
        }

        void printCourses() {
            for(int i=0; i<cnt; i++) {
                cout << "name: " << course[i].cname << " | " << "course code: " << course[i].ccode << endl;
            }
            cout << endl;
        }

        void printInfo() {
            cout << "name: " << name << endl;
            cout << "age: " << age << endl;
            cout << "address: " << address << endl;
            cout << "cgpa: " << cgpa << endl;
            cout << "id: " << id << endl;

            printCourses();
        }
};

class PermanentFaculty {
    public:
        string name;
        int age;
        string address;
        Course course[7];
        int cnt;

        PermanentFaculty() { cnt = 0; }

        void addCourse(Course value) {
            if(cnt < 7)
                course[cnt++] = value;
            else
                cout << "sorry, you cant\n" << endl;
        }

        void printCourses() {
            for(int i=0; i<cnt; i++) {
                cout << "name: " << course[i].cname << " | " << "course code: " << course[i].ccode << endl;
            }
            cout << endl;
        }

        void printInfo() {
            cout << "name: " << name << endl;
            cout << "age: " << age << endl;
            cout << "address: " << address << endl;
            cout << "numberOfCourses: " << cnt << endl;
            cout << "salary: " << getSalary() << endl;

            printCourses();
        }

        int getSalary() {
            int value = cnt>4? 10000 + (cnt-4)*2000 : 10000;
            return value;
        }
};

class VisitorFaculty {
    public:
        string name;
        int age;
        string address;
        Course course[3];
        int cnt;

        VisitorFaculty() { cnt = 0; }

        void addCourse(Course value) {
            if(cnt < 3)
                course[cnt++] = value;
            else
                cout << "sorry, you cant\n" << endl;
        }

        void printCourses() {
            for(int i=0; i<cnt; i++) {
                cout << "name: " << course[i].cname << " | " << "course code: " << course[i].ccode << endl;
            }
            cout << endl;
        }

        void printInfo() {
            cout << "name: " << name << endl;
            cout << "age: " << age << endl;
            cout << "address: " << address << endl;
            cout << "numberOfCourses: " << cnt << endl;
            cout << "salary: " << getSalary() << endl;

            printCourses();
        }

        int getSalary() {
            int value = cnt==3? 6000 : 4000;
            return value;
        }
};

void example() {
    Student s;

    s.name = "jimmy page";
    s.age = 23;
    s.address = "mirpur, dhaka-1216";
    s.cgpa = 3.1;
    s.id = "16112839234";

    s.addCourse(Course("Programming Language 2", 215));
    s.addCourse(Course("Programming Language 1", 115));
    s.addCourse(Course("Data Structures and Algorithms", 225));
    s.addCourse(Course("Microprocessors", 331));
    s.addCourse(Course("Database Management", 311));

    s.printInfo(); cout << "student info(s) : first call\n" << endl;

    s.addCourse(Course("Operating Systems", 323));
    s.addCourse(Course("Machine Learning", 411));

    s.printInfo(); cout << "student info(s) : second call\n" << endl;
}

void example2() {
    Student t;

    t.name = "dimebag";
    t.age = 24;
    t.address = "Dhanmondi, Dhaka-1216";
    t.cgpa = 2.4;
    t.id = "1712184642";

    t.addCourse(Course("Programming Language 2", 215));
    t.addCourse(Course("Programming Language 1", 115));
    t.addCourse(Course("Data Structures and Algorithms", 225));
    t.addCourse(Course("Microprocessors", 331));

    t.printInfo(); cout << "student info(t) : first call\n" << endl;
}

void example3() {
    PermanentFaculty p;

    p.name = "slash";
    p.age = 30;
    p.address = "Mirpur";

    p.addCourse(Course("Programming Language 2", 215));
    p.addCourse(Course("Programming Language 1", 115));
    p.addCourse(Course("Data Structures and Algorithms", 225));
    p.addCourse(Course("Microprocessors", 331));

    p.printInfo(); cout << "permanent teacher info(p) : first call\n" << endl;
}

void example4() {
    VisitorFaculty v;

    v.name = "ozzy";
    v.age = 28;
    v.address = "RA";

    v.addCourse(Course("Microprocessors", 331));
    v.addCourse(Course("Database Management", 311));
    v.addCourse(Course("Programming Language 2", 215));

    v.printInfo(); cout << "visiting teacher info(v) : first call\n" << endl;
}


int main()
{
    example();
    example2();
    example3();
    example4();

    return 0;
}