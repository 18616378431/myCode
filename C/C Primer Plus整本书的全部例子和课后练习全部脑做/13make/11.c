////命令行程序，第一个参数为字符串，第二个参数为文件名
////在文件中查找第一个字符串的行，并打印
//#include<stdio.h>
//#include<string.h>//strstr()
//#include<stdlib.h>
//#define SIZE 256
//
//int main(int argc,char * argv[])
//{
//	FILE * fp;
//	char temp[SIZE];
//
//	if(argc < 3)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	if((fp = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while(fgets(temp,SIZE,fp) != NULL)//按行读取，获取换行符
//		if(strstr(temp,argv[1]) != NULL)
//			fputs(temp,stdout);
//	return 0;
//}