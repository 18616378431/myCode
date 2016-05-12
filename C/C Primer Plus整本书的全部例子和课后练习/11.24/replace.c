//Ìæ»»fgets()ÖÐµÄ»»ÐÐ·û
#include<stdio.h>
#include<string.h>

int main()
{
	char line[80];
	char * find;

	fgets(line,80,stdin);
	find = strchr(line,'\n');

	if(find)
	{
		*find = '\0';
	}
	return 0;
}