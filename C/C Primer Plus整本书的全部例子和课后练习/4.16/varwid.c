//ʹ�ÿɱ��ȵ�����ֶ�
#include<stdio.h>

int main(void)
{
	unsigned width,precision;	//�����ֶο�ȣ����ȱ���
	int number=256;
	double weight=242.5;

	printf("What filed width? \n");
	scanf("%d",&width);
	printf("The number is : %*d \n",width,number);
	printf("Enter width and precision:");
	scanf("%d %d",&width,&precision);
	printf("Weight:%*.*f \n",width,precision,weight);
	return 0;
}