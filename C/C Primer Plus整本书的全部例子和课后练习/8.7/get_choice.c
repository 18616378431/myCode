#include<stdio.h>

//��������
char get_choice(void);		//��ȡѡ��Ĳ˵���
char get_first(void);		//��ȡһ�еĵ�һ���ַ�
void count(void);		//cѡ��ļ�������
int get_int();		//��ȡһ������

int main(void)
{
	int choice;

	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
		case 'a':
			printf("Buy low,sel high!\n");
			break;
		case 'b':
			putchar('\a');
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
//����a,b,c,q
char get_choice(void)
{
	int ch;
	printf("Enter the letter of your choice:\n");
	printf("a.advice\tb.bell\nc.count\t\tq.quit\n");
	ch = get_first();
	while(ch < 'a' || ch > 'c' && ch != 'q')
	{
		printf("Please response a,b,c or q.\n");
		ch = get_first();
	}
	return ch;
}
//ֻ��ȡһ�еĵ�һ���ַ������������ַ�
char get_first(void)
{
	char cr;		//�洢�û������ַ�
	
	while((cr = getchar()) == ' ' || cr == '\n')
	{
		continue;
	}
	/*if(cr == '\n')
	{
		cr = getchar();
	}
	else
	{
		;
	}*/
	while(getchar() != '\n')		//��������ʣ�ಿ��
	{
		continue;
	}
	return cr;
}
//����
void count(void)
{
	int n,i;

	n = get_int();
	for(i=1;i<=n;i++)
	{
		printf("%d.\n",i);
	}
	//while(getchar() != '\n')		//����scanf()��ȡ����Ĳ���\n�ַ�
	//{
	//	continue;
	//}
}
//��ȡһ������
int get_int()
{
	int input;
	char ch;		//�洢�����ַ�
	
	printf("Count how far?Enter an integer:");
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.Please try again.\n");
	}
	return input;
}