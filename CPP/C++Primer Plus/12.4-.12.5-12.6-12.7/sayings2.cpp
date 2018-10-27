//12.7 指向对象的指针
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	
	String name;
	cout << "Hi!What's your name?\n";
	cin >> name;

	cout << name << ",please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i = 0;
	for(i = 0;i < ArSize;i++)
	{
		cout << i + 1 << ":";
		cin.get(temp,MaxLen);
		while(cin && cin.get() != '\n')
			continue;
		if(!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if(total > 0)
	{
		cout << "Here are your sayings:\n";
		for(i = 0;i < total;i++)
			cout << sayings[i] << "\n";

		//使用对象指针跟踪最短和字母排在最前的对象
		String *shortest = &sayings[0];
		String *first = &sayings[0];
		for(i = 1;i < total;i++)
		{
			if(sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if(sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortest saying:" << *shortest << endl;
		cout << "First alphabetically:" << *first << endl;

		srand(time(0));
		int choice = rand() % total;
		//使用选中的初始化一个对象
		String *favorite = new String(sayings[choice]);
		cout << "My favorite saying:" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "No much to say,eh?\n";
	cout << "Bye.\n";

	return 0;
}