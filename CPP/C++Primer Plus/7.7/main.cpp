#include<iostream>

using namespace std;

const int MAX = 5;

int fill_array(double arr[],int n);
void show_array(const double arr[],int n);
void revalue(double r,double arr[],int n);

int main()
{
	double properties[MAX];
	int size = fill_array(properties,MAX);
	double factor;

	show_array(properties,size);
	cout << "Enter revaluation factor:";
	cin >> factor;
	revalue(factor,properties,size);
	show_array(properties,size);
	cout << "Done.\n";
	return 0;
}
int fill_array(double arr[],int n)
{
	double temp;
	int i;
	for(i = 0;i < n;i++)
	{
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input;input process terminated.\n";
			break;
		}
		else if(temp < 0)
		{
			break;
		}
		arr[i] = temp;
	}
	return i;
}
void show_array(const double arr[],int n)
{
	for(int i = 0;i < n;i++)
	{
		cout << "Property #" << (i + 1) << ":$";
		cout << arr[i] << endl;
	}
}
void revalue(double r,double arr[],int n)
{
	for(int i = 0;i < n;i++)
		arr[i] *= r;
}