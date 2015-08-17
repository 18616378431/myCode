////将二进制字符串转换为数值
//#include<stdio.h>
//#include<string.h>
//
//int bstoi(char * pbs);
//
//int main()
//{
//	char pbin[32];//0100 1001,1 8 64 = 73
//	
//	puts("Enter a binary string");
//	gets(pbin);
//	printf("binary string to integer is %d.\n",bstoi(pbin));
//	return 0;
//}
//int bstoi(char * pbs)
//{
//	int i = 1;
//	int sum = 0;
//	int size = (int)strlen(pbs) - 1;
//
//	pbs += size;
//	while(size-- >= 0)
//	{
//		sum += (*pbs-- - '0') * i;
//		i *= 2;
//	}
//	return sum;
//}