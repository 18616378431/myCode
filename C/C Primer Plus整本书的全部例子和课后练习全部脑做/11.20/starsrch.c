#include<stdio.h>
#include<string.h>//strncmp()函数，可以比较到字符串的不同位置，也可以比较到由第三个参数指定的字符数
#define LISTSIZE 5

int main()
{
	char * list[LISTSIZE] = {
		"astronomy",
		"astounding",
		"astrophysics",
		"ostracize",
		"asterism"
	};
	int count = 0;
	int i;

	for(i = 0;i < LISTSIZE;i++)
	{
		if(strncmp(list[i],"astro",5) == 0)
		{
			printf("Found %s\n",list[i]);
			count++;
		}
	}
	printf("The list contained %d words begining with astro.\n",count);

	return 0;
}