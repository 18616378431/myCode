#include<iostream>

using namespace std;

namespace CompA
{
	//�������е����ֵ����Сֵ
	int getMaxOrMin(int *arr,int n,bool isMax)
	{
		int temp = arr[0];

		for(int i = 1;i < n;i++)
		{
			if(isMax)
			{
				if(temp < arr[i])
				{
					temp = arr[i];
				}
			}
			else
			{
				if(temp > arr[i])
				{
					temp = arr[i];
				}
			}
		}
		return temp;
	}
}

int main()
{
	int arr[4] = {3,5,1,7};
	bool flag = false;
	
	cout << "�����ֵ����Сֵ(1,0):" << endl;
	cin >> flag;
	cout << CompA::getMaxOrMin(arr,sizeof(arr)/sizeof(int),flag) << endl;
	return 0;
}
