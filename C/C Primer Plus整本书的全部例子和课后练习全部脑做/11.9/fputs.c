#include<stdio.h>
#define MSG "This is a message!"

int main()
{
	//char line[81];

	//gets()丢弃换行符，puts()输出时在字符串末尾添加换行符
	/*while(gets(line))
		puts(line);*/

	//fgets()读取换行符，fputs()输出时不添加换行符
	/*while(fgets(line,81,stdin))
		fputs(line,stdout);*/

	char string[] = "ahahhahaha";
	char name[] = "This is a name!";

	printf("%s\n",string);
	puts(string);
	printf("Well,%s,%s\n",name,MSG);
	return 0;
}