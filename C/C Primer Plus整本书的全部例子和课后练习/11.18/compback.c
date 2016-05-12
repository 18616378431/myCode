#include<stdio.h>
#include<string.h>

//strcmp()的返回值，二者相同返回0，第一个参数的ASC||码值减去第二个参数的ASC||码值，大于0，返回1，小于0，返回-1
int main()
{
	//相同
	puts("strcmp(\"A\",\"A\") is");
	printf("%d.\n",strcmp("A","A"));
	//
	puts("strcmp(\"A\",\"B\") is");
	printf("%d.\n",strcmp("A","B"));
	//
	puts("strcmp(\"B\",\"A\") is");
	printf("%d.\n",strcmp("B","A"));
	//
	puts("strcmp(\"C\",\"A\") is");
	printf("%d.\n",strcmp("C","A"));
	//
	puts("strcmp(\"Z\",\"a\") is");
	printf("%d.\n",strcmp("Z","a"));
	//
	puts("strcmp(\"apples\",\"apple\")");
	printf("%d.\n",strcmp("apples","apple"));

	return 0;
}