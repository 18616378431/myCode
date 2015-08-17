////读取10个字符或EOF
////五个选项:
////1.输出初始字符串列表
////2.按ASCII顺序输出字符串
////3.按长度递增输出字符串
////4.按字符串中第一个单词的长度输出字符串
////5.退出
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
//#define LIM 11
//#define SIZE 81
//
//int getStr(char s[LIM][SIZE],int n,char * p[LIM]);
//int showMenu();
//void showIt(char * p[LIM],int n);
//void showAsc(char *p[LIM],int n);
//void showStrLength(char *p[LIM],int n);
//void showStrLengthOne(char *p[LIM],int n);
//
////main进行流程控制
//int main()
//{
//	char str[LIM][SIZE];
//	char * ptstr[LIM];//指针数组
//	int i = 0;
//	int choice = 0;
//
//	puts("*************请输入要处理的字符串*************");
//	//获取字符串
//	i = getStr(str,i,ptstr);
//	//菜单选项
//	choice = showMenu();
//	switch(choice)
//	{
//	case 1://1.输出初始字符串列表
//		showIt(ptstr,i);
//		break;
//	case 2://2.按ASCII顺序输出字符串
//		showAsc(ptstr,i);
//		break;
//	case 3://3.按长度递增输出字符串
//		showStrLength(ptstr,i);
//		break;
//	case 4://4.按字符串中第一个单词的长度输出字符串
//		showStrLengthOne(ptstr,i);
//		break;
//	case 5:
//		return 0;
//		break;
//	default:
//		puts("您没有选择一个正确的选项");
//		main();
//		break;
//	}
//	puts("*************操作结束*************");
//	return 0;
//}
////获取字符串,并且将每个字符串首地址赋给指针数组
//int getStr(char s[LIM][SIZE],int n,char * p[LIM])
//{
//	while(gets(s[n]) && s[n][0] != '\0' && n < LIM - 1)
//	{
//		p[n] = s[n];
//		n++;
//	}
//	return n;
//}
////菜单选项
//int showMenu()
//{
//	int choose;
//
//	puts("*************输入选项数字执行操作*************");
//	puts("1.输出原始字符串列表\t2.按ASCII顺序输出字符串");
//	puts("3.按长度递增输出字符串\t4.按字符串中第一个单词的长度输出字符串");
//	puts("5.回车或Q退出");
//	puts("*************输入选项数字执行操作*************");
//	scanf("%d",&choose);//剩余一个换行符在内存中
//	while(getchar() != '\n')
//	{
//		continue;
//	}
//	puts("*************执行操作*************");
//	return choose;
//}
////1.输出初始字符串列表
//void showIt(char *p[LIM],int n)
//{
//	int k;
//	for(k = 0;k < n;k++)
//	{
//		puts(p[k]);
//	}
//}
////2.按ASCII顺序输出字符串,只给指针排序，初始字符串未变化
//void showAsc(char *p[LIM],int n)
//{
//	char * temp;
//	int top,seek;
//
//	for(top = 0;top < n - 1;top++)
//	{
//		for(seek = top + 1;seek < n;seek++)
//		{
//			if(strcmp(p[top],p[seek]) > 0)
//			{
//				temp = p[top];
//				p[top] = p[seek];
//				p[seek] = temp;
//			}
//		}
//	}
//	showIt(p,n);
//}
////3.按长度递增输出字符串,按长度大小重新排序指针数组
//void showStrLength(char *p[LIM],int n)
//{
//	char * temp;
//	int top,seek;
//
//	for(top = 0;top < n - 1;top++)
//	{
//		for(seek = top + 1;seek < n;seek++)
//		{
//			if(strlen(p[top]) > strlen(p[seek]))
//			{
//				temp = p[top];
//				p[top] = p[seek];
//				p[seek] = temp;
//			}
//		}
//	}
//	showIt(p,n);
//}
////4.按字符串中第一个单词的长度输出字符串
//void showStrLengthOne(char *p[LIM],int n)
//{
//	int i;
//	int k;
//
//	char * temp;
//	int top,seek;
//
//	int ct = 0;//空白字符计数
//
//	for(i = 0;i < n;i++)
//	{
//		k = 0;
//		while(p[i][k] != '\0')
//		{
//			if(p[i][k] == ' ')
//			{
//				p[i][k] = '\0';
//				break;
//			}
//			k++;
//		}
//	}
//	//按字符串长度进行排序
//	for(top = 0;top < n - 1;top++)
//	{
//		for(seek = top + 1;seek < n;seek++)
//		{
//			if(strlen(p[top]) > strlen(p[seek]))
//			{
//				temp = p[top];
//				p[top] = p[seek];
//				p[seek] = temp;
//			}
//		}
//	}
//	//将替换掉的'\0'，替换回原来的空白符
//	for(i = 0;i < n;i++)
//	{
//		k = 0;
//		while(p[i][k] != ' ')
//		{
//			if(p[i][k] == '\0' && k != strlen(p[i]))
//			{
//				p[i][k] = ' ';
//				break;
//			}
//			ct++;
//			k++;
//		}
//	}
//	showIt(p,n);
//}

//int first_word_length(char * p)
//{
//	int i = 0;
//
//	for(;!isalpha(*p);p++)
//	{
//		if(*p == '\0')
//		{
//			return 0;
//		}
//	}
//	for(i = 1;isalpha(p[i]);i++)
//	{
//		continue;
//	}
//	return i;
//}
//
//void word_put(char **p,int n)
//{
//	int i,j;
//	char *temp;
//
//	//根据函数first_word_length()返回的第一个单词长度，排列指针数组
//	for(i = 0;i < n - 1;i++)
//	{
//		for(j = i + 1;j < n;j++)
//		{
//			if(first_word_length(p[i]) > first_word_length(p[j]))
//			{
//				temp = p[i];
//				p[i] = p[j];
//				p[j] = temp;
//			}
//		}
//	}
//	showIt(p,n);
//}