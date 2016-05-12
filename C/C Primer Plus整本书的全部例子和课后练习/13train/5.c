//命令行程序，第一个参数字符argv[1]，第二个参数文件名argv[2],只打印包含指定字符的那些行
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF 256

int has_ch(char ch,char * line);

int main(int argc,char * argv[])
{
	FILE * fp;
	static char data[BUF];
	char * p = data;

	if(argc < 2)
	{
		printf("Usage:%s filename.\n",argv[0]);
	}
	if((fp = fopen(argv[2],"r")) == NULL)
	{
		fprintf(stderr,"Error in opening file %s.\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fp,NULL,_IOLBF,BUF) != 0)
	{
		fprintf(stderr,"Error create output buff.\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(data,BUF,fp))
	{
		if(strstr(data,argv[1]) != NULL && data[0] != '\0' && data[0] != '\n')
		{
			fputs(data,stdout);
		}
		/*if(has_ch(argv[1][0],data))
		{
			fputs(data,stdout);
		}*/
	}
	fclose(fp);
	return 0;
}
int has_ch(char ch,char * line)
{
	while(*line)
	{
		if(ch == *line++)
		{
			return 1;
		}
	}
	return 0;
}