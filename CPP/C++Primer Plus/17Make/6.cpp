//6. employee character 14 program pratice 5 class
//line 507
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include "emp.h"
//
//using namespace std;
//
//const char * file = "17-6Make.txt";
//
//const int MAX = 10;
//
//int main()
//{
//	//17.18
//	char ch;
//	abstr_emp *pc[MAX],*tmp;
//	int classtype,i,ct;
//
//	//show initial contents
//	ifstream fin(file,ios_base::in);
//
//	if(fin.is_open())
//	{
//		cout << "Here are the current contents of the "
//			<< file << " file:\n";
//		
//		while((fin >> classtype).get(ch))
//		{
//			switch(classtype)
//			{
//			case Employee:
//				tmp = new employee();
//				break;
//			case Manager:
//				tmp = new manager();
//				break;
//			case Fink:
//				tmp = new fink();
//				break;
//			case Highfink:
//				tmp = new highfink();
//				break;
//			default:
//				cout << "Unrealized Type\n";
//				exit(EXIT_FAILURE);
//			}
//			tmp->getAll(fin);
//			tmp->ShowAll();
//			delete tmp;
//		}
//	}
//	fin.close();
//
//	ofstream fout(file,ios_base::out | ios_base::app);
//	tmp = NULL;
//	classtype = -1;
//	//add new names
//	if(!fout.is_open())
//	{
//		cerr << "Can't open " << file << " file for output.\n";
//		exit(EXIT_FAILURE);
//	}
//
//	for(i = 0,ct = 0;i < MAX;i++,ct++)
//	{
//		cout << "Enter classtype[0,1,2,3](-1 to quit):";
//		(cin >> classtype).get(ch);
//		switch(classtype)
//		{
//		case Employee:
//			cout << "employee\n";
//			pc[i] = new employee();
//			break;
//		case Manager:
//			cout << "manager\n";
//			pc[i] = new manager();
//			break;
//		case Fink:
//			cout << "fink\n";
//			pc[i] = new fink();
//			break;
//		case Highfink:
//			cout << "highfink\n";
//			pc[i] = new highfink();
//			break;
//		default:
//			cout << "Unrealized Type\n";
//			break;
//		}
//		if(classtype <= -1)
//			break;
//		pc[i]->SetAll();
//		fout << classtype << endl;
//		pc[i]->writeAll(fout);
//	}
//	fout.close();
//
//	//show revised file
//	fin.clear();
//	fin.open(file);
//	classtype = -1;
//	if(fin.is_open())
//	{
//		cout << "Here are the contents of the " << file << " file:\n";
//		while((fin >> classtype).get(ch))
//		{
//			switch(classtype)
//			{
//			case Employee:
//				tmp = new employee();
//				break;
//			case Manager:
//				tmp = new manager();
//				break;
//			case Fink:
//				tmp = new fink();
//				break;
//			case Highfink:
//				tmp = new highfink();
//				break;
//			default:
//				cout << "Unrealized Type\n";
//				exit(EXIT_FAILURE);
//			}
//			tmp->getAll(fin);
//			tmp->ShowAll();
//			delete tmp;
//		}
//	}
//	fin.close();
//	cout << "Done.\n";
//
//	return 0;
//}