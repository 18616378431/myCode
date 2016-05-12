#include<stdio.h>
#include<string.h>//对strlen函数的支持
#define DENSITY 62.6f//人体密度

int main()
{
	float weight,volume;//重量，密度
	int size,letters;//字符串大小，名字字母数
	char name[40];//有40个字符的数组

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