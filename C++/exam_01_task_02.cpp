//Program 1
# include <iostream>
using namespace std;

class Employee {
    public: string name, city, state, country; //
        int zipCode;

    public:
        Employee (string name) {
            this->name = name; // 
        }

        void setAddress(string, string, string, int); //
        friend void displayAddress(Employee e); //
        friend ostream& operator<<(ostream&, Employee&); //
};

void Employee::setAddress (string cy, string st, string co, int zip) {
    city = cy;
    state = st;
    country = co;
    zipCode = zip;
}

void displayAddress(Employee e) { //
    cout << "City: " << e.city
    << "\nState: " << e.state
    << "\nCountry: " << e.country
    << "\nZip code: " << e.zipCode;
}

ostream& operator << (ostream& strm, Employee& e) { //
    cout << "Name: " << e.name << endl;
    displayAddress(e); //
    return strm; //
}

int main() {
    Employee emp("John"); //
    emp.setAddress("Johor Bahru", "Johor", "Malaysia", 81300);
    cout << "Employee info: \n--------\n" << emp << endl;
    return 0;
}

// 6 / public: string name, city, state, country;
// 11 / this->name = name;
// 14 / void setAddress(string, string, string, int);
// 15 / friend void displayAddress(Employee e);
// 16 / friend ostream& operator<<(ostream&, Employee&);
// 26 / void displayAddress(Employee e) {
// 33 / ostream& operator << (ostream& strm, Employee& e) {
// 35 / displayAddress(e);
// 36 / return strm;
// 40 / Employee emp("John");