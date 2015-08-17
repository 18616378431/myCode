//反向显示命令行参数
//#include<stdio.h>
//
//int main(int argc,char *argv[])
//{
//	int i;
//	char * temp;
//
//	printf("argc = %d\n",argc);
//	for(i = 1;i < argc - i;i++)
//	{
//		temp = argv[i];
//		argv[i] = argv[argc - i];
//		argv[argc - i] = temp;
//	}
//	for(i = 1;i < argc;i++)
//	{
//		printf("%s ",argv[i]);
//	}
//	return 0;
//}