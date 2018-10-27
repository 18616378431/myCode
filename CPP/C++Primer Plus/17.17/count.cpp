//17.17 console.h int argc,char *argv[]
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <console.h>//for mac

int main(int argc,char * argv[])
{
	using namespace std;
	
	//argc = ccommand(&argv);
	if(argc == 1)
	{
		cerr << "Usage:" << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}
	
	ifstream fin;//open stream
	long count;
	long total = 0;
	char ch;

	for(int file = 1;file < argc;file++)
	{
		fin.open(argv[file]);//connect stream to argv[file]
		if(!fin.is_open())
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while(fin.get(ch))
			count++;
		cout << count << " characters in " << argv[file] << endl;
		total += count;
		fin.clear();//need for some implementations
		fin.close();//disconnect file
	}

	cout << total << " characters in all files\n";
	
	return 0;
}