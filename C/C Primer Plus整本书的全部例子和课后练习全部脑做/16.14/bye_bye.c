//exit()��atexit()
#include<stdio.h>
#include<stdlib.h>

void sign_off(void);
void too_bad(void);

int main()
{
	int n;

	atexit(sign_off);//��exit����ִ���б�����Ӻ���
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