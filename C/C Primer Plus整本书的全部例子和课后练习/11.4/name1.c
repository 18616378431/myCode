//��ȡһ������
#include<stdio.h>
#define MAX 81

int main()
{
	char name[MAX];//�����ڴ�ռ�
	printf("Hi!What is your name?\n");
	gets(name);//���ַ�������name������
	printf("Nice name,%s\n",name);
	return 0;
}