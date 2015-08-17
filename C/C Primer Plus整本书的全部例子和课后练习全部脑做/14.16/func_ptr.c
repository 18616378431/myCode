//����ָ�룬����:���������塢���á���Ϊָ��
#include<stdio.h>
#include<string.h>//strchr()
#include<ctype.h>//toupper()
#define LEN 81

char showMenu(void);
void eatline(void);
void show(void (*pf)(char *),char * str);
void ToUpper(char * str);
void ToLower(char * str);
void Transpose(char * str);
void Dummy(char * str);

int main()
{
	char line[LEN];
	char copy[LEN];
	void (* pfun)(char *);//ָ������ָ��,��������Ϊchar *,����ֵΪvoid
	char choice;//�洢�û�ѡ��
	
	puts("Enter a string:");
	while(gets(line) != NULL && line[0] != '\0')
	{
		while((choice = showMenu()) != 'n')
		{
			switch(choice)//���ú���ָ��
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy(copy,line);//��������������ԭʼ�ַ���
			show(pfun,copy);
		}
		puts("Enter a string:(Empty line to quit)");
	}
	return 0;
}

char showMenu(void)
{
	char ans;

	puts("Enter menu choice");
	puts("u)upper case\tl)lower case");
	puts("t)transposed case\to)original case");
	puts("n)next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while(strchr("ulton",ans) == NULL)
	{
		puts("Please enter a u,l,t,o or n");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}
//�޳����ڶ����ַ�
void eatline(void)
{
	while(getchar() != '\n')
		continue;
}
//���ò������ݹ����ĺ���ָ�벢��ʾ���
void show(void (*pf)(char *),char * str)
{
	(*pf)(str);//�۸��û�ѡ��ĺ���������str
	puts(str);//��ʾ
}
//ת��Ϊ��д
void ToUpper(char * str)
{
	while(*str != '\0')
	{
		*str = toupper(*str);
		str++;
	}
}
//ת��ΪСд
void ToLower(char * str)
{
	while(*str != '\0')
	{
		*str = tolower(*str);
		str++;
	}
}
//��Сдת��
void Transpose(char * str)
{
	while(*str != '\0')
	{
		if(islower(*str))
		{
			*str = toupper(*str);
		}
		else if(isupper(*str))
		{
			*str = tolower(*str);
		}
		str++;
	}
}
//���ı��ַ���
void Dummy(char * str)
{
	
}