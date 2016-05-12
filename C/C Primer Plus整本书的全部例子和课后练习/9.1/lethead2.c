//#include<stdio.h>
//#include<string.h>		//为strlen()提供原型
//#define NAME "GIGATHINK,INC."
//#define ADDRESS "101 Megabuck Plaza"
//#define PLACE "Megapolis.,CA 94904"
//#define WIDTH 40
//#define SPACE ' '
////函数声明
//void show_n_char(char ch,int num);
//
//int main()
//{
//	int spaces;
//	
//	show_n_char('*',WIDTH);
//	putchar('\n');
//	spaces = (WIDTH - strlen(NAME)) / 2;
//	show_n_char(SPACE,spaces);
//	printf("%s",NAME);
//	putchar('\n');
//	spaces = (WIDTH - strlen(ADDRESS)) / 2;
//	show_n_char(SPACE,spaces);
//	printf("%s",ADDRESS);
//	putchar('\n');
//	spaces = (WIDTH - strlen(PLACE)) / 2;
//	show_n_char(SPACE,spaces);
//	printf("%s",PLACE);
//	putchar('\n');
//	show_n_char('*',WIDTH);
//	putchar('\n');
//	return 0;
//}
//
//void show_n_char(char ch,int num)
//{
//	int count;
//
//	for(count = 1;count <= num;count++)
//		putchar(ch);
//}