#include<stdio.h>
#include<string.h>

void fit(char *string,unsigned int size);

int main()
{
	char mesg[] = "Hold on to your hats,hackers.";

	puts(mesg);
	fit(mesg,7);
	puts(mesg);
	puts("Let's look at some more of the string.");
	puts(mesg + 8);
	return 0;
}

//�����ַ������ȵĺ���
void fit(char *string,unsigned int size)//�ı��ַ���
{
	if(strlen(string) > size)
	{
		*(string + size) = '\0';
	}
}