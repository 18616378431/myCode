//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include"9.h"
//
////#define BOOL int
////#define true 1
////#define false 0
////#define LEN 40
////#define SIZE 12
////
////typedef struct seat{
////	int code;//��λ���
////	BOOL isSale;//�Ƿ��Ѿ���Ԥ���ı��
////	char fn[LEN];//��
////	char ln[LEN];//��
////}SEAT;
////
////void createFile(void);
////int setFileName(int fnum);
////int getInfo(SEAT * st);
////char menu(int fnum);
////void opera(SEAT * seat1,int fnum);
////void emptyNum(SEAT * st);
////void emptyList(SEAT * st);
////void showAlpha(SEAT * st);
////void assign(SEAT * st);
////void delSeat(SEAT * st);
////void editSeat(SEAT * st);
////void saveInfo(SEAT st[],int size);
////void delMore(void);
////
////char file_name[LEN];
//
//int main()
//{
//	SEAT seat1[SIZE];
//	int flightNum;
//
//	//createFile();//���������ļ�
//	puts("Choose a flight:102,311,444 or 519(q to quit):");
//	while(scanf("%d",&flightNum) == 1)
//	{
//		delMore();
//		if(setFileName(flightNum) == 0)
//		{
//			getInfo(seat1);//���ļ��ж�ȡ��Ϣ
//			opera(seat1,flightNum);
//			saveInfo(seat1,sizeof(seat1));
//		}
//		puts("Choose a flight:102,311,444 or 519(q to quit):");
//	}
//	return 0;
//}
////���ú����Ӧ���ļ�����
//int setFileName(int fnum)
//{
//	switch(fnum)
//	{
//	case 102:
//		strcpy(file_name,"seat");
//		break;
//	case 311:
//		strcpy(file_name,"seat1");
//		break;
//	case 444:
//		strcpy(file_name,"seat2");
//		break;
//	case 519:
//		strcpy(file_name,"seat3");
//		break;
//	default:
//		puts("Error flight code");
//		return -1;
//		break;
//	}
//	return 0;
//}
////����˵�
//char menu(int fnum)
//{
//	char choice;
//
//	puts("======================================================");
//	printf("********Welcome to %d flight********\n",fnum);
//	puts("To choose a function,enter its letter label:");
//	puts("a)Show number of empty seats");
//	puts("b)Show list of empty seats");
//	puts("c)Show alphabetical list of seats");
//	puts("d)Assign a customer to a seat assignment");
//	puts("e)Delete a seat assignment");
//	puts("v)Edit a seat assignment");
//	puts("f)Return to hte previous menu");
//	puts("======================================================");
//	printf("Your choice:");
//	choice = getchar();
//	delMore();
//	return choice;
//}
////ִ�в���
//void opera(SEAT * seat1,int fNum)
//{
//	char ch;
//	
//	while((ch = menu(fNum)) != 'f')
//	{
//		switch(ch)
//		{
//		case 'a':
//			emptyNum(seat1);
//			break;
//		case 'b':
//			emptyList(seat1);
//			break;
//		case 'c':
//			showAlpha(seat1);
//			break;
//		case 'd':
//			assign(seat1);
//			break;
//		case 'e':
//			delSeat(seat1);
//			break;
//		case 'v':
//			editSeat(seat1);
//			break;
//		default:
//			puts("Please type in an character such as a,b,c,d and e:");
//			break;
//		}
//	}
//}
////����λ����
//void emptyNum(SEAT * st)
//{
//	int i;
//	int ct = 0;
//
//	for(i = 0;i < SIZE;i++)
//	{
//		if(!st[i].isSale)
//		{
//			ct++;
//		}
//	}
//	printf("There is %d empty seats.\n",ct);
//}
////����λ�б�
//void emptyList(SEAT * st)
//{
//	int i;
//
//	puts("Empty seats");
//	puts("Code\tisSale\tfirstName\tlastName");
//	for(i = 0;i < SIZE;i++)
//	{
//		if(!st[i].isSale)
//		{
//			printf("%d\t%d\t%s\t%s.\n",st[i].code,st[i].isSale,st[i].fn,st[i].ln);
//		}
//	}
//}
////����ĸ˳����ʾ��λ�б�
//void showAlpha(SEAT * st)
//{
//	SEAT * p[SIZE];
//	SEAT * temp;
//	int i,j;
//	
//	for(i = 0;i < SIZE;i++)
//		p[i] = &st[i];
//	for(i = 0;i < SIZE - 1;i++)
//	{
//		for(j = i + 1;j < SIZE;j++)
//		{
//			if(strcmp(p[i]->fn,p[j]->fn) < 0)
//			{
//				temp = p[i];
//				p[i] = p[j];
//				p[j] = temp;
//			}
//		}
//	}
//	puts("Seats order in alphabetical");
//	puts("Code\tisSale\tfirstName\tlastName");
//	for(i = 0;i < SIZE;i++)
//		printf("%d\t%d\t%s\t%s.\n",p[i]->code,p[i]->isSale,p[i]->fn,p[i]->ln);
//}
////���ͻ����䵽һ������λ�ϲ���ȡ��Ϣ
//void assign(SEAT * st)
//{
//	int i;
//
//	for(i = 0;i < SIZE;i++)
//	{
//		if(!st[i].isSale)
//		{
//			st[i].isSale = true;
//			printf("Here is a seat code:%d for you!\nPlease type in your first name:\n",st[i].code);
//			gets(st[i].fn);
//			printf("and your last name:\n");
//			gets(st[i].ln);
//			break;
//		}
//	}
//}
////ɾ����λ��Ϣ
//void delSeat(SEAT * st)
//{
//	int code;//��λ���
//	int i;
//	BOOL isFound = false;
//
//	puts("Please enter the seat code:");
//	scanf("%d",&code);
//	delMore();
//	for(i = 0;i < SIZE;i++)
//	{
//		if(st[i].code == code)
//		{
//			isFound = true;
//			break;
//		}
//	}
//	if(isFound && st[i].isSale)
//	{
//		st[i].isSale = false;
//		//st[i].fn = st[i].ln;
//		strcpy(st[i].fn,"");
//		strcpy(st[i].ln,"");
//	}
//	else
//	{
//		puts("Error seat code");
//	}
//}
////�޸ĺ�����Ϣ
//void editSeat(SEAT * st)
//{
//	int code;
//	int i;
//	BOOL isFound = false;
//
//	puts("Input the seat code which you want to edit:");
//	scanf("%d",&code);
//	delMore();
//	for(i = 0;i < SIZE;i++)
//	{
//		if(code == st[i].code)
//		{
//			isFound = true;
//			puts("Input the new first name:");
//			gets(st[i].fn);
//			puts("Input the new last name:");
//			gets(st[i].ln);
//			puts("Successfully");
//			break;
//		}
//	}
//	if(!isFound)
//	{
//		puts("Seat doesn't exist!");
//	}
//}
////���������ļ�
//void createFile(void)
//{
//	SEAT seat1[SIZE] = {
//		{35720,false,"",""},
//		{35721,false,"",""},
//		{35722,false,"",""},
//		{35723,true,"Jone","Hiber"},
//		{35724,false,"",""},
//		{35725,false,"",""},
//		{35726,false,"",""},
//		{35727,true,"Wang","Kang"},
//		{35728,false,"",""},
//		{35729,false,"",""},
//		{35730,false,"",""},
//		{35731,false,"",""},
//	};
//	FILE * fp;
//	int i = sizeof(seat1);
//
//	if((fp = fopen(file_name,"wb")) == NULL)
//	{
//		fprintf(stderr,"Can't open file\"seat\".\n");
//		exit(1);
//	}
//	if(fwrite(seat1,sizeof(seat1),1,fp) == 1)
//	{
//		puts("Succesfully");
//	}
//	fclose(fp);
//}
////���ļ��ж�����Ϣ
//int getInfo(SEAT * st)
//{
//	int i;
//	FILE * fp;
//
//	if((fp = fopen(file_name,"r")) == NULL)
//	{
//		fprintf(stderr,"Can't open file\"seat\".\n");
//		for(i = 0;i < SIZE;i++)
//		{
//			st[i].code = 35720 + i;
//			st[i].isSale = false;
//		}
//		return 0;
//	}
//	i = 0;
//	while(i < SIZE && fread(&st[i],sizeof(SEAT),1,fp) == 1)
//		i++;
//	fclose(fp);
//	return 0;
//}
////�����º����Ϣ����д���ļ�w
//void saveInfo(SEAT st[],int size)
//{
//	FILE * fp;
//	int i = sizeof(st);
//
//	if((fp = fopen(file_name,"w")) == NULL)
//	{
//		fprintf(stderr,"Can't open file \"seat\".\n");
//		exit(1);
//	}
//	fwrite(st,size,1,fp);
//	fclose(fp);
//}
////�����ʣ�༰���з�
//void delMore(void)
//{
//	while(getchar() != '\n')
//		continue;
//}