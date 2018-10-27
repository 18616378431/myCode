//15.6 nested class template
#include <iostream>
#include <string>
#include "queuetp.h"

using namespace std;

int main()
{
	QueueTP<string> cs(5);
	string temp;

	while(!cs.isfull())
	{
		cout << "Enter your name:";
		getline(cin,temp);
		cs.enqueue(temp);
	}
	cout << "Queue is full.Processing!\n";

	while(!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << " ...\n";
	}

	return 0;
}