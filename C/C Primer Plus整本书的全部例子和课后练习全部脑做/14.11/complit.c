//复合文字和结构,Visual Studio 2005不支持符合文字结构
#include<stdio.h>
#define TITLE 41
#define AUTHOR 31

struct book{
	char title[TITLE];
	char author[AUTHOR];
	float value;
};

int main()
{
	struct book readfirst;
	int score;

	puts("Enter score:");
	scanf("%d",&score);
	if(score >= 84)
	{
		readfirst = (struct book) {"Crime and Punishment","Fyodor Dostoyevsky",9.99};
	}
	else
	{
		readfirst = (struct book) {"Mr.Bouncy's Nice Hat","Fred Winsome",5.99};
	}
	puts("Your assigned reading:");
	printf("%s by %s :$%.2f.\n",readfirst.title,readfirst.author,readfirst.value);
}