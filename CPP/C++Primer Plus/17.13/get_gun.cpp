//17.13 cin get() getline() ignore()
#include <iostream>

const int Limit = 255;

int main()
{
	using namespace std;

	char input[Limit];

	cout << "Enter a string for getline() preocssing:\n";
	cin.getline(input,Limit,'#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase1\n";

	char ch;
	cin.get(ch);
	cout << "The next input char is " << ch << endl;

	if(ch != '\n')
		cin.ignore(Limit,'\n');//discard rest of line

	cout << "Enter a string for get() processing:\n";
	cin.get(input,Limit,'#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase2\n";

	cin.get(ch);
	cout << "The next input char is " << ch << endl;

	return 0;
}