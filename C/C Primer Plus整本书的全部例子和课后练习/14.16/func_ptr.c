//函数指针，函数:声明、定义、调用、作为指针
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
	void (* pfun)(char *);//指向函数的指针,参数类型为char *,返回值为void
	char choice;//存储用户选择
	
	puts("Enter a string:");
	while(gets(line) != NULL && line[0] != '\0')
	{
		while((choice = showMenu()) != 'n')
		{
			switch(choice)//设置函数指针
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy(copy,line);//创建副本，保留原始字符串
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
//剔除行内多余字符
void eatline(void)
{
	while(getchar() != '\n')
		continue;
}
//调用参数传递过来的函数指针并显示结果
void show(void (*pf)(char *),char * str)
{
	(*pf)(str);//价格用户选择的函数作用于str
	puts(str);//显示
}
//转换为大写
void ToUpper(char * str)
{
	while(*str != '\0')
	{
		*str = toupper(*str);
		str++;
	}
}
//转换为小写
void ToLower(char * str)
{
	while(*str != '\0')
	{
		*str = tolower(*str);
		str++;
	}
}
//大小写转置
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
//不改变字符串
void Dummy(char * str)
{
	
}