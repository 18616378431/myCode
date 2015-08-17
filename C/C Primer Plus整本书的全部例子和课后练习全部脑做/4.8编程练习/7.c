//计算汽车行驶汽油消耗
#include<stdio.h>
#define OILTOL 3.785		//加仑转换为升系数

int main(void)
{
	const float MILETOKM=1.609;		//只读常量 英里转换为公里系数
	double lper100k;		//欧洲通用燃料消耗表示法
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
	printf("欧洲通用表示法为：%.1f 升/100km \n",lper100k);
	return 0;
}