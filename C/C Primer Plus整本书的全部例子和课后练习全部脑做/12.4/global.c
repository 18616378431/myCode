#include<stdio.h>

//�ⲿ����
int units = 0;
//��������
void critic();

int main()
{
	extern int units;//ͬһ�ļ��Ŀ�ѡ��������

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
	//ʡ���˿�ѡ�Ķ�������
	printf("No,luck,Try again!\n");
	scanf("%d",&units);
}