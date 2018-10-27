//#include<iostream>
//#include<fstream>
//#include<cstdlib>
//
//using namespace std;
//
//int main()
//{
//	ifstream inFile;
//	int count = 0;
//	char ch;
//
//	inFile.open("test.txt");
//	if(!inFile.is_open())
//	{
//		cout << "Open file error" << endl;
//		exit(EXIT_FAILURE);
//	}
//	inFile >> ch;
//	while(inFile.good())
//	{
//		count++;
//		inFile >> ch;
//	}
//	if(inFile.eof())
//	{
//		cout << "End of file reached" << endl;
//	}
//	else if(inFile.fail())
//	{
//		cout << "Input terminated by mismatch." << endl;
//	}
//	else
//	{
//		cout << "Input terminated by unknow reason." << endl;
//	}
//	if(count == 0)
//	{
//		cout << "No data." << endl;
//	}
//	else
//	{
//		cout << count << " characters readed!" << endl;
//	}
//	return 0;
//}