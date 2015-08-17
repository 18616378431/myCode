//把多个文件内容追加到一个文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024

//函数声明
void append(FILE * source,FILE * dest);

//命令行参数形式将多个文件内容追加到同一文件
int main(int argc,char * argv[])//argv[1]为目标文件名称，argv[2],3,4...为源文件名称
{
	FILE * fa,* fs;//fa目标文件，fs源文件
	int files = 0;//追加的文件个数
	int i = 2;//源文件的命令行参数，argv数组下标2开始读取
	
	//追加模式打开目标文件
	if((fa = fopen(argv[1],"a")) == NULL)
	{
		fprintf(stderr,"Error opening file %s.\n",argv[1]);
		exit(1);
	}
	//为目标文件创建1024缓冲区,buf为NULL，函数自动为自己分配缓冲区
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Can't create ouput buff.\n");
		exit(2);
	}
	//循环获取所有源文件名称
	while(argv[i] && argv[i][0] != '\0')
	{
		//判断源文件与目标文件名称是否相同
		if(strcmp(argv[1],argv[i]) == 0)
		{
			fputs("Can't append file to itself.\n",stderr);
		}
		else if((fs = fopen(argv[i],"r")) == NULL)//打开源文件
		{
			fprintf(stderr,"Can't open file %s.\n",argv[i]);
		}
		else
		{
			//为源文件设置缓冲区
			if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
			{
				fprintf(stderr,"Can't create input buff");
				continue;
			}
			//
			append(fs,fa);
			if(ferror(fs) != 0)
			{
				fprintf(stderr,"Error in reading file %s.\n",argv[i]);
			}
			if(ferror(fa) != 0)
			{
				fprintf(stderr,"Error in writing file %s.\n",argv[1]);
			}
			//关闭当前源文件
			fclose(fs);
			files++;
			printf("File %s appended.\n",argv[i]);
			i++;
		}
	}
	printf("Done.%d files appended.\n",files);
	//关闭目标文件
	return 0;
}
//fread(),fwrite()每次复制1024字节
void append(FILE * source,FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];//分配一次，存储读取的字符

	if((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
	{
		fwrite(temp,sizeof(char),bytes,dest);
	}
}