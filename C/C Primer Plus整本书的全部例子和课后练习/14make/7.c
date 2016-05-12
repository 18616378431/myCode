//#include<stdio.h>
//#include<stdlib.h>//exit()
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 10
//#define BUFSIZE 1024
//#define BOOL int
//#define true 1
//#define false 0
//
//typedef struct book{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//}BOOK;
//
//int main()
//{
//	BOOK library[MAXBKS];
//	int count = 0;
//	int index,filecount;
//	FILE * pbooks;
//	int size = sizeof(BOOK);
//	char choice;
//	BOOL isDelete;
//	BOOL isEdit;
//	
//	if((pbooks = fopen("book.dat","r+b")) == NULL)
//	{
//		fprintf(stderr,"Can't open file \"book.dat\".\n");
//		exit(1);
//	}
//	if(setvbuf(pbooks,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buffer.\n");
//		exit(2);
//	}
//	rewind(pbooks);
//	while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
//	{
//		isDelete = false;
//		isEdit = false;
//		if(count == 0)
//		{
//			puts("Current book.dat contents:");
//		}
//		printf("%s by %s:$%.2f.\n",library[count].title,library[count].author,library[count].value);
//		printf("offset = %d.\n",ftell(pbooks));
//		puts("Whether do something to it");
//		puts("d)Delete It\te)Edit It\tn)Do Nothing");
//		choice = getchar();
//		switch(choice)
//		{
//		case 'd':
//			isDelete = true;
//			break;
//		case 'e':
//			while(getchar() != '\n')
//				continue;
//			puts("Enter title:");
//			gets(library[count].title);
//			puts("Enter author:");
//			gets(library[count].author);
//			puts("Enter value:");
//			scanf("%f",&library[count].value);
//			break;
//		case 'n':break;
//		default:puts("Please type in an character such as d,e or n");break;
//		}
//		while(getchar() != '\n')
//			continue;
//		if(!isDelete)
//			count++;
//	}
//	filecount = count;//记录文件中已有的记录数
//	if(count == MAXBKS)
//	{
//		fputs("The book.dat file is full.\n",stderr);
//		exit(3);
//	}
//	puts("Please add new book titles(Enter an empty line to stop):");
//	while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
//	{
//		puts("Enter the author:");
//		gets(library[count].author);
//		puts("Enter the value:");
//		scanf("%f",&library[count].value);
//		while(getchar() != '\n')
//			continue;
//		count++;
//		if(count < MAXBKS)
//		{
//			puts("Enter the next title:");
//		}
//	}
//	fclose(pbooks);
//	if((pbooks = fopen("book.dat","w+b")) == NULL)
//	{
//		fprintf(stderr,"Can't open file \"book.dat\".\n");
//		exit(1);
//	}
//	if(setvbuf(pbooks,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buffer.\n");
//		exit(2);
//	}
//	if(count > 0)
//	{
//		puts("Here is your books list:");
//		for(index = 0;index < count;index++)
//		{
//			printf("%s by %s:$%.2f.\n",library[index].title,library[index].author,library[index].value);
//		}
//		//将新加入的信息一次性全部写入文件中
//		fwrite(&library[0],size,count,pbooks);
//	}
//	else
//	{
//		puts("No Books!Too bad!");
//	}
//	fclose(pbooks);
//	puts("Bye!");
//	return 0;
//}