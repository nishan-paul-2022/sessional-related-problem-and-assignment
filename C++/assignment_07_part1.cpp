#include <iostream>
#include<string.h>

using namespace std;


class University {

    public:
        int uni_id;
        string name, country,city, state;

        University() {}
        
        University(int uni_id, string name, string country, string city, string state) { 
            this->uni_id = uni_id;
            this->name=name;
            this->country=country;
            this->city = city;
            this->state =state;
        }
};


class Student {
    private:
        University *university;

    public:
        string name;

        Student(string name, University *university) {
            this->name = name;
            this->university = university;
        }

        void display() {
            cout<< name<< " "<< " "<< "  " <<university->uni_id<<" "<<university->name<<
            "  "<<university-> country<<" " <<university->city<< " "<<university->state<<endl;
        }
};


int main(void) 
{
    University uni1 =University( 43600,"UKM","Malaysia","Bangi","Selangor");
    University uni2 =University( 54100,"UTM","Malaysia","Wilayah","Kuala Lampur");
    University uni3 =University( 3080,"UUM","Malaysia","Bukit Kayu Hitam","Kedah");

    Student s1 =Student("aLI",&uni1);
    Student s2 =Student("Saeed",&uni2);
    Student s3 =Student("Jone",&uni3);
    Student s4 =Student("Yaseen",&uni1);
    Student s5 =Student("Saleh",&uni3);
    Student s6 =Student("Victor",&uni2);
    Student s7 =Student("Rami",&uni1);

    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    s6.display();
    s7.display();

    return 0;
}