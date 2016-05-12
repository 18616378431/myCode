//函数参数指向结构的指针
#include<stdio.h>
#include<string.h>//strlen()
#define LEN 20

struct namect{
	char fname[LEN];
	char lname[LEN];
	size_t letters;
};

void getInfo(struct namect * pst);
void makeInfo(struct namect * pst);
void showInfo(const struct namect * pst);

int main()
{
	struct namect person;

	getInfo(&person);
	makeInfo(&person);
	showInfo(&person);
	return 0;
}
void getInfo(struct namect * pst)
{
	puts("Enter your first name:");
	gets(pst->fname);
	puts("Enter your last name:");
	gets(pst->lname);
}
void makeInfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showInfo(const struct namect * pst)
{
	printf("%s %s,there is %d letters in your name.\n",pst->fname,pst->lname,pst->letters);
}
