#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char ch;
	printf("Enter a letter that i will tell you an animal's name.\n");
	printf("Please type in or a '#' to quit!\n");
	while((ch = getchar()) != '#')
	{
		if('\n' == ch)
		{
			continue;
		}
		if(islower(ch))		//只识别小写字母
		{
			switch(ch)
			{
			case 'a':
				printf("argali,a wild sheep of Asia.\n");
				break;
			case 'b':
				printf("babrusia,a wild pig of Malay.\n");
				break;
			case 'c':
				printf("coati,racoonlike mamma.\n");
				break;
			case 'd':
				printf("desman,aquatic,molelike critter.\n");
				break;
			case 'e':
				printf("echidna,the spiny anteater.\n");
				break;
			case 'f':
				printf("fisher,brownish marten.\n");
				break;
			default:
				printf("That is a stumper!\n");
			}
		}
		else
		{
			printf("I recongnize only lowercase letters.\n");
		}
		while(getchar() != '\n')
		{
			continue;		//跳过输入行的剩余部分
		}
		printf("Please type another letter or a '#'.\n");
	}
	printf("Bye.\n");
	return 0;
}