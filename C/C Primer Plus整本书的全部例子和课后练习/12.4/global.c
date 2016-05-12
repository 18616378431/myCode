#include<stdio.h>

//外部变量
int units = 0;
//函数声明
void critic();

int main()
{
	extern int units;//同一文件的可选二次声明

	printf("How many pounds to a frikin of butter?\n");
	scanf("%d",&units);
	while(units != 56)
	{
		critic();
	}
	printf("You must have looked it up.\n");
	return 0;
}
void critic()
{
	//省略了可选的二次声明
	printf("No,luck,Try again!\n");
	scanf("%d",&units);
}