#include<stdio.h>
#include<ctype.h>		//为isspace()提供函数原型
#define bool int
#define TRUE 1
#define FALSE 0
#define STOP '|'

int main(void)
{
	char c;		//读入字符
	char prev;		//前一个读入字符
	long n_chars = 0L;		//字符数
	int n_lines = 0;		//行数
	int n_words = 0;	//单词数
	int p_lines = 0;	//不完整行数
	bool inword = FALSE;	//c在一个单词中，inword为true
	int hh = 0;		//统计换行符个数'\n'

	printf("Enter next to be analyzed(| to termate): \n");
	prev = '\n';		//用于识别完整的行
	while((c = getchar()) != STOP)
	{
		if(c != ' ')		//c不为空白字符时，字符数增加
		{
			n_chars++;		//统计字符
		}
		if(c == '\n')
		{
			hh += 1;
			n_lines++;//统计行
		}
		if(!isspace(c) && !inword)		//c为字符'w',isspace()为假，!isspace()为真
		{
			inword = TRUE;		//开始一个新单词
			n_words++;		//统计单词
		}
		if(isspace(c) && inword)		//读入的字符c为空格，换行或制表符时，isspace()为真
		{
			inword = FALSE;		//达到单词尾部
			prev = c;		//如果尾部字符不为'\n',则将字符保存在prev中
		}
	}
	if(prev != '\n')		//保存的尾部字符不为'\n'时，则产生一个不完整行
	{
		p_lines = 1;
	}

	printf("characters = %ld,words = %d,lines = %d,",n_chars - hh,n_words,n_lines);
	printf("partial lines = %d.\n",p_lines);
	return 0;
}