//get input until eof and write to cmd param file
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstdlib>
//
//using namespace std;
//
//int main(int argc,char *argv[])
//{
//	if(argc < 2)
//	{
//		cerr << "Haven't set output file!\n";
//		exit(EXIT_FAILURE);
//	}
//		
//	ofstream fout(argv[1],ios_base::out);
//	string input;
//	
//	while(getline(cin,input))
//	{
//		fout << input << endl;
//	}
//
//	fout.close();
//
//	return 0;
//}