#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//预处理,仅在预处理过程进行简单的字符串替换,定义常量
#define R 10	
//宏函数,求和
#define ADD(a,b) (a+b)//宏不区分变量类型,不需要分号结尾
#define X(n) (n*10)

#define MAX_LEN 1024

int add(int a,int b);//函数区分变量类型

typedef int *p;//typedef是语句，需要分号结尾,p代表(int *)
//定义结构体
typedef struct student{
	char name[MAX_LEN];
	int sex;
	int age;
	int tall;
}STU;

int main()
{
	int a = R;
	int b = R;

	/*float c = ADD(10.5,11.0);
	float d = add(10.5,11.0);*/
	
	//声明int *类型,等价于int *k = NULL;
	p k = NULL;

	//声明结构体指针
	STU *stu = (STU *)malloc(sizeof(STU));

	strcpy(stu->name,"wjk");
	stu->sex = 1;
	stu->age = 26;
	stu->tall = 170;
	

	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d+%d=%d\n",a,b,ADD(a,b));

	/*printf("c=%f\n",c);
	printf("d=%f\n",d);*/

	

	printf("name:%s\n",stu->name);

	printf("sizeof(STU)=%d\n",sizeof(STU));
	printf("sizeof(STU *)=%d\n",sizeof(STU *));
	
	return 0;
}
int add(int a,int b)
{
	return a+b;
}