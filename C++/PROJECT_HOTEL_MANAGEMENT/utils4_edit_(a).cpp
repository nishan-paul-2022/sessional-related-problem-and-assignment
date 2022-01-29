#include<bits/stdc++.h>
#include"utils3_display_customer_and_rooms.cpp"

using namespace std;


void ALGO::edit_customer_information() {

	int choice, r;
	cout << "\n EDIT MENU";
	cout << "\n ---------";
	cout << "\n 1. Modify Customer Information.";
	cout << "\n 2. Customer Check Out.";
	cout << "\n Enter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:	modify_customer_information(); break;
		case 2:	delete_customer_record(); break;
		default: cout<<"\n Wrong Choice."; break;
	}

	cout<<"\n Press any key to continue.\n";
	getchar();
	getchar();
}


void ALGO::modify_customer_information() {

	cout << "\n MODIFY MENU";
	cout << "\n -----------";
	cout << "\n 1. Modify Name";
	cout << "\n 2. Modify Address";
	cout << "\n 3. Modify Phone Number";
	cout << "\n 4. Modify Number of Days of Stay";

	int check, flag, r;
	cout << "\n Enter Your Choice: "; cin >> check;

	if(check<1 || check>4)
		cout<<"\n Wrong Choice";

	else {
		cout << "\n Enter Room Number: "; cin >> r;
		flag = check_room_status(r);

		if(flag==0)
			cout<<"\n Sorry, Room is vacant !";

		else if(flag == 2)
			cout << "\n Sorry, Room does not exist !!";

		else
			modify(check, r);
	}
}
