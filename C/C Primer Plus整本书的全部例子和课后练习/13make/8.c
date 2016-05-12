////命令行程序，一个字符、零个或多个文件名参数,字符后无参数，程序读取标准输入
////打开每个文件并报告文件中出现的字符次数
////argv[1][0] 为字符
//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>//toupper()
//#define SIZE 81
//#define BUFSIZE 1024
//
//int showNum(FILE * fs,char ch);
//int showCNum(char *p,char ch);
//
//int main(int argc,char * argv[])
//{
//	FILE * fp;
//	char str[SIZE];
//	int i = 2;//循环获取文件名参数下标
//	if(argc <= 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		//字符后无参数，读取标准输入
//		gets(str);
//		printf("There is %d %c come from your input.",showCNum(str,argv[1][0]),argv[1][0]);
//	}
//	while(argv[i])
//	{
//		if((fp = fopen(argv[i],"r")) == NULL)//打开输入文件
//		{
//			fprintf(stderr,"Can not open file %s.\n",argv[i++]);
//			continue;
//		}
//		if((setvbuf(fp,NULL,_IOFBF,BUFSIZE) != 0))//创建缓冲区
//		{
//			fprintf(stderr,"Fail to create input buff.\n");
//		}
//		printf("There is %d %c in %s.\n",showNum(fp,argv[1][0]),argv[1][0],argv[i]);
//		//错误检测
//		if(ferror(fp) != 0)
//		{
//			fprintf(stderr,"Error in reading file %s.\n",argv[i]);
//		}
//		if(fclose(fp) != 0)
//		{
//			fprintf(stderr,"Error in closing file %s.\n",argv[i]);
//		}
//		i++;
//	}
//	return 0;
//}
////字符后有参数,传递文件指针和字符
//int showNum(FILE * fs,char arg)
//{
//	char ch;
//	int ct = 0;
//
//	while((ch = getc(fs)) != EOF)
//	{
//		if(toupper(ch) == toupper(arg))
//		{
//			ct++;
//		}
//		putc(ch,stdout);
//	}
//	return ct;
//}
////字符后无参数,在字符串中查询字符出现的次数
//int showCNum(char *p,char ch)
//{
//	int ct = 0;
//
//	while(*p != '\0')
//	{
//		if(ch == *p)
//		{
//			ct++;
//		}
//		p++;
//	}
//	return ct;
//}