//#include<stdio.h>
//
//int main(void)
//{
//	char ch;
//	int count = 0;
//
//	while((ch = getchar()) != EOF)
//	{
//		if(ch == '#')
//		{
//			break;
//		}
//		if(ch == '\n')
//		{
//			printf("\\");
//			putchar('n');
//			putchar('\n');
//			continue;
//		}
//		printf("%c %d ",ch,ch);
//		count++;
//		if(count == 10)
//		{
//			printf("\n");
//			count = 0;
//		}
//	}
//	return 0;
//}