#include<iostream>
#include<string>//string对象

#include<cstring>//使用c函数strcmp

using namespace std;

typedef struct car{
	string make;
	int year;
}CAR;

int main(void)
{
	//1.
	/*int x,y,sum = 0;

	cout << "Please typein two integer:" << endl;
	cin >> x;
	cin >> y;

	if(x > y)
	{
		cout << "must x < y!" << endl;
		return 0;
	}

	for(;x <= y;x++)
	{
		sum += x;
	}
	cout << "sum = " << sum << endl;*/

	//2.
	/*int i,sum = 0;

	cout << "Please input a integer:" << endl;
	cin >> i;

	while(i != 0)
	{
		sum += i;
		cout << "Sum = " << sum << endl;
		cin >> i;
	}*/

	//3.
	/*int year = 0;
	float da = 0.10;
	float daOrignMoney = 100;
	float daSumMoney = 100;
	
	
	float cl = 0.05;
	float clOrignMoney = 100;
	
	do
	{
		year++;
		daSumMoney += daOrignMoney * da;
		clOrignMoney += clOrignMoney*cl;
	}while(daSumMoney > clOrignMoney);
	cout << "year " << year << endl;
	cout << "da has " << daSumMoney << endl;
	cout << "cl has " << clOrignMoney << endl;*/

	//4. 5.
	/*int i = 0,sum = 0,year = 0,yearSum = 0;
	char * months[12] = {
		"Juanary:",
		"February:",
		"March:",
		"April:",
		"May:",
		"June:",
		"July:",
		"August:",
		"Septemper:",
		"October:",
		"November:",
		"December:"
	};
	int sales[3][12];
	
	while(year < 3)
	{
		while(i < 12)
		{
			cout << months[i];
			cin >> sales[year][i];
			sum += sales[year][i];
			i++;
		}
		cout << "All sales is " << sum << endl;
		yearSum += sum;
		sum = 0;
		i = 0;
		year++;
	}
	cout << "Three years all sales is " << yearSum << endl;*/

	//6.
	/*int carNum;

	cout << "How many cars do you wish to catalog?";
	cin >> carNum;

	CAR *new_car = new CAR[carNum];
	
	for(int i = 0;i < carNum;i++)
	{
		cout << "car #" << (i+1) << ":" << endl;
		cout << "Please enter the make:";
		cin.sync();
		getline(cin,new_car[i].make);
		cout << "Please enter the year made:";
		cin >> new_car[i].year;
	}
	cout << "Here is your collection:" << endl;
	for(int j = 0;j < carNum;j++)
	{
		cout << new_car[j].year << "\t" << new_car[j].make << endl;
	}
	delete [] new_car;*/

	//7.
	/*char ch[10] = "0";
	int count = 0;

	cout << "Enter words (to stop,type the word done)" << endl;
	cin >> ch;
	while(strcmp(ch,"done") != 0)
	{
		count++;
		cin >> ch;
	}
	cout << "You enter a total of " << count << " words." << endl;*/
	
	//8.
	/*string word = "0";
	int count = 0;

	cout << "Enter words (to stop,type the word done)" << endl;
	cin >> word;
	
	while(word != "done")
	{
		count++;
		cin >> word;
	}
	cout << "You enter a total of " << count << " words." << endl;*/

	//9.
	
	int rows;

	cout << "Enter a number of rows:";
	cin >> rows;

	for(int i = 1;i <= rows;i++)
	{
		for(int j = 1;j <= rows - i;j++)
		{
			cout << ".";
		}
		for(int k = 1;k <= i;k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}