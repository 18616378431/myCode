#include<iostream>
using namespace std;

struct inflatable{
	char name[20];
	float volumn;
	double price;
};

int main()
{
	inflatable bb = {
		"sun",
		0.20,
		12.49
	};
	inflatable choice;

	cout << "bb:" << bb.name << " for $ " << bb.price << endl;
	choice = bb;
	cout << "choice:" << choice.name << " for $ " << choice.price << endl;
	return 0;
}