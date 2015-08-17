#include<iostream>
#include<climits>
#define ZERO 0

using namespace std;

int main()
{
	short sam = SHRT_MAX;
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited" << endl;
	cout << " Add 1$ to each other" << endl;
	sam += 1;
	sue += 1;
	cout << "Noew sam has " << sam << " dollars and Sue has " << sue << " dollars deposited" << endl;
	cout << "Poor sam!" << endl;
	sam = sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited" << endl;
	cout << "Take 1$ from each other." << endl;
	sam -= 1;
	sue -= 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited" << endl;
	cout << "Lucky sue!" << endl;
	return 0;
}