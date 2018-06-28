//5. 16 pratice8
//#include <iostream>
//#include <string>
//#include <set>
//#include <algorithm>
//#include <fstream>
//#include <cstdlib>
//
//using namespace std;
//
//const char *filemat = "mat.txt";
//const char *filepat = "pat.txt";
//const char *filematnpat = "matnpat.txt";
//
//typedef set<string> ss;
//
//ss & getInfo(ss & in,string name,const char *file);
//
//int main()
//{
//	ss mat,pat,union_friend;
//	ofstream fout(filematnpat,ios_base::out | ios_base::trunc);
//	ostream_iterator<string,char> out(cout," ");
//	ostream_iterator<string,char> fileout(fout,"\n");
//
//	getInfo(mat,"Mat",filemat);
//	copy(mat.begin(),mat.end(),out);
//	cout << endl;
//
//	getInfo(pat,"Pat",filepat);
//	copy(pat.begin(),pat.end(),out);
//	cout << endl << endl;
//
//	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),insert_iterator<ss>(union_friend,union_friend.begin()));
//	copy(union_friend.begin(),union_friend.end(),out);
//	copy(union_friend.begin(),union_friend.end(),fileout);
//	cout << endl;
//
//	return 0;
//}
//
//ss & getInfo(ss & in,string name,const char *file)
//{
//	cout << "Get names from file for " << name << "\n";
//	string temp;
//	ifstream fin(file,ios_base::in); 
//	if(!fin.is_open())
//	{
//		cerr << "Open file " << file << "failed.\n";
//		exit(EXIT_FAILURE);
//	}
//	while(getline(fin,temp) && temp != "quit")
//	{
//		in.insert(temp);
//	}
//	return in;
//}