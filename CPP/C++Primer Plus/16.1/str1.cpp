//16.1 string
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string one("Lottery Winner!");	//ctor #1
	cout << one << endl;	//overload <<
	
	string two(20,'$');	//ctor #2
	cout << two << endl;

	string three(one);	//ctor #3
	cout << three << endl;
	
	one += " Oops!";	//overload +=
	cout << one << endl;
	
	two = "Sorry!That was ";
	three[0] = 'P';

	string four;	//ctor #4
	four = two + three;	//overload +,=
	cout << four << endl;
	
	char alls[] = "All's well that ends well";
	string five(alls,20);	//ctor #5
	cout << five << "!\n";

	string six(alls + 6,alls + 10);	//ctor #6
	cout << six << ",";

	string seven(&five[6],&five[10]); //ctor #6
	cout << seven << "...\n";

	return 0;
}