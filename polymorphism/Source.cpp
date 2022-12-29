//Programer Name: Muhammad Danyal
// Reg No:4304/BSSE/F21/B
// In this program i apply the prienciples of polymorphisam to check wether the student or teacher is outstanding /or not. 
#include<iostream>
#include<string>
#include<typeinfo>
#include<windows.h>
#define MAX 100
using namespace std;

//for blinking text "Teacher"
void SetTextXY(int x, int y, char* buf, int timestoBlink, int delayMilliSecs) {	
	COORD ord;
	ord.X = x;
	ord.Y = y;
	int len = strlen(buf);
	char* p = new char[len + 1];
	memset(p, 32, len);
	p[len] = '\0';

	for (int i = 0; i < timestoBlink; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
		std::cout << p;
		::Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
		std::cout << buf;
		::Sleep(delayMilliSecs);
	}
}
//void gotoxy(int x, int y) {
//	COORD coord; // coordinates
//	coord.X = x; coord.Y = y; // X and Y coordinates
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
//}

class person {
protected:
	int pid;
	string name;
	int age;
	string address;
public:
	virtual void read();
	virtual void display();
	virtual void isoutstanding() = 0;
	person(int i = 0, int a = 0, string n = "n", string add = "res") :pid(i), age(a) { name = n; address = add; }
};
class student :public person {
protected:
	string prog;
	float cgpa;
public:
	void read();
	void display();
	void isoutstanding();
	student(float cg = 0.1, string p = "p",int i=0,int a=0,string n="n", string add="res") :person(i,a,n,add),cgpa(cg) { prog = p; }
};
class teacher :public person {
protected:
	string desig;
	float salary;
	int publiction;
public:
	teacher(float s = 0.1, int pub = 0, string des = "d", int i = 0, int a = 0, string n = "n", string add = "res") :person(i, a, n, add), salary(s),publiction(pub) { desig = des; }
	void read();
	void display();
	void isoutstanding();
};
void person:: read(){
	cout << "Enter person id \n";
	cin >> pid;
	cout << "Enter Name \n";
	cin.ignore(60,'\n');
	getline(cin,name);
	cout << "Enter address \n";
	getline(cin, address);
	cout << "Enter age \n";
	cin >> age;	
}
void person::display() {
	cout << "person id :"<< pid<<endl;
	cout << " Name: " << name << endl;		
	cout << "address:"<< address<<endl;	 
	cout << "age: " << age << endl;
}
void student::read() {
	person::read();
	cout << "Enter program \n";
	cin.ignore(60,'\n');
	getline(cin, prog);
	cout << "Enter CGPA \n";
	cin >> cgpa;	
}
void student::display() {
	person::display();
	cout << "program: "<<prog<<endl;
	cout << "CGPA:" << cgpa << endl;	
}
void student::isoutstanding() {
	if (cgpa >= 3.5) {
		cout << "Outstnding\n";		
	}
	cout << "-----------------------\n";
}
void teacher::read() {
	person::read();
	cout << "Enter designation \n";
	cin.ignore(60,'\n');
	getline(cin, desig);
	cout << "Enter salary \n";
	cin >> salary;
	cout << "Enter no of publication \n";
	cin >> publiction;
}
void teacher::display() {
	char buf[] = "Teacher\n\n";
	SetTextXY(15, 1, buf, 5, 1000);
	person::display();
	cout << "designation:"<<desig<<endl;
	cout << "salary:"<<salary<<endl;
	cout << "no of publication:"<<publiction<<endl;
}
void teacher::isoutstanding() {
	if (publiction >= 5) {
		cout << "Outstanding\n";		
	}
	cout << "-----------------------\n";
}

int main() {
	int choice,s=0,t=0,n=0;
	char q;
	person* p[MAX];	
	do {		
		cout << "\t\t\t\t\t\t_____MAIN MENU______" << endl;
		cout << "\t\t\t\t\t\t 1.Create student" << endl;
		cout << "\t\t\t\t\t\t 2.create teacher" << endl;
		cout << "\t\t\t\t\t\t 3.display all" << endl;			
		cout << "\t\t\t\t\t\t 4.No of teacher and student" << endl;
		cout << "\t\t\t\t\t\t 5.Exit" << endl;
		cout << "\t\t\t\t\t\tWhat you want to do? \n";
		//gotoxy(50, 0);
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "--------------Create student------------- \n";		
			do {
				p[n] = new student;
				p[n++]->read();
				cout << "Do you want to create another(y/n)\n ";
				cin >> q;
			} while (q == 'y');
			break;
		case 2:
			system("cls");
			cout << "--------------Create teacher------------- \n";		
			do{
				p[n] = new teacher;
				p[n++]->read();	
				cout << "Do you want to create another(y/n)\n ";
				cin >> q;
		} while (q == 'y');
			break;
		case 3:
			system("cls");
			cout << "--------------Display All------------- \n";
			for (int i = 0; i < n; i++) {
				p[i]->display();
				p[i]->isoutstanding();
			}			
			break;		
		case 4:
			system("cls");
			cout << "--------------No of teacher and student---------\n";
			for (int i = 0; i < n; i++) {
				if (typeid(*p[i]) == typeid(student))
					s++;
				else
					t++;
			}
			cout << "number of students are : " << s << "\n";
			cout << "number of teacher are : " << t << "\n";
			break;		
		case 5:
			exit(0);			
		default:
			cout << "Enter a valid input.\n";
			break;
		}		
	} while (true);	
}