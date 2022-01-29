#include<bits/stdc++.h>
#include"utils5_edit_(b).cpp"

using namespace std;

void ALGO::order_food_restaurant() {

	int r, ch, num;
	cout << "\n RESTAURANT MENU:";
	cout << "\n --------------- ";
	cout << "\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
	cout << "\n\n Enter your choice: ";
	cin >> ch;
	
	switch(ch) {
		case 1: assign_price("breakfast"); break;
		case 2: assign_price("lunch"); break;
		case 3: assign_price("dinner"); break;
		default: cout<<"\n Wrong Choice"; break;
	}

	cout << "\n\n Press any key to continue.\n";
	getchar();
	getchar();
	return;
}


void ALGO::assign_price(string check) {

	int r;
	cout << " Enter Room Number: "; cin >> r;
	int flag = check_room_status(r);

	if(flag == 0)
		cout << "\n Sorry, Room is Vacant !";
	
	else if(flag == 2)
		cout << "\n Sorry, Room does not exist !!";

	else {
		long num, pos;
		cout << " Enter number of people: ";
		cin >> num;
		fstream file("database.dat", ios::in|ios::out|ios::binary);

		while(!file.eof()) {
		
			pos = file.tellg();
			file.read((char*)this, sizeof(ALGO));

			if(room_no==r) {
				int value = check=="breakfast"? 500 : check=="lunch"? 1000 : 1200;
				pay = value*num;
				cost = cost+pay;
				file.seekg(pos);
				file.write((char*)this, sizeof(ALGO));
				cout << "\n Amount added to the bill: BDT. " << pay;
				break;
			}
		}

		file.close();
	}
}