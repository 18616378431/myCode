#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

const int SIZE = 100;

typedef struct gp{
	string name;
	double money;
}GP;

void show(GP *p,int n);

int main()
{
	ifstream inFile;
	inFile.open("9.txt");
	if(!inFile.is_open())
	{
		cout << "Open file error!" << endl;
		exit(EXIT_FAILURE);
	}
	int line;
	inFile >> line;

	GP *p = new GP[line];
	int i = 0;
	
	
	while(inFile.good())
	{
		//inFile >> p[i].name;
		inFile.get();
		getline(inFile,p[i].name);
		inFile >> p[i].money;
		i++;
	}
	show(p,line);
	inFile.close();
	delete []p;
	return 0;
}
void show(GP *p,int n)
{
	cout << "Grand Patrons" << endl;
	for(int i = 0;i < n;i++)
	{
		if(p[i].money >= 10000)
		{
			cout << p[i].name << " " << p[i].money << endl;
		}
	}
	cout << "Patrons" << endl;
	for(int i = 0;i < n;i++)
	{
		if(p[i].money < 10000)
		{
			cout << p[i].name << " " << p[i].money << endl;
		}
	}
}