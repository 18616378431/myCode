//结构中使用字符指针,malloc()分配内存,free()释放内存
#include<stdio.h>
#include<string.h>//strcpy()
#include<stdlib.h>//malloc()、free()
#define LEN 81

struct namect{
	char * first;
	char * last;
	size_t letters;
};

void getInfo(struct namect * pst);
void makeInfo(struct namect * pst);
void showInfo(const struct namect * pst);
void cleanUp(struct namect * pst);

int main()
{
	struct namect person;

	getInfo(&person);
	makeInfo(&person);
	showInfo(&person);
	cleanUp(&person);
	return 0;
}
void getInfo(struct namect * pst)
{
	char temp[LEN];

	puts("Enter your first name:");
	gets(temp);
	pst->first = (char *)malloc(strlen(temp) + 1);//为结构中的字符指针分配空间
	strcpy(pst->first,temp);//复制名字
	puts("Enter your last name:");
	gets(temp);
	pst->last = (char *)malloc(strlen(temp) + 1);//分配内存
	strcpy(pst->last,temp);
}
void makeInfo(struct namect * pst)
{
	pst->letters = strlen(pst->first) + strlen(pst->last);
}
void showInfo(const struct namect * pst)
{
	printf("%s %s,there is %d letters in your name.\n",pst->first,pst->last,pst->letters);
}
void cleanUp(struct namect * pst)//释放分配的内存
{
	free(pst->first);
	free(pst->last);
}