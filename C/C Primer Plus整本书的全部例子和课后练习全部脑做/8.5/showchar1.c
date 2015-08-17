//#include<stdio.h>
//
//void display(char cr,int lines,int width);
//
//int main(void)
//{
//	int ch;		//要打印的字符
//	int rows,cols;		//打印的行数和列数
//
//	printf("Enter a character and two integer:");
//	while((ch = getchar()) != '\n')
//	{
//		if((scanf("%d%d",&rows,&cols)) != 2)
//		{
//			continue;
//		}
//		display(ch,rows,cols);
//		while(getchar() != '\n')
//		{
//			continue;
//		}
//		printf("Enter another character and two integer:");
//		printf("Enter a new line to quit.\n");
//	}
//	printf("Bye.\n");
//	return 0;
//}
//void display(char cr,int lines,int width)
//{
//	int row,col;
//	for(row=0;row<lines;row++)
//	{
//		for(col=0;col<width;col++)
//		{
//			putchar(cr);
//		}
//		putchar('\n');
//	}
//}