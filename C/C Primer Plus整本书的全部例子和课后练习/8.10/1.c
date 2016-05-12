////读取一个文件并显示内容
//#include<stdio.h>
//#include<stdlib.h>		//exit()函数原型，终止程序
//
//int main(void)
//{
//	char ch;		//存储获取到的文件中的字符
//	FILE * fp;		//文件指针
//	char filename[50];		//字符数组，存储文件名称
//
//	printf("Enter filename:");
//	scanf("%s",filename);
//
//	fp = fopen(filename,"r");
//	if(fp == NULL)
//	{
//		printf("Failed to open file.Bye!\n");
//		exit(1);
//	}
//	while((ch = getc(fp)) != EOF)
//	{
//		putchar(ch);
//	}
//	fclose(fp);		//关闭文件
//	return 0;
//}