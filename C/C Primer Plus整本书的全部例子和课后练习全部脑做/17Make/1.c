////�޸�17.2������˫������б�����������ʾ�б�Ҳ���Ե�����ʾ�б�����һ:�޸������壬������:�ݹ�
////��¼����Ӱ���ƺ�����
////�޸ģ���̬�ڴ����
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
//	FILM * head = NULL;//ͷָ�룬ָ�������ͷ��
//	FILM * prev,*current;//ǰһ���ṹ��ָ��͵�ǰ�ṹָ��
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
//		prev = current;//��¼ǰһ���ṹ
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
//	//������:�ݹ�ʵ�ֵ�������б�
//	//backShowList(current);
//
//	//����һ:�޸��б���ʵ�ֵ������
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
////������:�ݹ鷽��������ʾ�б�
//void backShowList(FILM * ps)
//{
//	if(ps != NULL)
//	{
//		backShowList(ps->next);
//		printf("Movies:%-9s rating:%-5d\n",ps->title,ps->rating);
//	} 
//}
////����һ:�޸��б��壬��������б�
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