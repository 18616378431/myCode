#include<stdio.h>
#include<stdlib.h>		//Ϊexit()�����ṩ֧��

int main(void)
{
	int ch;
	FILE * fp;
	char fname[50];		//���ڴ���ļ���

	printf("Enter the name of the file: ");
	scanf("%s",&fname);

	fp = fopen(fname,"r");		//���ļ��Թ���ȡ
	if(fp == NULL)		//���Դ��ļ�ʧ��
	{
		printf("Failed to open file.Bye!\n");
		exit(1);		//��ֹ����
	}
	//getc()�Ӵ򿪵��ļ��л�ȡһ���ַ�
	while((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
	fclose(fp);		//�ر��ļ�
	return 0;
}