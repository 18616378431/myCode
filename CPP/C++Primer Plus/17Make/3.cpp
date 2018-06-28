//cp file1 to file2 and show error
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstdlib>
//
//using namespace std;
//
//int main(int argc,char *argv[])
//{
//	if(argc != 3)
//	{
//		cerr << "Param error!\n";
//		exit(EXIT_FAILURE);
//	}
//
//	fstream fin(argv[1],ios_base::in),fout(argv[2],ios_base::out);
//	string str;
//
//	
//	if(!fin.is_open() || !fout.is_open())
//	{
//		cerr << "Open file fail!\n";
//		exit(EXIT_FAILURE);
//	}
//
//	while(getline(fin,str))
//	{
//		fout << str << endl;
//	}
//
//	fin.close();
//	fout.close();
//
//	return 0;
//}