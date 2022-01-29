#include <bits/stdc++.h>
using namespace std;

/* local variable is same as a member's name */
void example() {

    class Test {
        private:
            int x;

        public:
            void setX(int x) {
                this->x = x;  // The 'this' pointer is used to retrieve the object's x hidden by the local variable 'x'
            }

            void print() { 
                cout << "x = " << x << endl;
            }
    };

    Test obj;
    int x = 20;

    obj.setX(x);
    obj.print();
}

void example2() {

    class Test {
        private:
            int x;
            int y;

        public:
            Test(int x = 0, int y = 0) {
                this->x = x;
                this->y = y;
            }

            Test& setX(int a) { 
                x = a; 
                return *this; 
            }

            Test& setY(int b) {
                y = b;
                return *this; 
            }

            void print() {
                cout << "x = " << x << " y = " << y << endl;
            }
    };

    Test obj1(5, 5);
    obj1.print();

    // Chained function calls. All calls modify the same object as the same object is returned by reference
    // obj1.setX(10);
    // obj1.setY(20);
    obj1.setX(10).setY(20);

    obj1.print();
}

void example3() {

    class Test {

        private:
            int x;
            int y;

        public:
            Test(int x = 0, int y = 0) {
                this->x = x;
                this->y = y;
            }

            void setX(int a) { x = a; }
            void setY(int b) { y = b; }

            void destroy() { delete this; }

            void print() {
                cout << "x = " << x << " y = " << y << endl;
            }
    };

    Test obj;
    obj.destroy();
    obj.print();
}

int main()
{
    example();
    example2();
    example3();

    return 0;
}