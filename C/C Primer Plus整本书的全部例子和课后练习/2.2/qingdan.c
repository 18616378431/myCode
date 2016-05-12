//把两fathoms换算成英尺feet
#include<stdio.h>		//预处理指令

int main()				//带有参数的函数名
{
	int feet,fathoms;	//声明语句

	fathoms=2;			//赋值语句
	feet=6*fathoms;		//运算
	printf("There are %d feet in %d fathoms!\n",feet,fathoms);//函数语句
	printf("Yes,i said %d feet! \n",6*fathoms);
	return 0;
}