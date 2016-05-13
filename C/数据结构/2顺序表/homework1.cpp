//顺序表存储结构，学生上机管理系统,存储一台考试机器中登录的考生信息
#include<iostream>
#include"home1.h"

using namespace std;

char menu();
void Add(Item * pSeq, int * seqLen);
void Del(Item * pSeq, int * seqLen);
void Seek(Item * pSeq, int * seqLen);
void show(Item item);
void delMore();
void editCmd();

int main()
{
	Item item[MAXSIZE];//存储线性表数据元素
	int seqLen;//线性表长度
	char ch;

	editCmd();
	//初始化顺序表
	InitalizeSeq(&seqLen);
	while ((ch = menu()) != 'q')
	{
		switch (ch)
		{
		case 'a':
			Add(item, &seqLen);
			break;
		case 'g':
			Seek(item, &seqLen);
			break;
		case 'd':
			Del(item, &seqLen);
			break;
		case 's':
			Traverse(item, &seqLen, show);
			break;
		default:
			cout << "Error input!Try again!" << endl;
			delMore();
			break;
		}
	}
	EmptyList(&seqLen);
	return 0;
}
//菜单
char menu()
{
	char ch;

	cout << "=============================================" << endl;
	cout << "Welcome to Student Information Manager System!" << endl;
	cout << "Enter your choice to operate your application:" << endl;
	cout << "a)add item\tg)seek item" << endl;
	cout << "d)delete\ts)show list" << endl;
	cout << "q)quit" << endl;
	ch = getchar();
	delMore();
	return ch;
}
//添加信息
void Add(Item * pSeq,int * seqLen)
{
	Item temp;

	cout << "Input student id:";
	cin >> temp.stuId;
	cout << "Input student name:";
	cin >> temp.name;
	if (temp.name[0] == '\0')
	{
		fprintf(stderr,"You didn't enter name!\n");
		return;
	}
	if (AddItem(pSeq, seqLen, &temp))
	{
		cout << "AddItem successfully!" << endl;
	}
	else
	{
		cout << "Add item failed!" << endl;
	}
	delMore();
}
//删除指定元素i
void Del(Item * pSeq,int * seqLen)
{
	int i;//删除顺序表中的第i个元素

	cout << "Enter the deleted index \"i\":";
	cin >> i;
	if (DeleteItem(pSeq, seqLen, i))
	{
		cout << "Delete item successful!" << endl;
	}
	else
	{
		cout << "Delete item failed!" << endl;
	}
	delMore();
}
//搜索指定元素
void Seek(Item * pSeq,int * seqLen)
{
	Item temp;

	cout << "Enter the Student id:";
	cin >> temp.stuId;
	cout << "Enter the Student name:";
	cin >> temp.name;
	if(SeekItem(pSeq,seqLen,temp))
	{
		cout << "The item is exists!" << endl;
	}
	else
	{
		cout << "The item is not exists!" << endl;
	}
	delMore();
}
//指定函数作用于顺序表
void show(Item item)
{
	cout << "Student ID:" << item.stuId;
	cout << " Student name:" << item.name << endl;
}
//清除剩余输入
void delMore()
{
	while (getchar() != '\n')
		continue;
}
//修改界面
void editCmd()
{
	system("color fc");
	system("title 学生上机管理系统");
}