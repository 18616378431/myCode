//图书目录,书名，作者，价格
#include<stdio.h>
#define TITLE 41
#define AUTHOR 31

struct book{//结构模板，标记为book
	char title[TITLE];
	char author[AUTHOR];
	float value;
};//结构模板结束

int main()
{
	struct book library;//将library声明维book类型变量

	puts("Enter the book title:");
	gets(library.title);
	puts("Enter the book's author:");
	gets(library.author);
	puts("Enter the price of the book:");
	scanf("%f",&library.value);
	printf("%s by %s :$%.2f.\n",library.title,library.author,library.value);
	printf("%s:\"%s\"($%.2f).\n",library.author,library.title,library.value);
	return 0;
}