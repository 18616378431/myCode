//�Զ�������������
#include<stdio.h>

int main()
{
	auto int x = 30;//��㶨��

	printf("outer x = %d\n",x);
	{
		int x = 77;//�ڲ㶨��
		printf("inner x = %d\n",x);
	}

	printf("outer x = %d\n",x);

	while(x++ < 33)//ʹ�õ�����������xֵ
	{
		int x = 100;//�ڲ�
		x++;
		printf("inner while loop x = %d\n",x);
	}

	printf("outer x = %d\n",x);
	return 0;
}