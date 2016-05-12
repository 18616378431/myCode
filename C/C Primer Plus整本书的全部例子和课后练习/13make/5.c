////命令行参数重写13.6,多个文件追加到一个文件,argv[1]目标文件，argv[2]....源文件
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include<string.h>//strcmp()
//#define BUFSIZE 1024
//
//void append(FILE * dest,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE * fa,* fs;
//	int files = 0;//记录文件个数
//	int i = 2;//索引
//
//	if(argc == 1)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//打开目标文件
//	if((fa = fopen(argv[1],"w")) == NULL)
//	{
//		fprintf(stderr,"Can't open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//为目标文件创建缓冲区
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create output buff.\n");
//	}
//	while(argv[i])
//	{
//		//判断是否为同一文件
//		if(strcmp(argv[i],argv[1]) == 0)
//		{
//			fprintf(stderr,"Can't append to itself.\n");
//			continue;
//		}
//		//打开源文件以供读取
//		if((fs = fopen(argv[i],"r")) == NULL)
//		{
//			fprintf(stderr,"Can not open input file %s.\n",argv[i]);
//			exit(EXIT_FAILURE);
//		}
//		//为源文件创建缓冲区
//		if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//		{
//			fprintf(stderr,"Can not create input buff.\n");
//			continue;
//		}
//		append(fa,fs);
//		if(ferror(fs) != 0)
//		{
//			fprintf(stderr,"Error in reading file.\n");
//		}
//		if(ferror(fa) != 0)
//		{
//			fprintf(stderr,"Error in writing file.\n");
//		}
//		files++;
//		fclose(fs);
//		printf("file %s appened.\n",argv[i]);
//		i++;
//	}
//	fclose(fa);
//	printf("%d files appended.\n",files);
//	printf("Done.\n");
//	return 0;
//}
////追加文件
//void append(FILE * dest,FILE * source)
//{
//	static char temp[BUFSIZE];
//	size_t bytes;//成功读入项目计数
//
//	while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
//	{
//		fwrite(temp,sizeof(char),bytes,dest);
//	}
//}