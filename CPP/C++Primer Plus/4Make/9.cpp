#include<iostream>
#include<string>

using namespace std;

struct CandyBar{
	string kind;
	float weight;
	int kaluli;
};

int main()
{
	/*CandyBar snack[3] = { 
		{ "Mocha Munch", 2.3, 350 },
		{ "Hello Munch", 2.4, 360 },
		{ "Kity Munch", 2.5, 370 }
	};*/
	CandyBar * pc = new CandyBar[3];
	pc[0] = { "Mocha Munch", 2.3, 350 };
	pc[1] = { "Hello Munch", 2.4, 360 };
	pc[2] = { "Kity Munch", 2.5, 370 };
	for (int i = 0; i < 3; i++)
	{
		cout << "Kind:" << pc[i].kind << " Weight:" << pc[i].weight << " Kaluli:" << pc[i].kaluli << endl;
	}
	return 0;
}