#include<iostream>

using namespace std;

int main()
{
	int quizScores[10] = {20,20,20,20,20,20,20,20,19,12};

	cout << "Doing it right!\n";
	int i;
	for (i = 0; quizScores[i] == 20; i++)
	{
		cout << "quizScores " << i << "is 20\n";
	}
	cout << "Doing it wrong!\n";
	for (i = 0; quizScores[i] = 20;i++)
		cout << "quizScores " << i << "is 20\n";
	return 0;
}