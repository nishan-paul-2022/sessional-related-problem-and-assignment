#include<bits/stdc++.h>
#include"utils4_edit_(a).cpp"

using namespace std;


void ALGO::modify(int check, int r) {

	string key = check==1? "name" : check==2? "address" : check==3? "phone number" : "days of stay";
	string caption = "\n enter new " + key + ": ";
	string caption2 = "\n customer " + key + " has been modified";

	fstream file("database.dat", ios::in|ios::out|ios::binary);  // ADVANCED FILE OPERATIONS

	while(!file.eof()) {
		long pos = file.tellg();
		file.read((char*)this, sizeof(ALGO));  // POINTER

		if(room_no==r) {

			cout << caption;
			switch(check) {
				case 1: cin >> name; break;
				case 2:	cin >> address; break;
				case 3: cin >> phone; break;
				default: cin >> days; break;
			}

			file.seekg(pos);
			file.write((char*)this, sizeof(ALGO));  // POINTER

			cout << caption2;
			break;
		}
	}

	getchar();
	getchar();
	file.close();
}


void ALGO::delete_customer_record() {

	int r, flag = 0;
	char ch;
	cout << "\n Enter Room Number: ";
	cin >> r;

	ifstream fin("database.dat", ios::in|ios::binary);  // ADVANCED FILE OPERATIONS
	ofstream fout("temp.dat", ios::out|ios::binary);  // ADVANCED FILE OPERATIONS

	while(fin.read((char*)this, sizeof(ALGO))) {  // POINTER
	
		if(room_no==r) {
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Phone Number: " << phone;
			cout << "\n Room Type: " << rtype;
			cout << "\n Your total bill is: Rs. " << cost;
			cout << "\n\n Do you want to check out this customer(y/n): ";

			cin >> ch;
			if(ch=='n')
			   fout.write((char*)this, sizeof(ALGO));  // POINTER
			else
			   cout<<"\n Customer Checked Out !";
			
			flag=1;
		}
		else
			fout.write((char*)this, sizeof(ALGO));  // POINTER
	}

	fin.close();
	fout.close();

	if(flag==0)
		cout<<"\n Sorry, Room is Vacant !";
	else {
		remove("database.dat");
		rename("temp.dat", "database.dat");
	}

	getchar();
	getchar();
}