//#include<iostream>
//
//using namespace std;
//
//void showmenu();
//void delMore();
//
//int main()
//{
//	char ch;
//	
//	showmenu();
//	while(cin.get(ch) && ch != '@')
//	{
//		switch (ch)
//		{
//		case 'c':
//			cout << "carnivore" << endl;
//			break;
//		case 'p':
//			cout << "pianist" << endl;
//			break;
//		case 't':
//			cout << "tree" << endl;
//			break;
//		case 'g':
//			cout << "game" << endl;
//			break;
//		default:
//			delMore();
//			cout << "Please enter a c,p,t or g:";
//			break;
//		}
//	}
//	return 0;
//}
//void showmenu()
//{
//	cout << "Please enter one of following choice:\n"
//		"c)carnivore\tp)pianist\n"
//		"t)tree\tg)game\n";
//}
//void delMore()
//{
//	while(cin.get() != '\n')
//		continue;
//}