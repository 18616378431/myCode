////���ṹ���ݱ��浽�ļ�
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
//	struct book library[MAXBKS];//�ṹ����
//	FILE *pbooks;//�ļ�ָ��
//	int index,filecount;//�����ͼ�¼�ļ��е�ǰ�Ľṹ��Ŀ
//	int count = 0;
//	int size = sizeof(struct book);//bookģ��Ĵ�С
//
//	//���ļ�
//	if((pbooks = fopen("book.dat","ab+")) == NULL)
//	{
//		fputs("Can not open file\"book.dat\".\n",stderr);
//		exit(EXIT_FAILURE);
//	}
//	rewind(pbooks);//���ļ�ָ�붨λ���ļ���ʼ��
//	//������ǰ�ļ�
//	while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
//	{
//		if(count == 0)
//		{
//			puts("Current contents of book.dat");
//		}
//		printf("%s by %s:$%.2f.\n",library[count].title,library[count].author,library[count].value);
//		count++;
//	}
//	filecount = count;//��¼�ļ��е�ǰ�Ľṹ�����
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
//		while(getchar() != '\n')//���������
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
//		fwrite(&library[filecount],size,count - filecount,pbooks);//������ӵ���Ϣд���ļ�
//	}
//	else
//	{
//		puts("No books?Too bad.");
//	}
//	//�ر��ļ�
//	if(fclose(pbooks) != 0)
//	{
//		fputs("Error closing file.\n",stderr);
//		exit(EXIT_FAILURE);
//	}
//	puts("Bye.");
//	return 0;
//}