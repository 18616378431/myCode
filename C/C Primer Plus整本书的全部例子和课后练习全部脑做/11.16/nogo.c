//���û�����Ӧ�����е��ַ����Ƚ�
#include<stdio.h>
#define ANSWER "Grant"

int main()
{
	char try[40];

	puts("Who is buried in Grant's tomb?");
	gets(try);
	while(try != ANSWER)
	{
		puts("No.That is wrong!Try again.");
		gets(try);
	}
	return 0;
}