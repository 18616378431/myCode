//ָ������
#include<stdio.h>
#define SQUARES 64 //�����Ϸ�������
#define CROP 1E15  //���� ����С�����

int main(void)
{
	int count=1;
	double total,current;
	printf("square grains total		");
	printf("fraction of \n");
	printf("add		grain		");
	printf("US total \n");
	total=current=1.0;		//��һ����ʼ
	printf("%4d %13.2e %12.2e %12.2e \n",count,current,total,total/CROP);
	while(count<SQUARES)
	{
		count=count+1;
		current=2*current;
		total=total+current;
		printf("%4d %13.2e %12.2e %12.2e \n",count,current,total,total/CROP);
	}
	return 0;
}