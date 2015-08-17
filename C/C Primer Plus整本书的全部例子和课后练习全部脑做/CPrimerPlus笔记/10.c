#include <stdio.h>

int main()
{
	char * name = "Hello World!";
	char * pt;

	pt = pr(name);
	puts(pt);
	return 0;
}

char *pr(char * str)
{
	while(*str != ' ' && *str != '\0')
	{
		str++;
	}
	if(*str == '\0')
		return NULL;
	else
		return str;
}
