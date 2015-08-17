#include<stdio.h>
#include<string.h>//strcpy()为char*类型，返回第一个参数的值;第一个参数不需要指向数组的开始，可以从数组的任何位置开始复制
#define WORDS "beast"
#define SIZE 40

int main()
{
	char * orig = WORDS;
	char copy[SIZE] = "Be the best that you can be!";
	char * ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy+7,orig);
	puts(copy);
	puts(ps);
	return 0;
}