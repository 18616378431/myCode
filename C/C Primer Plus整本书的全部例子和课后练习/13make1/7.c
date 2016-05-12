//a.程序打印打一个文件的第一行、第二个文件的第一行，第一个文件的第二行、第二个文件的第二行
//b.修改程序，将行号相同的打印到同一行上
//将文件内容按行存储在二维数组中
#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 1024

int main(int argc,char * argv[])
{
	FILE * fp1,* fp2;
	char  f1[BUFSIZE];
	char  f2[BUFSIZE];
	int i;//数组下标
	//判断命令行
	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//打开文件以供读取
	if((fp1 = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//创建缓冲区
	if(setvbuf(fp1,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//打开文件以供读取
	if((fp2 = fopen(argv[2],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	//创建缓冲区
	if(setvbuf(fp2,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//将文件内容读入数组
	//putc(getc(fp1),stdout);
	/*i = 0;
	while(fgets(f2[i],BUFSIZE,fp2))
	{
		i++;
	}*/
	//fscanf()不读取换行
	/*fscanf(fp1,"%s",temp);
	fprintf(stdout,"%s",temp);*/
	
	return 0;
}