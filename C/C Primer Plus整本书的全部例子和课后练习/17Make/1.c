////修改17.2，可以双向遍历列表，可以正序显示列表，也可以倒序显示列表，方法一:修改链表定义，方法二:递归
////记录看电影名称和评价
////修改，动态内存分配
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define TSIZE 45
////#define FMAX 5
//
//typedef struct film{
//	char title[TSIZE];
//	int rating;
//	struct film * above;
//	struct film * next;
//} FILM;
//
//typedef struct node{
//	FILM * head;
//	FILM * end;
//	int size;
//}Node;
//
//void delMore();
//void showList(FILM * ps);
//void freeList(FILM * ps);
//
//void backShowList(FILM * ps);
//void changeShowList(int size,FILM * last);
//
//int main()
//{
//	FILM * head = NULL;//头指针，指向链表的头部
//	FILM * prev,*current;//前一个结构的指针和当前结构指针
//	Node * node;
//	char input[TSIZE];
//
//	node = (Node *)malloc(sizeof(Node));
//	node->size = 0;
//	puts("Enter the first film title:");
//	while(gets(input) != NULL && input[0] != '\0')
//	{
//		current = (FILM *)malloc(sizeof(FILM));
//		if(head == NULL)
//		{
//			head = current;
//			node->head = current;
//		}
//		else
//		{
//			prev->next = current;
//			current->above = prev;
//		}
//		node->end = current;
//		node->end->next = NULL;
//		current->next = NULL;
//		strcpy(current->title,input);
//		puts("Enter your rating(0-10):");
//		scanf("%d",&current->rating);
//		delMore();
//		prev = current;//记录前一个结构
//		node->size++;
//		puts("Enter the next movie(empty line to quit):");
//	}
//	if(head == NULL)
//		puts("Too bad!No data!");
//	else
//		puts("Here is the movies list:");
//	//show
//	current = head;
//	//showList(current);
//	
//	//方法二:递归实现倒序输出列表
//	//backShowList(current);
//
//	//方法一:修改列表定义实现倒序输出
//	changeShowList(node->size,node->end);
//
//	puts("Free!");
//	current = head;
//	freeList(current);
//	puts("Bye!");
//	return 0;
//}
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}
//void showList(FILM * ps)
//{
//	while(ps != NULL)
//	{
//		printf("Movies:%-9s rating:%-5d\n",ps->title,ps->rating);
//		ps = ps->next;
//	}
//}
//void freeList(FILM * ps)
//{
//	FILM * nt;
//
//	while(ps != NULL)
//	{
//		nt = ps->next;
//		free(ps);
//		ps = nt;
//	}
//}
////方法二:递归方法倒序显示列表
//void backShowList(FILM * ps)
//{
//	if(ps != NULL)
//	{
//		backShowList(ps->next);
//		printf("Movies:%-9s rating:%-5d\n",ps->title,ps->rating);
//	} 
//}
////方法一:修改列表定义，倒序输出列表
//void changeShowList(int size,FILM * last)
//{
//	FILM * temp = last;
//
//	while(size-- > 0)
//	{
//		printf("Movies:%-9s rating:%-5d\n",temp->title,temp->rating);
//		temp = temp->above;
//	}
//}