////һ���������������ĺ�����һ��int���飬�����С����ѡȡ����
////���������������ѡ��ָ��������Ԫ�ز���ӡ
//#include<stdio.h>
//#include<stdlib.h>//srand()
//#include<time.h>//time()
//#include<string.h>
//#define SIZE 20
//
//void showByLuck(const int arr[],int size,int n);
//
//int main()
//{
//	int arrays[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//	int d;
//
//	while(scanf("%d",&d) == 1 && d <= 20)
//		showByLuck(arrays,SIZE,d);
//	return 0;
//}
//void showByLuck(const int arr[],int size,int n)
//{
//	int i;
//	int rnd;
//	int copyarr[SIZE];
//
//	srand((unsigned int)time(NULL));
//	memcpy(copyarr,arr,SIZE * sizeof(int));
//	for(i = 0;i < n;i++)
//	{
//		rnd = rand() % 20;
//		if(copyarr[rnd] != 0)
//			printf("%3d",copyarr[rnd]);
//		else
//			i--;
//		copyarr[rnd] = 0;
//	}
//	putchar('\n');
//	for(i = 0;i < 20;i++)
//	{
//		printf("%3d",copyarr[i]);
//	}
//	putchar('\n');
//}