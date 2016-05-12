//#include<stdio.h>
//
//void interchange(int * u,int * v);
//
//int main()
//{
//	int x = 5,y = 10;
//
//	printf("Originally x = %d and y = %d.\n",x,y);
//	interchange(&x,&y);		//向函数传递地址
//	printf("Now x = %d and y = %d.\n",x,y);
//	return 0;
//}
//
//void interchange(int * u,int * v)
//{
//	//参数int * u,意味着u是一个指针变量,u中存储指向一个整形数据的内存地址
//	//函数体部分使用的u代表main()中x的地址,*u为变量x地址中所存储的数据
//	int temp;
//	temp  = *u;
//	*u = *v;
//	*v = temp;
//}