////�����г���һ���ַ�����������ļ�������,�ַ����޲����������ȡ��׼����
////��ÿ���ļ��������ļ��г��ֵ��ַ�����
////argv[1][0] Ϊ�ַ�
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
//	int i = 2;//ѭ����ȡ�ļ��������±�
//	if(argc <= 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		//�ַ����޲�������ȡ��׼����
//		gets(str);
//		printf("There is %d %c come from your input.",showCNum(str,argv[1][0]),argv[1][0]);
//	}
//	while(argv[i])
//	{
//		if((fp = fopen(argv[i],"r")) == NULL)//�������ļ�
//		{
//			fprintf(stderr,"Can not open file %s.\n",argv[i++]);
//			continue;
//		}
//		if((setvbuf(fp,NULL,_IOFBF,BUFSIZE) != 0))//����������
//		{
//			fprintf(stderr,"Fail to create input buff.\n");
//		}
//		printf("There is %d %c in %s.\n",showNum(fp,argv[1][0]),argv[1][0],argv[i]);
//		//������
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
////�ַ����в���,�����ļ�ָ����ַ�
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
////�ַ����޲���,���ַ����в�ѯ�ַ����ֵĴ���
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