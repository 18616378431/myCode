//一个程序中调用两个函数
#include<stdio.h>

void butler(void);

int main(void)
{
	printf("I will show the function that i have created! \n");
	butler();
	printf("Yes,you have saw the function that i have created for you !\n");
	return 0;
}

void butler(void)
{
	printf("The butler shows!! \n");
}