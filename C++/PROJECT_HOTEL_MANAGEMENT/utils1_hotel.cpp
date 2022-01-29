#include<bits/stdc++.h>

using namespace std;


class PRIMARY {
	public:
		int room_no;
		char name[30];
		char address[50];
		char phone[15];
		long days;
		long cost;
		char rtype[30];
		long pay;
};


class ALGO : public PRIMARY  // OOP : INHERITANCE
{
	public:
		void display_main_menu();

		void cost_analysis();
		int  check_room_status(int);
		void book_a_room();

		void display_customer_information();
		void display_alloted_rooms();

		void edit_customer_information();
		void modify_customer_information();
		void modify(int, int);
		void delete_customer_record();

		void order_food_restaurant();
		void assign_price(string);

		ALGO() {
			cout << "\n\t\t\t\t **WELCOME**";
			cout << "\n******************************************************************************\n\n\n";
		}

		~ALGO() {
			cout << "\n\n\n******************************************************************************";
			cout << "\n\t\t\t\t **GOOD BYE**\n\n\n";
		}
};


void ALGO::display_main_menu() {

	int choice;

	while(choice !=  6) {
		cout << "--- MAIN MENU ---" << endl;
		cout << "1. Book A Room" << endl;
		cout << "2. Customer Information" << endl;
		cout << "3. Rooms Allotted" << endl;
		cout << "4. Edit Customer Details" << endl;
		cout << "5. Order Food from Restaurant" << endl;
		cout << "6. Exit" << endl;

		cout << "Enter Your Choice: "; cin >> choice;
	
		switch(choice) {
			case 1:	book_a_room(); break;
			case 2: display_customer_information(); break;
			case 3: display_alloted_rooms(); break;
			case 4:	edit_customer_information(); break;
			case 5: order_food_restaurant(); break;
			case 6: return;

			default: {
				cout << "\nWrong choice.";
				cout << "\nPress any key to continue.\n";
				getchar();
				getchar();
			}
		}
	}
}
