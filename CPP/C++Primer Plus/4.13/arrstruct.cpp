#include<iostream>
using namespace std;

struct inflatable{
	char name[20];
	float volumn;
	double price;
};

int main()
{
	inflatable gifts[2] = {
		{"123",1.00,2.00},
		{"456",3.00,4.00}
	};
	cout << "The gifts " << gifts[0].name << " and " << gifts[1].name << " have a combined volume of " <<
		gifts[0].volumn + gifts[1].volumn << " cubic feet." << endl;
	return 0;
}