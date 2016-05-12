#include<stdio.h>

int main(void)
{
	int guess = 1;
	char response;

	printf("I'll guess a number that appear in your brain!\n");
	printf("If it's right please type in 'y' or flase to 'n'\n");
	printf("Now it's %d?\n",guess);

	while((response = getchar()) != 'y')
	{
		if(response == 'n')
		{
			printf("It's %d?\n",++guess);
		}
		else
		{
			printf("Sorry,I understand only y or n.\n");
		}
		while(getchar() != '\n')		//跳过输入行的剩余部分
		{
			continue;
		}
	}
	printf("Ok,I konw I could do it!\n");
	return 0;
}