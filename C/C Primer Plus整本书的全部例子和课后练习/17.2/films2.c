//��¼����Ӱ���ƺ�����
//�޸ģ���̬�ڴ����
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
	FILM * head = NULL;//ͷָ�룬ָ�������ͷ��
	FILM * prev,*current;//ǰһ���ṹ��ָ��͵�ǰ�ṹָ��
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
		prev = current;//��¼ǰһ���ṹ
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