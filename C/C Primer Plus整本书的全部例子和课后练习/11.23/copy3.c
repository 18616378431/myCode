#include<stdio.h>
#include<string.h>
//strcpy(target,source)不检查目标字符串是否可以容纳源字符串
#define TARGSIZE 7
//strncpy(target,source,n)需要第三个参数来指定最大可复制的字符数
#define LIM 5
#define SIZE 40

int main()
{
	char qword[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;

	printf("Enter %d words begining with q:\n",LIM);
	while(i < LIM && gets(temp))
	{
		if(temp[0] != 'q')
		{
			printf("%s doesn't begin with q!\n",temp);
		}
		else
		{
			strncpy(qword[i],temp,TARGSIZE - 1);
			qword[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("Here are the words accepted:");
	for(i = 0;i < LIM;i++)
	{
		puts(qword[i]);
	}
	return 0;
}