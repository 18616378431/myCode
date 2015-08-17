//打印较长字符串
#include<stdio.h>

int main(void)
{
	printf("This is one way to print a");//使用多个printf函数打印
	printf("long string! \n");

	printf("This is another way to print a \
long string! \n");						//使用反斜杠打印两行连接的字符串

	printf("This is a new way to print a "
		"long string! \n");				//采用字符串连接方法打印多行字符串
	return 0;
}