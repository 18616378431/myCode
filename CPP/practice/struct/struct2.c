//��̬����
#include<stdio.h>
#include<stdlib.h>

struct weapon{
	int price;
	int attack;
	struct weapon *next;
};

struct weapon *create();

int main(int argc,char *argv[])
{
	struct weapon *p,*p1;
	p = create();
	while(p != NULL)
	{
		printf("%d,%d\n",p->price,p->attack);
		p = p->next;
	}
	
	return 0;
}
struct weapon *create()
{
	struct weapon *head,*p1,*p2;//ͷָ�롢�½ڵ㡢��һ���ڵ�
	int n = 0;
	p1 = p2 = (struct weapon *)malloc(sizeof(struct weapon));
	scanf("%d,%d",&p1->price,&p1->attack);

	head = NULL;
	while(p1->price != 0)
	{
		n++;
		if(n == 1)
		{
			head = p1;
		}else{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct weapon *)malloc(sizeof(struct weapon));
		scanf("%d,%d",&p1->price,&p1->attack);
	}
	p2->next = NULL;
	return head;
}