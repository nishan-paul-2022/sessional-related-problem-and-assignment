#include<bits/stdc++.h>
#include"utils1_hotel.cpp"

using namespace std;


void ALGO::cost_analysis() {

	if(room_no >= 1 && room_no <= 50) {
		strcpy(rtype, "Deluxe");  // STRING MANIPULATION
		cost =  days*10000;
	}

	if(room_no >= 51 && room_no <= 80) {
		strcpy(rtype, "Executive");  // STRING MANIPULATION
		cost = days*12500;
	}

	if(room_no >= 81 && room_no <= 100) {
		strcpy(rtype, "Presidential");  // STRING MANIPULATION
		cost = days*15000;
	}
}


int ALGO::check_room_status(int r) {

	int flag = 0;
	ifstream fin("database.dat", ios::in|ios::binary);  // ADVANCED FILE OPERATIONS

	if(r<1 || r>100)
		flag = 2;

	while(flag==0 && fin.read((char*)this, sizeof(ALGO))) {  // POINTER

		if(room_no==r)
			flag = 1;
	}

	fin.close();
	return flag;
}


void ALGO::book_a_room() {  // ADVANCED FILE OPERATIONS
	
	int r, flag;
	ofstream fout("database.dat", ios::app|ios::binary);

	cout << "\n| Rooms  -   Room Type  |";
	cout << "\n+-----------------------+";
	cout << "\n|   1-50 -    Deluxe    |";
	cout << "\n|  51-80 -   Executive  |";
	cout << "\n| 81-100 - Presidential |";
	cout << "\n\n ENTER CUSTOMER DETAILS";

	cout << "\n\n Room Number: ";

	cin >> r;
	flag = check_room_status(r);

	if(flag == 1)
		cout << "\n Sorry, Room is already booked.\n";
	
	else if(flag == 2)
		cout << "\n Sorry, Room does not exist.\n";

	else {
		room_no = r;

		cout << " Name: "; cin >> name;
		cout << " Address: "; cin >> address;
		cout << " Phone Number: "; cin >> phone;
		cout << " Number of Days: "; cin >> days;

		cost_analysis();
	
		fout.write((char*)this, sizeof(ALGO));  // POINTER
		cout << "\n Room has been booked.";
	}

	cout << "\n Press any key to continue.\n";
	getchar();
	getchar();

	fout.close();
}