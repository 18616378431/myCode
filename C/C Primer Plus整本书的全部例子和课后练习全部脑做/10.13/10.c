//#include<stdio.h>
//#define ROWS 3
//#define COLS 5
//
//void showA(int ar[][COLS],int n);
//void getMutiplyTwo(int ar[][COLS],int n);
//
//int main()
//{
//	int source[ROWS][COLS] = {
//		{1,2,3,4,5},
//		{6,7,8,9,10},
//		{11,12,13,14,15}
//	};
//
//	printf("ԭ����:\n");
//	showA(source,ROWS);
//	getMutiplyTwo(source,ROWS);
//	printf("������:\n");
//	showA(source,ROWS);
//	return 0;
//}
////��ʾ����
//void showA(int ar[][COLS],int n)
//{
//	int r;
//	int c;
//
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < COLS;c++)
//		{
//			printf("source[%d][%d] = %d\n",r,c,ar[r][c]);
//		}
//	}
//}
////����ֵ����
//void getMutiplyTwo(int ar[][COLS],int n)
//{
//	int r;
//	int c;
//
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < COLS;c++)
//		{
//			ar[r][c] *= 2;
//		}
//	}
//}