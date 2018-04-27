//14.14 template class
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

int main()
{
	using namespace std;

	Stack<string> st;//create an empty stack
	char ch;
	string po;

	cout << "please enter A to add a purchase order.\n"
		<< "P to process a PO,or Q to quit.\n";
	while(cin >> ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
		case 'a':
		case 'A':
			cout << "Enter a PO number to add:";
			cin >> po;
			if(st.isfull())
				cout << "Stack is already full\n";
			else
				st.push(po);
			break;
		case 'p':
		case 'P':
			if(st.isempty())
				cout << "Stack is empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << "popped\n";
			}
			break;
		}
		cout << "please enter A to add a purchase order.\n"
			<< "P to process a PO,or Q to quit.\n";
	}
	cout << "Bye.\n";

	return 0;
}