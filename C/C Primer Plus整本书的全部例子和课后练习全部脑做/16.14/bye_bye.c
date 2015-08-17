//exit()、atexit()
#include<stdio.h>
#include<stdlib.h>

void sign_off(void);
void too_bad(void);

int main()
{
	int n;

	atexit(sign_off);//向exit函数执行列表中添加函数
	if(scanf("%d",&n) != 1)
	{
		puts("There's no integer");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	return 0;
}

void sign_off(void)
{
	puts("Function sign_off");
}
void too_bad(void)
{
	puts("Function too_bad");
}