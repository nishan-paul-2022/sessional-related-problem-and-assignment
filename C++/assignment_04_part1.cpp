// question 01 [i]
#include <bits/stdc++.h>
#define spc ' '
using namespace std;


class HOME {

    public:  
        string address, city, state;

        HOME(string address, string city, string state) {    
            this->address = address;    
            this->city = city;    
            this->state = state;    
        }    
};


class SHOLDER {

    private:  
        HOME* HOME;

    public:
        int id;
        string name;

        SHOLDER(int id, string name, HOME* HOME) {    
            this->id = id;    
            this->name = name;    
            this->HOME = HOME;    
        }

        void display() {    
            cout << id << spc << name << spc <<     
                HOME->address << spc << HOME->city << spc << 
                HOME->state << endl;    
        }    
};


int main()
{
    HOME a1= HOME("C-146, Sec-15","Noida","UP");    
    SHOLDER e1 = SHOLDER(101,"Nakul",&a1);    
    e1.display();

    return 0;
}

