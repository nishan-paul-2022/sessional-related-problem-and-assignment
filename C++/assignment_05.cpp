// question 02 [iii]
#include <bits/stdc++.h>
using namespace std;


class Exam {

    private:
        int year;

    public:
        Exam() {
            cout << "Great" << endl;
        }

        ~Exam() {
            cout << "Positive" << endl;
        }

        void setTheory(double t) {
            theory = t;
        }

        void setPractical(double p) {
            practical = p;
        }

        void display(int y) {
            cout << "This is Exam : " << y << endl;
        }

    protected:
        double theory;
        double practical;
};


class Final: public Exam {

    private: 
        char Ef;

    public:
        Final () {
            cout << "Pray" << endl;
        }

        ~Final() {
            cout << "Success" << endl;
        }

        double getFinal() {
            return (theory + practical);
        }

        void myCode(char f) {
            Ef = f;
            cout << "Exam code:" << Ef << endl;
        }
};


class License: protected Exam {

    private:
        string message="Drive";

    public:
        void print(string m) {
            cout << message;
            cout << m;
        }

    protected :
        int date, month, year;
};


int main(void)
{
    Exam Eyear;
    Final F18;

    Eyear.display(2018);
    F18.setTheory(40.5);
    F18.setPractical(25.5);

    cout << "Sum: " << F18.getFinal() << endl;

    F18.myCode('F');

    return 0;
}


// Great
// Great
// Pray
// This is Exam : 2018
// Sum: 66
// Exam code:F
// Success
// Positive
// Positive
