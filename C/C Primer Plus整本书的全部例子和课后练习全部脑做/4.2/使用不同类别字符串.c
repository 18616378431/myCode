//��ͬ�����ַ���ʹ��
#include<stdio.h>
#include<string.h>
#define PRAISE "What a good name!"

int main()
{
	char name[40];
	printf("What's your name? \n");
	scanf("%s",name);
	printf("Hello,%s.%s \n",name,PRAISE);
	//�����嵥4.3
	printf("Your name of %d letters occupies %d memory cells! \n",strlen(name),sizeof name);
	printf("The phrase of praise has %d letters and occupies %d memory cells. \n",strlen(PRAISE),sizeof PRAISE);
	return 0;
}