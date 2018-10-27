//13.9 使用Brass和BrassPlus类
//#include <iostream>
//#include "brass.h"
//
//int main()
//{
//	using namespace std;
//
//	Brass piggy("Porcelot Pigg",381299,4000.0);
//	BrassPlus hoggy("Horatio Hogg",382288,3000.0);
//
//	piggy.ViewAcct();
//	cout << endl;
//	hoggy.ViewAcct();
//	cout << endl;
//	cout << "Deposit $1000 into the hoggy Account:\n";
//	hoggy.Deposit(1000.00);
//	cout << "New balance:$" << hoggy.Balance() << endl;
//	cout << "WithDrawing $4200 from the piggy Account:\n";
//	piggy.Withdraw(4200.00);
//	cout << "piggy Account balance:$" << piggy.Balance() << endl;
//	cout << "WithDraw $4200 from the hoggy Account:\n";
//	hoggy.Withdraw(4200.00);
//	hoggy.ViewAcct();
//
//	return 0;
//}