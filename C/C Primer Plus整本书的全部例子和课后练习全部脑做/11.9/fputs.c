#include<stdio.h>
#define MSG "This is a message!"

int main()
{
	//char line[81];

	//gets()�������з���puts()���ʱ���ַ���ĩβ��ӻ��з�
	/*while(gets(line))
		puts(line);*/

	//fgets()��ȡ���з���fputs()���ʱ����ӻ��з�
	/*while(fgets(line,81,stdin))
		fputs(line,stdout);*/

	char string[] = "ahahhahaha";
	char name[] = "This is a name!";

	printf("%s\n",string);
	puts(string);
	printf("Well,%s,%s\n",name,MSG);
	return 0;
}