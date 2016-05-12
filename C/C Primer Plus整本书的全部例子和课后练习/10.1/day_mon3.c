////指针与数组
//#include<stdio.h>
//#define MONTHS 12
//
//int main()
//{
//	//days为数组首元素地址，(days + n)为days[n]的地址,用取值符*可以取得相应地址内存储的数值
//	//days = &days[0]
//	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
//	int index;
//
//	for(index = 0;index < MONTHS;index++)
//	{
//		printf("Month %2d has %d days.\n",index + 1,*(days + index));
//	}
//	return 0;
//}