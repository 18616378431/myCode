////sprintf();作用和printf()函数一样，区别是写到字符串，而不是写到输出显示,第一个参数为目标字符串地址，其余和printf()一样
////把几个元素组合成字符串,把输入格式化为标准形式后存放在字符串数组中
//#include<stdio.h>
//#define MAX 20
//
//int main()
//{
//	char first[MAX];
//	char last[MAX];
//	char format[2*MAX + 10];
//	double prize;
//
//	puts("Enter your first name:");
//	gets(first);
//
//	puts("Enter your last name:");
//	gets(last);
//
//	puts("Enter your prize money:");
//	scanf("%lf",&prize);
//
//	sprintf(format,"%s,%-19s:$%6.2f\n",last,first,prize);
//
//	puts(format);
//	return 0;
//}