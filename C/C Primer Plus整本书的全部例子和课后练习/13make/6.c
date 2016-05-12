////不使用命令行参数,重写13.2
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include<string.h>//strcat()
//#define ALEN 81
//
//int main()
//{
//	char name[ALEN];
//	FILE * in, * out;
//	int ch;
//	int count = 0;
//
//	puts("输入源文件名:");
//	gets(name);
//	if((in = fopen(name,"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open input file %s.\n",name);
//		exit(EXIT_FAILURE);
//	}
//	strcat(name,".red");
//	if((out = fopen(name,"w")) == NULL)
//	{
//		fprintf(stderr,"Can not open output file %s.\n",name);
//	}
//	//复制数据
//	while((ch = getc(in)) != EOF)
//	{
//		if(count++ % 3 == 0)
//		{
//			putc(ch,out);
//		}
//	}
//	//关闭文件
//	if(fclose(in) != 0 || fclose(out) != 0)
//	{
//		fprintf(stderr,"Error in closing files.\n");
//		exit(EXIT_FAILURE);
//	}
//	puts("Done.");
//	return 0;
//}