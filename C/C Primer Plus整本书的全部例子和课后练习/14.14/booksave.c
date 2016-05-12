////将结构内容保存到文件
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#define MAXTITL 41
//#define MAXAUTL 41
//#define MAXBKS 10
//
//struct book{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//};
//
//int main()
//{
//	struct book library[MAXBKS];//结构数组
//	FILE *pbooks;//文件指针
//	int index,filecount;//索引和记录文件中当前的结构数目
//	int count = 0;
//	int size = sizeof(struct book);//book模板的大小
//
//	//打开文件
//	if((pbooks = fopen("book.dat","ab+")) == NULL)
//	{
//		fputs("Can not open file\"book.dat\".\n",stderr);
//		exit(EXIT_FAILURE);
//	}
//	rewind(pbooks);//将文件指针定位到文件开始处
//	//遍历当前文件
//	while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
//	{
//		if(count == 0)
//		{
//			puts("Current contents of book.dat");
//		}
//		printf("%s by %s:$%.2f.\n",library[count].title,library[count].author,library[count].value);
//		count++;
//	}
//	filecount = count;//记录文件中当前的结构体个数
//	if(count == MAXBKS)
//	{
//		fputs("The book.dat is full.\n",stderr);
//		exit(EXIT_FAILURE);
//	}
//	puts("Please add new book title:");
//	while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
//	{
//		puts("Enter author:");
//		gets(library[count].author);
//		puts("Enter price:");
//		scanf("%f",&library[count].value);
//		while(getchar() != '\n')//清空输入行
//		{
//			continue;
//		}
//		if(count < MAXBKS)
//		{
//			puts("Enter next book's title:");
//		}
//		count++;
//	}
//	if(count > 0)
//	{
//		puts("Here is the list of your books");
//		for(index = 0;index < count;index++)
//		{
//			printf("%s by %s:$%.2f.\n",library[index].title,library[index].author,library[index].value);
//		}
//		fwrite(&library[filecount],size,count - filecount,pbooks);//后来添加的信息写入文件
//	}
//	else
//	{
//		puts("No books?Too bad.");
//	}
//	//关闭文件
//	if(fclose(pbooks) != 0)
//	{
//		fputs("Error closing file.\n",stderr);
//		exit(EXIT_FAILURE);
//	}
//	puts("Bye.");
//	return 0;
//}