// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// SBT1: Topic 2 to 4 (Intro to Class, Cons. destruc., & COM)

#include <iostream>
using namespace std;

class Date
{
  private:
	int month, year;

  public:
	Date(int m = 0, int y = 0) : month(m), year(y) {}

	void setMonth(int value) { month = value; }
	void setYear(int value) { year = value; }

	bool operator>(Date right)
	{
		if (year > right.year)
			return true;
		if ((year == right.year) && (month > right.month))
			return true;
		return false;
	}

	Date operator-(Date right)
	{
		if (month < right.month)
		{
			month += 12;
			year--;
		}

		Date diff(month - right.month, year - right.year);

		return diff;
	}

	friend void printAge(Date dob);
};

void printAge(Date dob)
{
	Date today(10, 2018);
	Date diff;

	diff = today - dob;

	cout <<"DOB: " << dob.month << " " << dob.year << endl; 
	cout <<"Age: " << diff.year << " years and " << diff.month << " months old " << endl
		 << endl;
}

int main()
{
	Date date, recent;
	int nPerson;

	cout << "How many person you want to enter => ";
	cin >> nPerson;
	cout << endl;

	for (int i = 1; i <= nPerson; i++)
	{
		int m, y;

		cout << "Enter the date of birth (month and year) => ";
		cin >> m >> y;
		date.setMonth(m);
		date.setYear(y);

		if (date > recent)
			recent = date;
	}

	cout << endl;
	cout << "The youngest person" << endl;
	printAge(recent);

	system("pause"); // remove this line if you are using Dev C++

	return 0;
}
