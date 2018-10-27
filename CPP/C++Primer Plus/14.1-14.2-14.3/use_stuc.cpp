//14.3 use composite class
#include <iostream>
#include "studentc.h"

void set(Student & s,int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = {Student(quizzes),Student(quizzes),Student(quizzes)};
	int i;

	for(i = 0;i < pupils;i++)
	{
		set(ada[i],quizzes);
	}
	std::cout << "\nStudent List:\n";
	for(i = 0;i < pupils;i++)
	{
		std::cout << ada[i].Name() << std::endl;
	}
	std::cout << "\nResult:\n";
	for(i = 0;i < pupils;i++)
	{
		std::cout << std::endl << ada[i];
		std::cout << "Average:" << ada[i].Average() << std::endl;
	}
	std::cout << "Done\n";

	return 0;
}
void set(Student & s,int n)
{
	std::cout << "Please enter the student's name:";
	getline(std::cin,s);
	std::cout << "Please enter " << n << " quiz scores:\n";
	for(int i = 0;i < n;i++)
	{
		std::cin >> s[i];
	}
	while(std::cin.get() != '\n')
	{
		continue;
	}
}