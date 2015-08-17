////复制程序，从命令行参数获得源文件和目的文件名,argv[1]目标文件，argv[2]源文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define BUFSIZE 1024
//
//void file_copy(FILE *destination,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE *fa,*fs;
//	//判断命令行参数个数是否正确
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//打开目标文件以供写入
//	if((fa = fopen(argv[1],"wb")) == NULL)
//	{
//		fprintf(stderr,"Can not open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//为目标文件创建缓冲区
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Can not create output buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//判断是否为同一个文件
//	if(strcmp(argv[1],argv[2]) == 0)
//	{
//		fprintf(stderr,"Can't copy file to itself.\n");
//		exit(EXIT_FAILURE);
//	}
//	if((fs = fopen(argv[2],"rb")) == NULL)
//	{
//		fprintf(stderr,"Can not open input file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	//为源文件创建缓冲区
//	if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Can't create input buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//执行复制函数
//	file_copy(fa,fs);
//	if(ferror(fa) != 0)
//	{
//		fprintf(stderr,"Error in writing file %s.\n",argv[1]);
//	}
//	if(ferror(fs) != 0)
//	{
//		fprintf(stderr,"Error in reading file %s.\n",argv[2]);
//	}
//return 0;
//}
//void file_copy(FILE *destination,FILE * source)
//{
//	static char temp[BUFSIZE];
//	size_t bytes;
//
//	while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
//	{
//		fwrite(temp,sizeof(char),bytes,destination);
//	}
//}