//#include<stdio.h>
//#include<stdlib.h>
//#include"3list.h"
//
//void showMovies(Item item);
//void delMore();
//
//int main()
//{
//	List movies;
//	Item item;
//
//	//��ʼ��
//	InitializeList(&movies);
//	if(ListIsFull(&movies))
//	{
//		fprintf(stderr,"No memory available!Bye!\n");
//		exit(1);
//	}
//	//�ռ����ݲ��洢
//	puts("Enter first movie title:");
//	while(gets(item.title) != NULL && item.title[0] != '\0')
//	{
//		puts("Enter your rating(0-10):");
//		scanf("%d",&item.rating);
//		delMore();
//		if(AddItem(item,&movies) == false)
//		{
//			fprintf(stderr,"Problem allocating memory\n");
//			break;
//		}
//		if(ListIsFull(&movies))
//		{
//			puts("The list is full now!");
//			break;
//		}
//		puts("Enter the next movie title(empty line to quit):");
//	}
//	//��ʾ
//	if(ListIsEmpty(&movies))
//	{
//		printf("No data entered!\n");
//	}
//	else
//	{
//		printf("Here is the movie list:\n");
//		Traverse(&movies,showMovies);
//	}
//	printf("You entered %d movies.\n",ListItemCount(&movies));
//	//���
//	EmptyTheList(&movies);
//	puts("Bye!");
//	return 0;
//}
////�������б�ÿһ��ĺ���
//void showMovies(Item item)
//{
//	printf("Movie:%s Rating:%d\n",item.title,item.rating);
//}
////���������������ĩβ
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}