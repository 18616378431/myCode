////��д13.1����ʹ�������в���
//#include<stdio.h>
//#include<stdlib.h>
//#define ARRSIZE 41
//
//int main()
//{
//	char file[ARRSIZE];
//	FILE * fp;
//	long count = 0;//����
//	char ch;//�ַ�
//	
//	puts("File name:");
//	gets(file);
//	if((fp = fopen(file,"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",file);
//	}
//	while((ch = getc(fp)) != EOF)
//	{
//		putc(ch,stdout);
//		count++;
//	}
//	printf("\nFile %s has %ld characters.\n",file,count);
//	return 0;
//}