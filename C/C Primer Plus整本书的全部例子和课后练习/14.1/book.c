//ͼ��Ŀ¼,���������ߣ��۸�
#include<stdio.h>
#define TITLE 41
#define AUTHOR 31

struct book{//�ṹģ�壬���Ϊbook
	char title[TITLE];
	char author[AUTHOR];
	float value;
};//�ṹģ�����

int main()
{
	struct book library;//��library����άbook���ͱ���

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