////结构数组
//#include<stdio.h>
//#include<string.h>
//#define TITLE 41
//#define AUTHOR 31
//#define MAXBKS 100
//
//struct book{//结构模板
//	char title[TITLE];
//	char author[AUTHOR];
//	float value;
//};
//
//void titleUp(struct book * ps,int ct);
//void valueUp(struct book * ps,int ct);
//void show(struct book * ps,int ct);
//
//int main()
//{
//	struct book library[MAXBKS];//结构数组
//	int index;
//	int count = 0;
//	struct book * ps = library;
//
//	puts("Enter title:");
//	while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
//	{
//		puts("Enter author:");
//		gets(library[count].author);
//		puts("Enter price:");
//		scanf("%f",&library[count++].value);
//		while(getchar() != '\n')
//			continue;
//		if(count < MAXBKS)
//			puts("Enter the next book(Enter to quit):");
//	}
//	if(count > 0)
//	{
//		puts("Here is your books list:");
//		for(index = 0;index < count;index++)
//		{
//			printf("%s by %s:$%.2f.\n",library[index].title,library[index].author,library[index].value);
//		}
//	}
//	else
//	{
//		puts("No book!");
//	}
//	titleUp(ps,count);
//	valueUp(ps,count);
//	return 0;
//}
////按标题字母升序输出
//void titleUp(struct book * ps,int ct)
//{
//	int i,j;
//	struct book temp;
//
//	for(i = 0;i < ct - 1;i++)
//	{
//		for(j = i + 1;j < ct;j++)
//		{
//			if(strcmp(ps[i].title,ps[j].title) > 0)
//			{
//				temp = ps[i];
//				ps[i] = ps[j];
//				ps[j] = temp;
//			}
//		}
//	}
//	puts("Order by title:");
//	show(ps,ct);
//}
////按价格升序排序
//void valueUp(struct book * ps,int ct)
//{
//	int i,j;
//	struct book temp;
//
//	for(i = 0;i < ct - 1;i++)
//	{
//		for(j = i + 1;j < ct;j++)
//		{
//			if(ps[i].value > ps[j].value)
//			{
//				temp = ps[i];
//				ps[i] = ps[j];
//				ps[j] = temp;
//			}
//		}
//	}
//	puts("Order by value:");
//	show(ps,ct);
//}
//
//void show(struct book * ps,int ct)
//{
//	int i;
//
//	for(i = 0;i < ct;i++)
//	{
//		printf("%s by %s:$%.2f.\n",ps[i].title,ps[i].author,ps[i].value);
//	}
//}