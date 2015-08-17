//结构数组
#include<stdio.h>
#define TITLE 41
#define AUTHOR 31
#define MAXBKS 100

struct book{//结构模板
	char title[TITLE];
	char author[AUTHOR];
	float value;
};

int main()
{
	struct book library[MAXBKS];//结构数组
	int index;
	int count = 0;

	puts("Enter title:");
	while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
	{
		puts("Enter author:");
		gets(library[count].author);
		puts("Enter price:");
		scanf("%f",&library[count++].value);
		while(getchar() != '\n')
			continue;
		if(count < MAXBKS)
			puts("Enter the next book(Enter to quit):");
	}
	if(count > 0)
	{
		puts("Here is your books list:");
		for(index = 0;index < count;index++)
		{
			printf("%s by %s:$%.2f.\n",library[index].title,library[index].author,library[index].value);
		}
	}
	else
	{
		puts("No book!");
	}
	return 0;
}