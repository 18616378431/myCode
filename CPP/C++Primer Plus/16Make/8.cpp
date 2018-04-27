//8. 
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

typedef set<string> ss;

ss & getInfo(ss & in,string name);

int main()
{
	ss mat,pat,union_friend;
	ostream_iterator<string,char> out(cout," ");
	
	getInfo(mat,"Mat");
	copy(mat.begin(),mat.end(),out);
	cout << endl;

	getInfo(pat,"Pat");
	copy(pat.begin(),pat.end(),out);
	cout << endl;

	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),insert_iterator<ss>(union_friend,union_friend.begin()));
	copy(union_friend.begin(),union_friend.end(),out);
	cout << endl;

	return 0;
}

ss & getInfo(ss & in,string name)
{
	cout << "Enter names for " << name << "(quit to quit):\n";
	string temp;
	while(cin >> temp && temp != "quit")
	{
		in.insert(temp);
		cout << "Enter names for " << name << "(quit to quit):\n";
	}
	return in;
}