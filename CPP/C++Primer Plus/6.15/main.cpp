#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "Enter the make and model of automobile:";
	cin.getline(automobile,50);
	cout << "Enter the model year:";
	cin >> year;
	cout << "Enter the original asking price:";
	cin >> a_price;
	d_price = a_price * 0.913;

	//display information on screen with cout
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model:" << automobile << endl;
	cout << "Year:" << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	//do exact using ourFile instead of cout
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model:" << automobile << endl;
	outFile << "Year:" << year << endl;
	outFile << "Was aking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	outFile.close();
	return 0;
}