////从命令行读取两个二进制字符串，转换为数值，然后按位取反,对这两个数& | ^
////使用二进制字符串形式显示结果
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int bstoi(char * pbs);
//void show_binary(int n,char *);
//
//int main(int argc,char *argv[])
//{
//	int bs1,bs2;
//	char bstr[8 * sizeof(int) + 1];
//
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	bs1 = bstoi(argv[1]);
//	bs2 = bstoi(argv[2]);
//	printf("bs1 =  %d,bs2 = %d.\n",bs1,bs2);
//	show_binary(bs1,bstr);
//	show_binary(bs2,bstr);
//	//~
//	printf("~bs1 =  %d, ~bs2 = %d.\n",~bs1,~bs2);
//	show_binary(~bs1,bstr);
//	show_binary(~bs2,bstr);
//	//	&
//	printf("bs1 & bs2 is %d.\n",bs1 & bs2);
//	show_binary(bs1 & bs2,bstr);
//	//	|
//	printf("bs1 | bs2 is %d.\n",bs1 | bs2);
//	show_binary(bs1 | bs2,bstr);
//	//	^
//	printf("bs1 ^ bs2 is %d.\n",bs1 ^ bs2);
//	show_binary(bs1 ^ bs2,bstr);
//	return 0;
//}
//int bstoi(char * pbs)
//{
//	int i = 1,sum = 0;
//	int size = (int)strlen(pbs);
//	
//	pbs += size - 1;
//	while(size-- > 0)
//	{
//		sum += (*pbs-- - '0') * i;
//		i *= 2;
//	}
//	return sum;
//}
//void show_binary(int n,char * p)
//{
//	int i;
//	static int size = 8 * sizeof(int);
//	
//	for(i = size - 1;i >= 0;i--,n >>= 1)
//	{
//		p[i] = (01 & n) + '0';
//	}
//	p[size] = '\0';
//	puts(p);
//}