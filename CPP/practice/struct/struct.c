//#include<stdio.h>
////结构体变量内存空间分配
////结构体变量对齐及补位
//
////结构体总内存空间为结构体内最大数据类型的整数倍，
////不足则在结构体最后一个变量末尾补位
//
////结构体变量的偏移为对应成员变量类型的整数倍，不足则在改成员变量后补位
////结构体变量的偏移值:变量的起始地址到结构体起始地址的距离
//struct data{
//	int a;//a为结构体第一个变量,偏移为0
//	char b;//偏移为第一个变量的大小即int类型大小4，char大小为1,4是1的整数倍
//	int c;//偏移为5，5不是int 4的整数倍，在变量b后面进行补位，将c的偏移补位到8
//};
//
//
//int main()
//{
//	struct data data_1;
//
//	printf("sizeof:%d\n",sizeof(struct data));
//	return 0;
//}