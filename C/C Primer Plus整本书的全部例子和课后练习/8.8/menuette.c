#include<stdio.h>

//��������
char get_choice();		//��ȡ����ѡ��
char get_first();		//��ȡ��һ���ǿ��ַ�
void count(void);		//Cѡ�����
int get_int();		//��ȡ����

int main(void)
{
	int choice;

	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
		case 'a':
			printf("Buy low,sell high!\n");
			break;
		case 'b':
			printf("\a");
			break;
		case 'c':
			count();
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	return 0;
}
//��ȡѡ����
char get_choice()
{
	char ch;
	
	printf("Enter the letter your choice:\n");
	printf("a.advice\tb.bell\n");
	printf("c.count\tq.quit\n");

	ch = get_first();
	while(ch < 'a' || ch > 'c' && ch != 'q')
	{
		printf("Please response with a,b,c or q!\n");
		ch = get_first();
	}
	return ch;
}
//��ȡ��һ���ǿջ���\n���ַ�
char get_first()
{
	char cr;		//��ȡ�ĵ�һ���ǿ��ַ�

	while((cr = getchar()) == ' ' || cr == '\n')		//������Ч����֮ǰ�Ŀհ׷��ͻ��з�
	{
		continue;
	}
	while(getchar() != '\n')		//����ʣ���ַ�
	{
		continue;
	}
	return cr;
}

void count(void)
{
	int n;		//�洢��ȡ����
	int i;		//ѭ���Ͻ�
	
	n = get_int();
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
	}
	//while(getchar() != '\n')		//��������ʣ���ַ�
	//{
	//	continue;
	//}
}
//��ȡһ������
int get_int()
{
	int input;		//�洢��ȷ����
	char ch;		//�洢����������
	
	printf("Count how far?Enter an integer:");
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.\n");
	}

	return input;
}