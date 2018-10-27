//7. string,vector,fstream,Function Object,algorithm
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "store.h"

using namespace std;

const char *file = "strings.dat";

void ShowStr(const string & s);
void GetStr(ifstream & in,vector<string> & vi);

int main()
{
	vector<string> vostr;
	string temp;
	
	//acquire strings
	cout << "Enter strings(empty line to quit):\n";
	while(getline(cin,temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(),vostr.end(),ShowStr);

	//store in file
	ofstream fout(file,ios_base::out | ios_base::binary);
	for_each(vostr.begin(),vostr.end(),store(fout));
	fout.close();

	//recover file contents
	vector<string> vistr;
	ifstream fin(file,ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStr(fin,vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);


	return 0;
}
//Show vector contents
void ShowStr(const string & s)
{
	cout << s << endl;
}
//Get binary contents from file
void GetStr(ifstream & in,vector<string> & vi)
{
	std::size_t len;
	while(in.read((char *)&len,sizeof(len)))
	{
		char *str = new char[len + 1];
		in.read(str,len);
		str[len] = '\0';
		vi.push_back(str);
		delete str;
	}

}