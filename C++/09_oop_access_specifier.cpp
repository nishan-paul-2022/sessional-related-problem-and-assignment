#include<bits/stdc++.h>
using namespace std;

class MyClass {

    public:
        int i;

        void set_value(int value) {
            length = value;
        }

        void show_value() {
            cout << length << endl;
            cout << name << endl;
        }

        MyClass() {
            name = 'access specifier';
        }

    private:
        int length;

    protected:
        string name;
};


int main()
{
    MyClass myObj;

    myObj.i = 25;  // allowed (public)
    cout << myObj.i << endl;

    myObj.set_value(100);
    myObj.show_value();

    return 0;
}
