//��������������hashɢ�о���
#include<stdio.h>
#include"interface.h"

//�ֲ�����
char Menu();
void delMore();
void InsertItem(HashList hl);
void SearchItem(HashList hl);
void DeleteItem(HashList hl);

int main()
{
	HashList hl;
	char choose;

	InitHashList(hl);
	while((choose = Menu()) != 'd')
	{
		switch(choose)
		{
		case 'a'://��������
			InsertItem(hl);
			break;
		case 'b'://��ѯ����
			SearchItem(hl);
			break;
		case 'c'://ɾ������
			DeleteItem(hl);
			break;
		default:
			puts("������a��b��c������ѡ�����");
			break;
		}
	}
	ClearHashList(hl);
	return 0;
}
//��ʾ�˵�����ȡ�û�ѡ��
char Menu()
{
	char ch;

	puts("==========================================");
	puts("a.����������������\tb.��ѯ������������");
	puts("c.ɾ��ָ�������������\td.�˳�");
	puts("==========================================");
	ch = getchar();
	delMore();
	return ch;
}
//���������ʣ����
void delMore()
{
	while(getchar() != '\n')
		continue;
}
//��������
void InsertItem(HashList hl)
{
	Item item;

	puts("�����������������:");
	puts("please enter the car id:");
	scanf("%d",&item.carId);
	delMore();
	puts("please enter the trade mark:");
	gets(item.tradeMark);
	if(!InsertItemIntoHashList(hl,item))
	{
		puts("����ʧ��");
	}
	else
	{
		puts("����ɹ�");
	}
}
//��ѯ����
void SearchItem(HashList hl)
{
	Item item;
	int result;

	puts("������Ҫ��ѯ�ĳ��ƺ�:");
	scanf("%d",&item.carId);
	delMore();
	result = LocateItemFromHashList(hl,item);
	if(result != -1)
	{
		printf("���ҳɹ�,����λ��Ϊ%d!.\n",result);
	}
	else
	{
		puts("����ʧ��!");
	}
}
//ɾ������
void DeleteItem(HashList hl)
{
	Item item;

	puts("������Ҫɾ���ĳ��ƺ�:");
	scanf("%d",&item.carId);
	delMore();
	DeleteItemFromHashList(hl,item);
}