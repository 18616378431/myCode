////��ȡ10���ַ���EOF
////���ѡ��:
////1.�����ʼ�ַ����б�
////2.��ASCII˳������ַ���
////3.�����ȵ�������ַ���
////4.���ַ����е�һ�����ʵĳ�������ַ���
////5.�˳�
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
////main�������̿���
//int main()
//{
//	char str[LIM][SIZE];
//	char * ptstr[LIM];//ָ������
//	int i = 0;
//	int choice = 0;
//
//	puts("*************������Ҫ������ַ���*************");
//	//��ȡ�ַ���
//	i = getStr(str,i,ptstr);
//	//�˵�ѡ��
//	choice = showMenu();
//	switch(choice)
//	{
//	case 1://1.�����ʼ�ַ����б�
//		showIt(ptstr,i);
//		break;
//	case 2://2.��ASCII˳������ַ���
//		showAsc(ptstr,i);
//		break;
//	case 3://3.�����ȵ�������ַ���
//		showStrLength(ptstr,i);
//		break;
//	case 4://4.���ַ����е�һ�����ʵĳ�������ַ���
//		showStrLengthOne(ptstr,i);
//		break;
//	case 5:
//		return 0;
//		break;
//	default:
//		puts("��û��ѡ��һ����ȷ��ѡ��");
//		main();
//		break;
//	}
//	puts("*************��������*************");
//	return 0;
//}
////��ȡ�ַ���,���ҽ�ÿ���ַ����׵�ַ����ָ������
//int getStr(char s[LIM][SIZE],int n,char * p[LIM])
//{
//	while(gets(s[n]) && s[n][0] != '\0' && n < LIM - 1)
//	{
//		p[n] = s[n];
//		n++;
//	}
//	return n;
//}
////�˵�ѡ��
//int showMenu()
//{
//	int choose;
//
//	puts("*************����ѡ������ִ�в���*************");
//	puts("1.���ԭʼ�ַ����б�\t2.��ASCII˳������ַ���");
//	puts("3.�����ȵ�������ַ���\t4.���ַ����е�һ�����ʵĳ�������ַ���");
//	puts("5.�س���Q�˳�");
//	puts("*************����ѡ������ִ�в���*************");
//	scanf("%d",&choose);//ʣ��һ�����з����ڴ���
//	while(getchar() != '\n')
//	{
//		continue;
//	}
//	puts("*************ִ�в���*************");
//	return choose;
//}
////1.�����ʼ�ַ����б�
//void showIt(char *p[LIM],int n)
//{
//	int k;
//	for(k = 0;k < n;k++)
//	{
//		puts(p[k]);
//	}
//}
////2.��ASCII˳������ַ���,ֻ��ָ�����򣬳�ʼ�ַ���δ�仯
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
////3.�����ȵ�������ַ���,�����ȴ�С��������ָ������
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
////4.���ַ����е�һ�����ʵĳ�������ַ���
//void showStrLengthOne(char *p[LIM],int n)
//{
//	int i;
//	int k;
//
//	char * temp;
//	int top,seek;
//
//	int ct = 0;//�հ��ַ�����
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
//	//���ַ������Ƚ�������
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
//	//���滻����'\0'���滻��ԭ���Ŀհ׷�
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
//	//���ݺ���first_word_length()���صĵ�һ�����ʳ��ȣ�����ָ������
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