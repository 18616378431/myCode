#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	float sec;
	cout << "Enter the delay time in seconds:";
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC;//�������Գ����õ�ϵͳʱ��
	cout << "starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "Done\a\n";
	cout << time(NULL) << endl;
	return 0;
}