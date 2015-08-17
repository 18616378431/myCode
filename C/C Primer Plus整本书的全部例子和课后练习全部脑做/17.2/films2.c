//记录看电影名称和评价
//修改，动态内存分配
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
//#define FMAX 5

typedef struct film{
	char title[TSIZE];
	int rating;
	struct film * next;
} FILM;

void delMore();
void showList(FILM * ps);
void freeList(FILM * ps);

int main()
{
	FILM * head = NULL;//头指针，指向链表的头部
	FILM * prev,*current;//前一个结构的指针和当前结构指针
	char input[TSIZE];
	
	puts("Enter the first film title:");
	while(gets(input) != NULL && input[0] != '\0')
	{
		current = (FILM *)malloc(sizeof(FILM));
		if(head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title,input);
		puts("Enter your rating(0-10):");
		scanf("%d",&current->rating);
		delMore();
		prev = current;//记录前一个结构
		puts("Enter the next movie(empty line to quit):");
	}
	if(head == NULL)
		puts("Too bad!No data!");
	else
		puts("Here is the movies list:");
	current = head;
	showList(current);
	puts("Free!");
	current = head;
	freeList(current);
	puts("Bye!");
	return 0;
}
void delMore()
{
	while(getchar() != '\n')
		continue;
}
void showList(FILM * ps)
{
	while(ps != NULL)
	{
		printf("Movies:%-9s rating:%-5d\n",ps->title,ps->rating);
		ps = ps->next;
	}
}
void freeList(FILM * ps)
{
	FILM * nt = (FILM *)malloc(sizeof(FILM));

	while(ps != NULL)
	{
		nt->next = ps->next;
		free(ps);
		ps = nt->next;
	}
	free(nt);
}