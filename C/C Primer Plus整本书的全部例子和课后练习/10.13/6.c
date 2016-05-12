////复制二维数组
//#include<stdio.h>
//
//void copy_arr(double ar[][3],double tr[][3],int n);
//
//int main()
//{
//	double source[3][3] = {
//				{1.1,2.2,3.3},
//				{4.4,5.5,6.6},
//				{7.7,8.8,9.9}
//	};
//	double target[3][3];
//	int i;
//	int j;
//
//	copy_arr(source,target,3);
//
//	for(i = 0;i < 3;i++)
//	{
//		for(j = 0;j < 3;j++)
//		{
//			printf("Now target[%d][%d] is %.2lf \n",i,j,target[i][j]);
//		}
//	}
//	return 0;
//}
//
//void copy_arr(double ar[][3],double tr[][3],int n)
//{
//	int r;
//	int c;
//
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < n;c++)
//		{
//			tr[r][c] = ar[r][c];
//		}
//	}
//}