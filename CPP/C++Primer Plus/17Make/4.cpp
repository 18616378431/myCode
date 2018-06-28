//4. two file to another file
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstdlib>
//
//using namespace std;
//
//const char *file1 = "4-1in.txt";
//const char *file2 = "4-2in.txt";
//const char *file3 = "4-3out.txt";
//
//int main()
//{
//	ifstream fin1(file1,ios_base::in),
//			 fin2(file2,ios_base::in);
//	ofstream fout(file3,ios_base::out);
//	string str1,str2;
//
//	if(!fin1.is_open() || !fin2.is_open() || !fout.is_open())
//	{
//		if(fin1.fail())
//			cerr << "Open " << file1 << " failed.\n";
//		else if(fin2.fail())
//			cerr << "Open " << file2 << " failed.\n";
//		else if(fout.fail())
//			cerr << "Open " << file3 << "failed.\n";
//		exit(EXIT_FAILURE);
//	}
//
//	while(!fin1.eof() && !fin2.eof())
//	{
//		getline(fin1,str1);
//		getline(fin2,str2);
//		fout << str1 << " " << str2 << endl;
//	}
//	
//	if(!fin1.eof())
//	{
//		while(getline(fin1,str1))
//			fout << str1 << endl;
//	}
//
//	if(!fin2.eof())
//	{
//		while(getline(fin2,str2))
//			fout << str2 << endl;
//	}
//
//	fin1.close();
//	fin2.close();
//	fout.close();
//
//	return 0;
//}