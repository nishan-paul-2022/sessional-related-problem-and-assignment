// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// SBT1: Topic 2 to 4 (Intro to Class, Cons. destruc., & COM)

#include <iostream>
using namespace std;

class Point
{
  private:
	double x, y; // attributes are pre-declared / given

  public:
	// define at least one constrcutor
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

	// define necessary mutators and accessors
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(int value) { x = value; }
	void setY(int value) { y = value; }

	// define two operators (+) and (/) for the class
	// + to be used for operation like: point1 = point2 + point3
	// / to be used for division of a point by a real value, eg..   point1 = point2 / 5.0

	Point operator+(Point right)
	{
		return Point(x + right.x, y + right.y);
	}

	Point operator/(double right)
	{
		return Point(x / right, y / right);
	}

	// You may add other methods if necessary.
};

// You may also add other functions if necessary.

// Your program must use an array to hold a list of points
// must use the operator + and / to determine the middle point

int main()
{
	Point points[10];
	Point middle;
	int numberOfPoints; // number of points

	cout << "How many points you want to enter => ";
	cin >> numberOfPoints;
	cout << endl;

	for (int i = 0; i < numberOfPoints; i++)
	{
		double x, y;

		cout << "Enter the coordinates (x and y) => ";
		cin >> x >> y;
		points[i].setX(x);
		points[i].setY(y);

		middle = middle + points[i];
	}
	middle = middle / numberOfPoints;

	cout << endl;
	cout << "Point\t\tx\ty " << endl;

	for (int i = 0; i < numberOfPoints; i++)
		cout << (i+1) << "\t\t" << points[i].getX() << "\t" << points[i].getY() << endl;

	cout << endl;
	cout << "Middle Point\t" << middle.getX() << "\t" << middle.getY() << endl << endl;

	system("pause"); // remove this line if you are using Dev C++

	return 0;
}
