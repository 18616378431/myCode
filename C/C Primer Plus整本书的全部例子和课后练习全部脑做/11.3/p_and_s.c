#include<stdio.h>

int main()
{
	char *mesg = "Don't be a fool!";
	char *copy;

	copy = mesg;
	printf("%s\n",copy);
	printf("mesg = %s,&mesg = %p,value = %p\n",mesg,&mesg,mesg);
	printf("copy = %s,&copy = %p,value = %p\n",copy,&copy,copy);

	//mesg和copy指向同一个字符串的首地址
	return 0;
}