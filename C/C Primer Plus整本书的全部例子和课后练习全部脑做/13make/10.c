////交互式获取文本文件名称
////循环获取文件位置
////打印从该位置到换行符之间的内容
////非数字字符终止循环
//#include<stdio.h>
//#include<stdlib.h>
//#define SIZE 41
//#define LINESIZE 256
//
//int main()
//{
//	FILE * fp;
//	char filename[SIZE];
//	int pos;//文件位置
//	char ch[LINESIZE];
//
//	puts("Enter filename:");
//	gets(filename);
//	if((fp = fopen(filename,"r")) == NULL)
//	{
//		fprintf(stderr,"Can't open file %s.\n",filename);
//		exit(EXIT_FAILURE);
//	}
//	puts("Position:");
//	while(scanf("%d",&pos) == 1)//换行符占字节，带有换行的文本下标不准
//	{
//		fseek(fp,pos - 1,SEEK_SET);//将文件指针移动到距离文件开始pos的位置
//		fscanf(fp,"%s",ch);
//		puts(ch);
//		puts("Position(q to quit):");
//	}
//	return 0;
//}