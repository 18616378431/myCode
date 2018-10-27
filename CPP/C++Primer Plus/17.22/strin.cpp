//17.22 istringstream 
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	using namespace std;

	string lit = "It was a dark and stormy day, and "
		"the full moon glowed brilliantly.";
	istringstream instr(lit);//use buf for input
	string word;
	while(instr >> word)//read a word a time
		cout << word << endl;

	return 0;
}