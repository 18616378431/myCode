////静态链表
//#include<stdio.h>
//
//struct weapon{
//	int price;
//	int attack;
//	struct weapon *next;
//};
//
//int main()
//{
//	struct weapon a,b,c,*head;
//	//访问节点p
//	struct weapon *p;
//
//	a.price = 100;
//	a.attack = 100;
//	b.price = 200;
//	b.attack = 200;
//	c.price = 300;
//	c.attack = 300;
//	
//	head = NULL;
//	
//	head = &a;
//	a.next = &b;
//	b.next = &c;
//	c.next = NULL;
//
//	p = head;
//
//	while(p != NULL)
//	{
//		printf("%d,%d\n",p->price,p->attack);
//		p = p->next;
//	}
//	return 0;
//}