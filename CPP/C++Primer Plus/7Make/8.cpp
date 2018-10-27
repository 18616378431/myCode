#include<iostream>

using namespace std;

const int SLEN = 30;

struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[],int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);

int main()
{
	int class_size;

	cout << "Enter class size:";
	cin >> class_size;
	while(cin.get() != '\n')
		continue;

	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu,class_size);
	for(int i = 0;i < entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);
	cout << "Done.\n";
	delete []ptr_stu;
	return 0;
}
//获取信息
int getinfo(student pa[],int n)
{
	int count = 0;
	
	for(int i = 0;i < n;i++)
	{
		cout << "Enter fullname:";
		cin.getline(pa[count].fullname,SLEN);
		if(strlen(pa[count].fullname) == 0)
		{
			break;
		}
		cout << "Enter hobby:";
		cin >> pa[count].hobby;
		cout << "Enter ooplevel:";
		cin >> pa[count].ooplevel;
		cin.get();
		count++;
	}
	return count;
}
//按值传递,显示单个学生信息
void display1(student st)
{
	cout << "display1" << endl;
	cout << "fullname:" << st.fullname << endl;
	cout << "hobby:" << st.hobby << endl;
	cout << "ooplevel:" << st.ooplevel << endl;
}
//传递结构地址
void display2(const student *ps)
{
	cout << "display2" << endl;
	cout << "fullname:" << ps->fullname << endl;
	cout << "hobby:" << ps->hobby << endl;
	cout << "ooplevel:" << ps->ooplevel << endl;
}
//显示结构体数组,传递结构体首元素地址
void display3(const student pa[],int n)
{
	cout << "display3" << endl;
	for(int i = 0;i < n;i++)
	{
		cout << "fullname" << i << ":" << pa[i].fullname << endl;
		cout << "hobby" << i << ":" << pa[i].hobby << endl;
		cout << "ooplevel" << i << ":" << pa[i].ooplevel << endl;
	}
}