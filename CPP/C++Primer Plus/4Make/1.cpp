//#include<iostream>
//#define SIZE 30
//
//using namespace std;
//
//struct info{
//	char fname[SIZE];
//	char lname[SIZE];
//	char grade;
//	unsigned int age;
//};
//
//int main()
//{
//	info person;
//	info * pinfo = &person;
//
//	cout << "What is your first name?";
//	cin.getline(pinfo->fname, SIZE);
//	cout << "What is your last name?";
//	cin.getline(pinfo->lname,SIZE);
//	cout << "What letter grade do you deserve?";
//	cin >> pinfo->grade;
//	cout << "What is your age?";
//	cin >> pinfo->age;
//	cout << "Name:" << pinfo->lname << pinfo->fname << endl;
//	cout << "Grade:" << char(pinfo->grade + 1) << endl;
//	cout << "Age:" << pinfo->age << endl;
//	return 0;
//}