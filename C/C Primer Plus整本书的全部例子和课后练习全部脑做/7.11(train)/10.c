//#include<stdio.h>
//#define RATE1 0.15
//#define RATE2 0.28
//
//float come(float x,int a);
//
//int main(void)
//{
//	int i;		//����
//	float sj;		//˰��
//	float income;		//����
//	int status;		//�ж�income�Ƿ���ȷ
//	
//	printf("*****************************************************************\n");
//	printf("Enter your type:\n");
//	printf("1)����\t2)����\t3)�ѻ�\t����\t4)�ѻ飬����\t5)q to exit\n");
//	printf("*****************************************************************\n");
//	while(scanf("%d",&i) == 1)
//	{
//		printf("Enter your income:\n");
//		status = scanf("%f",&income);
//		if(status == 1)
//		{
//			sj = come(income,i);
//			printf(" sj is %.2f.\n",sj);
//			printf("Enter your type.\n");
//		}
//		else
//		{
//			printf("Please type in correct number.\n");
//		}
//		
//	}
//	return 0;
//}
//
//float come(float x,int a)
//{
//	float sj1;
//	float fj;
//	switch(a)
//	{
//	case 1:
//		fj = 17850.00;
//		break;
//	case 2:
//		fj = 23900.00;
//		break;
//	case 3:
//		fj = 29750.00;
//		break;
//	case 4:
//		fj = 14875.00;
//		break;
//	}
//	if(x <= fj)
//	{
//		sj1 = x * RATE1;
//	}
//	else
//	{
//		sj1 = fj * RATE1 + (x - fj) * RATE2;
//	}
//	return sj1;
//}