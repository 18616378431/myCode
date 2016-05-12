//fprintf(),fscanf(),rewind()函数使用
#include<stdio.h>
#include<stdlib.h>//exit()原型
#define MAX 40

int main()
{
	FILE * fp;
	char words[MAX];
	//打开并创建文件以供读写
	if((fp = fopen("words","a+")) == NULL)//以可读写追加模式打开文件，文件不存在则创建
	{
		fprintf(stdout,"Can't open \"words\" file.");
		exit(EXIT_FAILURE);
	}
	printf("Enter words to add to file.\n");
	while(gets(words) != NULL && words[0] != '\0')//向文件中写入内容
	{
		fprintf(fp,"%s",words);
	}
	puts("File contents.");
	rewind(fp);//将文件指针重置到文件开始处
	while(fscanf(fp,"%s",words) == 1)
	{
		puts(words);
	}
	//关闭文件
	if((fclose(fp)) != 0)//0为关闭成功，否则EOF失败
	{
		fprintf(stderr,"Error Closing file.\n");
	}
	return 0;
}