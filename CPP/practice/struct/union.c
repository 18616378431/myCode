//#include<stdio.h>
//
////共用体、联合体
////共用体所占内存空间为联合体内最大数据类型所占空间
//union data{
//	int a;
//	char b;
//	int c;
//};
//
//int main()
//{
//	//声明联合体变量
//	union data tt;
//	//共用体变量值为最后一次赋值的值，后面的会覆盖前面的
//	tt.b = 'C';
//	tt.c = 4;
//
//	//printf("%c\n",tt.b);
//	printf("%d\n",tt.c);
//	printf("sizeof:%d\n",sizeof(union data));
//	return 0;
//}