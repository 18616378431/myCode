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
//	char sp;		//�洢�հ��ַ�
//	
//	while((sp = getchar()) == ' ')
//		continue;
//	cr = sp;
//	while(getchar() != '\n')		//����ʣ�ಿ��
//		continue;
//	return cr;
//}