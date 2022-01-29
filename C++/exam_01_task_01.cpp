# include <bits/stdc++.h>
using namespace std;

class Name {
    public:
        string firstName;
        string lastName;

        Name(string a, string b) {
            firstName = a;
            lastName = b;
        }

        string getFullName() {
            return firstName + " " + lastName;
        }
};


class Product {
    public:
        string name;
        string category;
        double price;
        int quantity;
    
        Product() {
            name = "";
            category = "";
            price = 0;
            quantity = 0;
        }

        Product(string a, string b, double c) {
            name = a;
            category = b;
            price = c;
        }

        string getName() {return name;}
        string getCategory() {return category;}
        double getPrice() {return price;}
        int getQuantity() {return quantity;}

        void setQuantity(int a) {
            quantity = a;
        }
};


class Customer {
    public:
        string address;
        int numProduct;
        string name;
        int n;
        Product *parr;

        Customer(string a, string b, string c) {
            Name obj(a, b);
            name = obj.getFullName();
            address = c;
            numProduct = 0;
            n = 10;
            parr = new Product[n];
        }

        void buy(Product p, int i) {
            if(numProduct < n) {
                p.setQuantity(i);
                parr[numProduct++] = p;
            }
            else
                cout << "Sorry!! You already reached the maximum number of products purchased." << endl;
        }

        void print() {
            double cost = 0;

            cout << "Name : " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Number of products purchased: " << numProduct << "\n\n";

            cout << "No ";
            cout << setfill(' ') << setw(17) << "Product Name";
            cout << setfill(' ') << setw(17) << "Category";
            cout << setfill(' ') << setw(17) << "Quantity";
            cout << setfill(' ') << setw(17) << "Unit Price(RM)";
            cout << setfill(' ') << setw(17) << "Amount(RM)" << endl;

            for(int i=0; i<numProduct; i++) {
                cout << i+1 << ' ';
                cout << setfill(' ') << setw(17) << parr[i].name;
                cout << setfill(' ') << setw(17) << parr[i].category;
                cout << setfill(' ') << setw(17) << parr[i].quantity;
                cout << setfill(' ') << setw(17) << fixed << setprecision(2) << parr[i].price;
                cout << setfill(' ') << setw(17) << fixed << setprecision(2) << parr[i].quantity*parr[i].price;
                cost += parr[i].quantity*parr[i].price;
                cout << endl;
            }

            cout << "\nTotal price = RM " << cost << endl;
        }
};


int main () {

    Customer cust("Amir", "Jalil", "Masai, Johor");
    Product p1("Jacob", "Biscuit", 14.8);
    Product p2("Twister", "Drink", 7.5);
    Product p3("Ayamas", "Nugget", 18.4);
    Product p4("Oreo", "Biscuit", 3.8);

    cust.buy(p4, 5);
    cust.buy(p2, 4);
    cust.buy(p3, 2);
    cust.buy(p1, 3);
    cust.print();

    return 0;
}