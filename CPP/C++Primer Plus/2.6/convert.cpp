#include<iostream>

using namespace std;

int stoneToPound(int);

int main()
{
	int stone;
	cout << "Enter the weight int stone:";
	cin >> stone;
	int pounds = stoneToPound(stone);
	cout << stone << " stone = " << pounds << " pounds" << endl;
	return 0;
}
int stoneToPound(int sts)
{
	return 14 * sts;
}