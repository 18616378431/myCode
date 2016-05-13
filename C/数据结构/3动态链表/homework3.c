//��̬����ʵ����������ϵͳ
#include<stdio.h>
#include<stdlib.h>
#include"home.h"

void showList(Item item);
void delMore();
char menu();
void AddItem(List * plist);
void show(List * plist);
void deleteItem(List * plist);

int main()
{
	List  plist;
	char ch;

	InitalizeList(&plist);
	if (ListIsFull(&plist))
	{
		fprintf(stderr,"List is full!\n");
		exit(EXIT_FAILURE);
	}
	while((ch = menu()) != 'q')
	{
		switch(ch)
		{
		case 'a':
			AddItem(&plist);
			break;
		case 'd':
			deleteItem(&plist);
			break;
		case 's':
			show(&plist);
			break;
		default:
			puts("Error inputing!");
			break;
		}
	}
	EmptyList(&plist);
	puts("Thanks for using!");
	return 0;
}
//�˵�
char menu()
{
	char ch;

	puts("==============================================");
	puts("a)add item to the list\td)delete item from list");
	puts("s)show list\t\tq)quit");
	puts("==============================================");
	ch = getchar();
	delMore();
	return ch;
}
//���������
void delMore()
{
	while(getchar() != '\n')
		continue;
}
//���б������Ԫ��
void AddItem(List * plist)
{
	Item temp;

	puts("Please input the carid:");
	scanf("%d",&temp.carid);
	delMore();
	puts("Please enter the car's trademark:");
	gets(temp.trademark);
	temp.flag = false;
	if(ListIsFull(plist))
	{
		fprintf(stderr,"List is full!\n");

	}
	else
	{
		if(AddItemToList(&temp,plist) == false)
		{
			fprintf(stderr,"Add item failed!\n");
			exit(EXIT_FAILURE);
		}
	}
}
//��ʾ�б�����
void show(List * plist)
{
	if (ListIsEmpty(plist))
	{
		puts("No data!");
	}
	else
	{
		printf("Here is the car's information:\n");
		Traverse(plist, showList);
	}
	printf("There is %d car in your list.\n", ListItemCount(plist));
}
//ɾ����λԪ��
void deleteItem(List * plist)
{
	DeleteItemFromList(plist);
}
//�����б���
void showList(Item item)
{
	printf("Car id:%d , trademark:%s , using status:%s.\n",item.carid,item.trademark,item.flag?"YES":"NO");
}