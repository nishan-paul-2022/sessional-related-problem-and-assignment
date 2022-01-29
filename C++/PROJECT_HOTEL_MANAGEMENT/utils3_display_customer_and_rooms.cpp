#include<bits/stdc++.h>
#include"utils2_book_a_room.cpp"

using namespace std;


class TVA {

    public:

        void display(int room_no, char name[], char address[], char phone[], long days, char rtype[], long cost) {

			cout << "\n Customer Details";
			cout << "\n ---------------- \n";
			cout << "\n Room Number: " << room_no;
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Phone Number: " << phone;
			cout << "\n Staying for " << days << " days.";
			cout << "\n Room Type: " << rtype;
			cout << "\n Total cost of stay: \n" << cost;
        }
};


void ALGO::display_customer_information() {

	ifstream fin("database.dat", ios::in|ios::binary);  // ADVANCED FILE OPERATIONS
	int r, flag = 0;
	cout << "\n Enter Room Number: ";
	cin >> r;

	while(fin.read((char*)this, sizeof(ALGO))) {  // POINTER

		if(room_no == r) {
			TVA mmad;  // AGGREGATION AND COMPOSITION
			mmad.display(room_no, name, address, phone, days, rtype, cost);
			flag = 1;
			break;
		}
	}

	if(flag == 0)
		cout<<"\n Room is Vacant !!!";

	cout << "\n Press any key to continue.\n";
	getchar();
	getchar();
	fin.close();
}


void ALGO::display_alloted_rooms() {

	const char separator=' ';
	const int NoWidth=8;
	const int GuestWidth=17;
	const int AddressWidth=16;
	const int RoomWidth=13;
	const int ContactNoWidth=13;

	ifstream fin("database.dat", ios::in|ios::binary);  // ADVANCED FILE OPERATIONS
	cout << "\nLIST OF ROOMS ALLOTED";
	cout << "\n Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";

	while(fin.read((char*)this, sizeof(ALGO))) { // POINTER
		cout << "\n" << setw(NoWidth) << setfill(separator) << room_no << " |";
		cout << setw(GuestWidth) << setfill(separator) << name << " |";
		cout << setw(AddressWidth) << setfill(separator) << address << " |";
		cout << setw(RoomWidth) << setfill(separator) << rtype << " |";
		cout << setw(ContactNoWidth) << setfill(separator) << phone << " |";
	}

	cout << "\n Press any key to continue.\n";
	getchar();
	getchar();
	fin.close();
}