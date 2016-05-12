////复制程序，命令行参数，将源文件中的小写字母全部转换为大写存入目标文件ctype.h,文本模式
////argv[1]目标文件，argv[2]源文件
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include<ctype.h>//toupper()
//#include<string.h>//strcmp()
//#define BUFSIZE 1024
//
//void file_copy(FILE * dest,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE * fa,* fs;
//	//判断命令参数个数是否正确
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//打开目标文件以供写入
//	if((fa = fopen(argv[1],"w")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//为目标文件创建缓冲区
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create output buff.\n");
//	}
//	//打开源文件
//	if((fs = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	else//源文件打开成功
//	{
//		if(strcmp(argv[1],argv[2]) == 0)//比较是否为同一个文件
//		{
//			fprintf(stderr,"Can't copy it to itself.\n");
//			exit(EXIT_FAILURE);
//		}
//		//为源文件创建缓冲区
//		if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//		{
//			fprintf(stderr,"Fail to create input buff.\n");
//		}
//		file_copy(fa,fs);
//		if(ferror(fa) != 0)
//		{
//			fprintf(stderr,"Error in writing file.\n");
//		}
//		if(ferror(fs) != 0)
//		{
//			fprintf(stderr,"Error in reading file.\n");
//		}
//	}
//	//关闭文件
//	fclose(fa);
//	fclose(fs);
//	return 0;
//}
////文件复制
//void file_copy(FILE * dest,FILE * source)
//{
//	char ch;
//	
//	while((ch = getc(source)) != EOF && ch != '\0')
//		putc(toupper(ch),dest);
//}