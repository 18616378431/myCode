//����������ʻ��������
#include<stdio.h>
#define OILTOL 3.785		//����ת��Ϊ��ϵ��

int main(void)
{
	const float MILETOKM=1.609;		//ֻ������ Ӣ��ת��Ϊ����ϵ��
	double lper100k;		//ŷ��ͨ��ȼ�����ı�ʾ��
	float mile;
	float oil;
	float summy;
	printf("Enter Mile:");
	scanf("%f",&mile);
	printf("Enter oil:");
	scanf("%f",&oil);
	summy=mile/oil;
	printf("Summy=%.1f mile/oil \n",summy);
	lper100k=((summy*MILETOKM)/OILTOL)*100;
	printf("ŷ��ͨ�ñ�ʾ��Ϊ��%.1f ��/100km \n",lper100k);
	return 0;
}