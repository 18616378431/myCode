//5.1�Ľ������while ѭ��
#include<stdio.h>
#define ADJUST 7.64
#define SCALE 0.325

int main(void)
{
	double shoe,foot;

	printf("Shoes size(men's) \tfoot length! \n");
	shoe=3.0;
	while(shoe<18.5)		//whileѭ����ʼ,ѭ������
	{
		foot=SCALE*shoe+ADJUST;
		printf("%10.1f and %15.2f inchs! \n",shoe,foot);
		shoe=shoe+1;		//�����仯
	}
	printf("If it fits,wear it! \n");
	return 0;
}