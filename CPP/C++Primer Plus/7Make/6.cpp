//#include<iostream>
//
//using namespace std;
//
//const int SIZE = 10;
//
//int file_array(double *arr,int size);
//void show_array(const double *arr,int size);
//void reverse_array(double *arr,int size);
//
//int main()
//{
//	double arr[SIZE];
//
//	int count = file_array(arr,SIZE);
//	show_array(arr,count);
//	reverse_array(arr,count);
//	return 0;
//}
////�������
//int file_array(double *arr,int size)
//{
//	int count = 0;
//	cout << "Enter a double value:";
//	while(count < size && cin >> arr[count])
//	{
//		count++;
//		if(count < size)
//			cout << "Enter a double value:";
//	}
//	return count;
//}
////��ʾ��������
//void show_array(const double *arr,int size)
//{
//	int count = 0;
//
//	while(count < size)
//	{
//		cout << arr[count++] << endl;
//	}
//}
////��ת����,����һ��Ԫ�غ����һ��Ԫ��,��ת����Ԫ��˳��
//void reverse_array(double *arr,int size)
//{
//	double temp[SIZE];
//
//	for(int i = size - 2,j = 1;i >= 1 ;i--,j++)
//	{
//		temp[j] = arr[i];
//	}
//	for(int i = 1;i < size - 1;i++)
//	{
//		arr[i] = temp[i];
//	}
//	cout << "reverse" << endl;
//	show_array(arr,size);
//}