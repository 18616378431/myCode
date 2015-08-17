//#include<stdio.h>
//
//char get_first();
//
//int main(void)
//{
//	char ch;
//	printf("Enter a letter:\n");
//	ch = get_first();
//
//	putchar(ch);
//	putchar('\n');
//	return 0;
//}
//
//char get_first()
//{
//	char cr;
//	char sp;		//´æ´¢¿Õ°××Ö·û
//	
//	while((sp = getchar()) == ' ')
//		continue;
//	cr = sp;
//	while(getchar() != '\n')		//Ìø¹ıÊ£Óà²¿·Ö
//		continue;
//	return cr;
//}