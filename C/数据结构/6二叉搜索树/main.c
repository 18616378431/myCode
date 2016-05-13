#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"tree.h"

char menu(void);
void addPet(Tree * pt);
void dropPet(Tree * pt);
void showPets(const Tree * pt);
void findPet(const Tree * pt);
void printItem(Item item);
void uppercase(char * str);

int main()
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while((choice = menu()) != 'q')
	{
		switch(choice)
		{
		case 'a':
			addPet(&pets);
			break;
		case 'l':
			showPets(&pets);
			break;
		case 'n':
			printf("%d cars in club\n",TreeItemCount(&pets));
			break;
		case 'f':
			findPet(&pets);
			break;
		case 'd':
			dropPet(&pets);
			break;
		default:
			puts("Switching error");
			break;
		}
	}
	DeleteAll(&pets);
	puts("Bye!");
	return 0;
}
//菜单
char menu()
{
	char ch;

	puts("==================================================");
	puts("Nerfville Car Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a)add a data\t\tl)show list of data");
	puts("n)number of data\tf)find data");
	puts("d)delete a data\t\tq)quit");
	puts("==================================================");
	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
			continue;
		ch = tolower(ch);
		if(strchr("alnfdq",ch) == NULL)
		{
			puts("Please enter an a,l,n,f,d or q:");
		}
		else
		{
			break;
		}
	}
	if(ch == EOF)
	{
		ch = 'q';
	}
	return ch;
}
//添加
void addPet(Tree * pt)
{
	Item temp;

	if(TreeIsFull(pt))
	{
		puts("No room in the club.");
	}
	else
	{
		puts("Please enter the car name:");
		gets(temp.petname);
		puts("Please enter the car kind:");
		gets(temp.petkind);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp,pt);
	}
}
//将名称种类全部转换为大写
void uppercase(char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}
//显示
void showPets(const Tree * pt)
{
	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
	}
	else
	{
		Traverse(pt,printItem);
	}
}
//指针函数调用函数
void printItem(Item item)
{
	printf("Car:%-19s Kind:%-19s\n",item.petname,item.petkind);
}
//查找
void findPet(const Tree * pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
		return ;
	}
	puts("Please enter name of pet you wish to find:");
	gets(temp.petname);
	puts("Please enter car kind:");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	if(InTree(&temp,pt))
	{
		printf("is a member.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}
//删除
void dropPet(Tree * pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
		return ;
	}
	puts("Please enter name of car you wish delete:");
	gets(temp.petname);
	puts("Please enter car kind:");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	if(DeleteItem(&temp,pt))
	{
		printf(" is dropped from the club.\n");
	}
	else
	{
		printf(" is not a member.\n");
	}
}