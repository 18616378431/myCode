////修改13.3，从1开始为每个加入的单词编号，程序再次运行时，接着之前的编号
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>//strlen()
//#define MAX 41
//
//int main()
//{
//	FILE * fp;
//	char words[MAX];
//	int number = 0;//单词编号
//	char ch;
//
//	if((fp = fopen("words","a+")) == NULL)
//	{
//		fprintf(stderr,"Can't open file \"words\".\n");
//		exit(EXIT_FAILURE);
//	}
//	//根据换行符数量确定单词编号
//	while((ch = getc(fp)) != EOF)
//	{
//		if(ch == '\n')
//		{
//			number++;
//		}
//	}
//	puts("Enter words to add to the file(any single character to quit).");
//	while(fscanf(stdin,"%s",words) == 1 && strlen(words) > 2)
//	{
//		printf("%d.\n",strlen(words));
//		fprintf(fp,"%d.%s\n",number++,words);//将words内容写入fp指向的文件中
//	}
//	puts("File contents:");
//	rewind(fp);//将文件指针恢复到文件开始处
//	while(fscanf(fp,"%s",words) == 1)//按行读取文件内容，fscanf()读取一个项目成功返回1，否则返回0,存储在words中
//	{
//		fprintf(stdout,"%s\n",words);
//	}
//	if(fclose(fp) != 0)
//	{
//		fprintf(stderr,"Error closing file.\n");
//	}
//	return 0;
//}