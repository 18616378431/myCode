////3.
//#include <iostream>
//#include "workermi.h"
//#include "QueueTp.h"
//
//const int SIZE = 10;
//
//int main()
//{
//	using namespace std;
//
//	QueueTp<Worker *> lolas(SIZE);
//	int ct;
//
//	for(ct = 0;ct < SIZE;ct++)
//	{
//		char choice;
//		cout << "Enter the employee category:\n"
//			<< "w:waiter s:singer\n"
//			<< "t:singingwaiter q:quit\n";
//		cin >> choice;
//		while(strchr("wstq",choice) == NULL)
//		{
//			cout << "Please enter a w,s,t or q:";
//			cin >> choice;
//		}
//		if(choice == 'q')
//			break;
//		switch(choice)
//		{
//		case 'w':
//			lolas.Push(new Waiter);
//			break;
//		case 's':
//			lolas.Push(new Singer);
//			break;
//		case 't':
//			lolas.Push(new SingingWaiter);
//			break;
//		}
//		cin.get();//eat the last \n
//		lolas.rear()->Set();
//	}
//	cout << "\nHere is your Staff:\n";
//	int i;
//	for(i = 0;i < ct;i++)
//	{
//		cout << endl;
//		lolas.front()->Show();
//		if(lolas.Push(lolas.front()) != false)
//			lolas.Pop();
//	}
//	for(i = 0;i < ct;i++)
//	{
//		delete lolas.front();
//		lolas.Pop();
//	}
//		
//
//	cout << "Bye\n";
//
//	return 0;
//}