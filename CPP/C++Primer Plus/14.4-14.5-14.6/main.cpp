//14.6
#include <iostream>
#include "studenti.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student & sa,int n);

const int pupils = 3;
const int quizzes = 5;

int main(int argc,char *argv[])
{
	Student ada[pupils] = {Student(quizzes),Student(quizzes),Student(quizzes)};
	int i;
	for(i = 0;i < pupils;i++)
	{
		set(ada[i],quizzes);
	}
	cout << "\nStudent list:\n";
	for(i = 0;i < pupils;i++)
	{
		cout << ada[i].Name() << endl;
	}
	cout << "\nResult:\n";
	for(i = 0;i < pupils;i++)
	{
		cout << ada[i];
		cout << "Average:" << ada[i].Average() << endl;
	}
	cout << "Done\n";

	return 0;
}
void set(Student & sa,int n)
{
	cout << "Please enter the name of Student:";
	getline(cin,sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for(int i =0;i < n;i++)
	{
		cin >> sa[i];
	}
	while(cin.get() != '\n')
	{
		continue;
	}
}