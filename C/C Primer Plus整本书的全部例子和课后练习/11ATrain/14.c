//ʹ���ַ����ຯ��ʵ��atoi()����
#include<stdio.h>
#include<ctype.h>
#define SIZE 81

int myatoi(const char * s);
int tenN(int n);

int main()
{
	char str[SIZE];
	int integer;

	puts("��������ַ���");
	gets(str);
	integer = myatoi(str);
	
	printf("%s from string to integer is %d.\n",str,integer);
	return 0;
}

int myatoi(const char * s)
{
	int getInt = 0;
	char * p = s;
	int i = 0;
	int k;

	
	if(isdigit(*p))//�����һ���ַ�������
	{
		while(isdigit(*p))
		{
			i++;
			p++;
		}
		//printf("i = %d\n",i);
		p = s;
		for(k = 0;k < i;k++)
		{
			getInt += (*p - '0')*tenN(i - (k + 1));
			p++;
		}
	}
	else
	{
		return 0;
	}
	return getInt;
}
//����10��n�η�
int tenN(int n)
{
	int sum = 1;
	int i;

	for(i = 0;i < n;i++)
	{
		sum *= 10;
	}
	//printf("sum = %d\n",sum);
	return sum;
}