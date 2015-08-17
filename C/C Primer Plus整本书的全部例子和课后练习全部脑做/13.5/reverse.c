//随机存取
#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'

int main(int argc,char * argv[])//通过命令行参数操作文件
{
	char ch;//存储文件字符
	FILE *fp;
	long count,last;//字符位置计数，文件末尾计数

	if((fp = fopen(argv[1],"rb")) == NULL)
	{
		printf("Error open %s file.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//定位到文件末尾
	fseek(fp,0L,SEEK_END);
	last = ftell(fp);//报告文件指针当前位置
	for(count = 1L;count <= last;count++)
	{
		fseek(fp,-count,SEEK_END);
		ch = getc(fp);
		//针对DOS下，UNIX也可以工作
		if(ch != CNTL_Z && ch != '\r')
		{
			putchar(ch);
		}
		//针对Macintosh
		/*if(ch == '\r')
		{
			putchar('\n');
		}
		else
		{
			putchar(ch);
		}*/
	}
	putchar('\n');
	//关闭文件
	if(fclose(fp) != 0)
	{
		fprintf(stderr,"Error closing file.\n");
	}
	return 0;
}