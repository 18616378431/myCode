//把文件压缩为原来的三分之一
#include<stdio.h>
#include<stdlib.h>//调用exit()
#include<string.h>//strcpy(),strcat()
#define LEN 40

int main(int argc,char * argv[])
{
	FILE * in;//要读取和写入的文件的指针
	FILE * out;
	int ch;//存储文件字符
	char name[LEN];//存储文件名称
	int count = 0;//字符计数

	//检查命令行参数
	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//实现输入，打开文件以便读取
	if((in = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//实现输出，打开文件以便写入
	strcpy(name,argv[1]);//复制文件名称
	strcat(name,".red");//拼接字符串，在文件名称之后加入.red后缀
	if((out = fopen(name,"w")) == NULL)
	{
		fprintf(stderr,"Can't create output file %s.\n",name);
		exit(EXIT_FAILURE);
	}
	printf("%s\n",name);
	//复制字符
	while((ch = getc(in)) != EOF)
	{
		if(count++ % 3 == 0)//打印每三个字符的第一个
		{
			putc(ch,out);
		}
	}
	//收尾工作,文件关闭成功返回0，否则返回EOF
	if(fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr,"Error in closing files.\n");
	}
	return 0;
}