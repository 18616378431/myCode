#include<iostream>

using namespace std;

struct inflatable{
	char name[20];
	float volumn;
	double price;
};

int main()
{
	inflatable guest = {
		"qwert",
		1.88,
		29.99
	};
	inflatable pal = {
		"asdfgh",
		3.12,
		32.99
	};

	cout << "Expand your guest list with " << guest.name << " and " << pal.name << endl;
	cout << "You can have both for $ " << guest.price + pal.price << endl;
	return 0;
}