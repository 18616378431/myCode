//�ṹ��ʹ���ַ�ָ��,malloc()�����ڴ�,free()�ͷ��ڴ�
#include<stdio.h>
#include<string.h>//strcpy()
#include<stdlib.h>//malloc()��free()
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
	pst->first = (char *)malloc(strlen(temp) + 1);//Ϊ�ṹ�е��ַ�ָ�����ռ�
	strcpy(pst->first,temp);//��������
	puts("Enter your last name:");
	gets(temp);
	pst->last = (char *)malloc(strlen(temp) + 1);//�����ڴ�
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
void cleanUp(struct namect * pst)//�ͷŷ�����ڴ�
{
	free(pst->first);
	free(pst->last);
}