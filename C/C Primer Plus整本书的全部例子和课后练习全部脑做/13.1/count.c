//读取文件并计数字符个数EXIT_SUCCESS = 0,EXIT_FAILURE = 1
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	int ch;//存储每个字符的位置
	FILE *fp;//文件指针
	long count = 0;//字符计数

	if(argc != 2)
	{
		printf("Usage:%s filename.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((fp = fopen(argv[1],"rb")) == NULL)
	{
		printf("Can't open %s.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	while(ch = getc(fp) != EOF)
	{
		putc(ch,stdout);//相当于putchar();
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters.\n",argv[0],count);
	return 0;
}