//17.21 ostringstream wostringstream str()
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	using namespace std;

	ostringstream outstr;//manage a string stream

	string hdisk;
	cout << "What's the name of your disk?";
	getline(cin,hdisk);
	int cap;
	cout << "What's its capacity in GB?";
	cin >> cap;
	//write formatted information to string stream
	outstr << "The hard disk " << hdisk << " has a capacity of "
			<< cap << " gigabytes.\n";
	string result = outstr.str();//save result
	cout << result;//show contents

	return 0;
}