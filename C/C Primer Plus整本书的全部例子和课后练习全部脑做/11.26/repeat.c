#include<stdio.h>
//带有参数的main函数,由命令行启动
//argv[0]指向当前程序，argv[1]指向第一个参数，以此类推
int main(int argc,char *argv[])
{
	int count;

	printf("The command line has %d arguments.\n",argc - 1);
	for(count = 1;count < argc;count++)
	{
		printf("%d:%s\n",count,argv[count]);
	}
	printf("\n");
	return 0;
}