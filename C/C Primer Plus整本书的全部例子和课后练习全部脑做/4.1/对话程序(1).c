#include<stdio.h>
#include<string.h>//��strlen������֧��
#define DENSITY 62.6f//�����ܶ�

int main()
{
	float weight,volume;//�������ܶ�
	int size,letters;//�ַ�����С��������ĸ��
	char name[40];//��40���ַ�������

	printf("Hi!what's your first name? \n_____\b\b\b\b\b");
	scanf("%s",name);
	printf("%s,What's your weight in pounds? \n",name);
	scanf("%f",&weight);
	volume=weight/DENSITY;
	size=sizeof name;
	letters=strlen(name);
	printf("Volume is %.2f \n",volume);
	printf("There is %d letters in your name! \n",letters);
	printf("And we have %d bytes to store it in! \n",size);
	return 0;
}