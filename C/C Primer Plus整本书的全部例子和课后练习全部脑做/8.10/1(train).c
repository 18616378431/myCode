//#include<stdio.h>
//#include<stdlib.h>
//
//int main(void)
//{
//	FILE * fp;
//	char ch;
//	char filename[50];
//	int count = 0;
//
//	printf("Enter filename:");
//	scanf("%s",filename);
//	fp = fopen(filename,"r");
//	if(fp == NULL)
//	{
//		printf("Failed to open file.\n");
//		exit(1);
//	}
//	while((ch = getc(fp)) != EOF)
//	{
//		putchar(ch);
//		count++;
//	}
//	printf("letters number is %d.\n",count);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void)
//{
//	char ch;
//	int c = 0;
//
//	while((ch = getchar()) != EOF)
//	{
//		if(ch == '#')
//		{
//			break;
//		}
//		putchar(ch);
//		c++;
//	}
//	printf("\n%d\n",c);
//	return 0;
//}