////��ȡһ���ļ�����ʾ����
//#include<stdio.h>
//#include<stdlib.h>		//exit()����ԭ�ͣ���ֹ����
//
//int main(void)
//{
//	char ch;		//�洢��ȡ�����ļ��е��ַ�
//	FILE * fp;		//�ļ�ָ��
//	char filename[50];		//�ַ����飬�洢�ļ�����
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
//	fclose(fp);		//�ر��ļ�
//	return 0;
//}