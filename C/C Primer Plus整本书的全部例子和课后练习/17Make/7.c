////�򿪲���ȡ�ı��ļ���ͳ���ļ���ÿ�����ʵĳ��ֵĴ������ö����������洢���ʼ�����
////����������ѡ�1.�г����ѵ��ʼ����ִ�����2.����һ�����ʣ�����õ������ļ��г��ֵĴ���3.�˳�
//#include<stdio.h>
//#include<stdlib.h>
//#include"7tree.h"
//
//void createFile();
//void delMore();
//char menu();
//void show(Item item);
//
//int main()
//{
//	FILE * fp;
//	Item item;
//	Tree ptree;
//	char ch;
//	
//	//createFile();
//	InitalizeTree(&ptree);
//	if((fp = fopen("wordtree","r")) == NULL)
//	{
//		fprintf(stderr,"Failing opening file.\n");
//		exit(1);
//	}
//	while(fscanf(fp,"%s",item.word) != EOF)
//	{
//		if(TreeIsFull(&ptree))
//		{
//			puts("Tree is full");
//		}
//		else
//		{
//			AddItem(&item,&ptree);
//		}
//	}
//	while((ch = menu()) != 'q')
//	{
//		switch(ch)
//		{
//		case 'a':
//			Traverse(&ptree,show);
//			break;
//		case 'b':
//			puts("Enter a word that you want to know:");
//			gets(item.word);
//			if(InTree(&item,&ptree))
//			{
//				puts("InTree");
//				searchNode(&ptree,item);
//			}
//			else
//			{
//				puts("The word is not exists!");
//			}
//			break;
//		default:
//			puts("error input ,type in such as a b or q:");
//			break;
//		}
//	}
//	return 0;
//}
//char menu()
//{
//	char ch;
//
//	puts("=========================================================================");
//	puts("Enter your choice:");
//	puts("a)list the word and times\tb)enter an word and show its times\tq)quit");
//	puts("=========================================================================");
//	ch = getchar();
//	delMore();
//	return ch;
//}
//void createFile()
//{
//	char word[10][30] = {"tree","tree","where","how","name","how","good","nice","tree"};
//	FILE * fp;
//	int i;
//
//	if((fp = fopen("wordtree","w")) == NULL)
//	{
//		fprintf(stderr,"Can't create file \"wordtree\"\n");
//		exit(1);
//	}
//	for(i = 0;i < MAXITEM;i++)
//	{
//		fprintf(fp,"%s ",word[i]);
//	}
//	if(fclose(fp) != 0)
//	{
//		fprintf(stderr,"Failing closing file.\n");
//	}
//}
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}
////��ʾ���м���Ԫ������
//void show(Item item)
//{
//	printf("word:%s,times:%d.\n",item.word,item.ct);
//}