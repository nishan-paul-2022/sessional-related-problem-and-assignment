/*Software Eng Department: Ali Abu Alyssa
Ali still exists!
Abu still exists!
Alyssa still exists!*/

// Program 1
#include <iostream>
using namespace std;
// Update Program 1 here.

class Teacher {
	private:
		string name;
	public:
		Teacher(string n) {
			name=n;
		}
		string getName() {
			return name;
		}
};

class Department{
	Teacher *teacher;
	string na[3];
	int n=0;
	public:
		Department(){
		}
		void add(Teacher *tt){
			teacher=tt;
			na[n]=teacher->getName();
			n++;
		}
		~Department(){
			cout<<"Sftware ENG: ";
			for(int i=0;i<3;i++){
				cout<<na[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
// Create a teacher outside the scope of the Department
	Teacher *t1 = new Teacher("Ali "); // create a teacher
	Teacher *t2 = new Teacher("Abu");
	Teacher *t3 = new Teacher("Alyssa");
	
	{
		// Create a department and use the constructor parameter
		//to pass the teacher to it.
		Department dept; // create an empty Department
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);
	//	cout << dept;
	} // dept goes out of scope here and is destroyed
	
	cout << t1->getName() << " still exists!\n";
	cout << t2->getName() << " still exists!\n";
	cout << t3->getName() << " still exists!\n";
	delete t1;
	t1=0;
	delete t2;
	t2=0;
	delete t3;
	t3=0;
	return 0;
}