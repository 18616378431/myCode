//17.14 peek() read() gcount() putback()
#include <iostream>
#include <cstdlib>

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	//read and echo input up to a # character
	char ch;

	while(cin.get(ch))//terminate on EOF
	{
		if(ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);//reinsert character
			break;
		}
	}

	if(!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		std::exit(0);
	}

	while(cin.peek() != '#')//look ahead
	{
		cin.get(ch);
		cout << ch;
	}

	if(!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
		cout << "End of file reached.\n";

	return 0;
}