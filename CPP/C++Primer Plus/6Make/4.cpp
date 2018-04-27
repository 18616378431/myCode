//#include<iostream>
//
//using namespace std;
//
//void showmenu();
//void delMore();
//void showInfo(struct bop *p,int n,int type);
//
//const int strsize = 80;
//const int ArSize = 5;
//
//struct bop{
//	char fullname[strsize];
//	char title[strsize];
//	char bopname[strsize];
//	int preference;//0 full,1 title,2bop
//};
//
//int main()
//{
//	struct bop bops[ArSize] = {
//		{"Wimp Macho","www","kkk",0},
//		{"Raki Rhodes","Junior Programmer","kkk",1},
//		{"Celia Laiter","www","MIPS",2},
//		{"Hoppy Hipman","Analyst Trainee","kkk",1},
//		{"Pat Hand","LOOPY","kkk",1}
//	};
//	char ch;
//
//	showmenu();
//	while(cin.get(ch) && ch != 'q')
//	{
//		if(ch == '\n')
//			continue;
//		switch(ch)
//		{
//		case 'a':
//			showInfo(bops,ArSize,0);
//			break;
//		case 'b':
//			showInfo(bops,ArSize,1);
//			break;
//		case 'c':
//			showInfo(bops,ArSize,2);
//			break;
//		case 'd':
//			showInfo(bops,ArSize,3);
//			break;
//		default:
//			cout << "Please enter a,b,c or d.\n";
//			break;
//		}
//		delMore();
//		cout << "Next choice:";
//	}
//	cout << "Bye" << endl;
//	return 0;
//}
//void showmenu()
//{
//	cout << "BOP report:\n"
//		"a)display by name	b)display by title\n"
//		"c)display by bopname	d)display by preference\n"
//		"q)quit" << endl;
//	cout << "Enter your choice:";
//}
//void delMore()
//{
//	while(cin.get() != '\n')
//		continue;
//}
//void showInfo(struct bop *p,int n,int type)
//{
//	for(int i = 0;i < n;i++)
//	{
//		if(type == 0)
//			cout << p[i].fullname << endl;
//		else if(type == 1)
//			cout << p[i].title << endl;
//		else if(type == 2)
//			cout << p[i].bopname << endl;	
//		else if(type == 3)
//		{
//			switch(p[i].preference)
//			{
//			case 0:
//				cout << p[i].fullname << endl;
//				break;
//			case 1:
//				cout << p[i].title << endl;
//				break;
//			case 2:
//				cout << p[i].bopname << endl;
//				break;
//			default:
//				cout << "Error!" << endl;
//				break;
//			}
//		}
//	}
//}
