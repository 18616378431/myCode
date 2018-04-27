////5.
//#include<iostream>
//#include<cctype>
//#include"Stack.h"
//
//int main()
//{
//	using namespace std;
//
//	Stack st;
//	char ch;
//	Item tmp;
//
//	cout << "Please enter A to add a purchase order,\n"
//		<< "P to process a PO,or Q to quit.\n";
//	while(cin >> ch && toupper(ch) != 'Q')
//	{
//		while(cin.get() != '\n')
//			continue;
//		if(!isalpha(ch))
//		{
//			cout << '\a';
//			continue;
//		}
//		switch(ch)
//		{
//		case 'A':
//		case 'a':
//			cout << "Enter fullname:";
//			cin >> tmp.fullname;
//			cout << "Enter payment:";
//			cin >> tmp.payment;
//			if(st.isfull())
//			{
//				cout << "Stack is already full.\n";
//			}
//			else
//			{
//				st.push(tmp);
//			}
//			break;
//		case 'P':
//		case 'p':
//			if(st.isempty())
//			{
//				cout << "Stack is already empty.\n";
//			}
//			else
//			{
//				st.pop(tmp);
//				cout << "Fullname:" << tmp.fullname
//					<< ",Payment:" << tmp.payment << " popped.\n";
//			}
//			break;
//		}
//		cout << "Please enter A to add a purchase order,\n"
//			<< "P to process a PO,or Q to quit.\n";
//	}
//	cout << "Bye.\n";
//	return 0;
//}