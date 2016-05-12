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
//	//初始化
//	InitializeList(&movies);
//	if(ListIsFull(&movies))
//	{
//		fprintf(stderr,"No memory available!Bye!\n");
//		exit(1);
//	}
//	//收集数据并存储
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
//	//显示
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
//	//清除
//	EmptyTheList(&movies);
//	puts("Bye!");
//	return 0;
//}
////作用于列表每一项的函数
//void showMovies(Item item)
//{
//	printf("Movie:%s Rating:%d\n",item.title,item.rating);
//}
////清除多余输入至行末尾
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}