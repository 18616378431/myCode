////��ʹ�������в���,��д13.2
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
//	puts("����Դ�ļ���:");
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
//	//��������
//	while((ch = getc(in)) != EOF)
//	{
//		if(count++ % 3 == 0)
//		{
//			putc(ch,out);
//		}
//	}
//	//�ر��ļ�
//	if(fclose(in) != 0 || fclose(out) != 0)
//	{
//		fprintf(stderr,"Error in closing files.\n");
//		exit(EXIT_FAILURE);
//	}
//	puts("Done.");
//	return 0;
//}