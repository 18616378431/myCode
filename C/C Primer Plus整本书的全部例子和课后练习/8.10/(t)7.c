//#include<stdio.h>
//#define MWT 40.00	//最大工作时间
//#define BASE1 (300.00 * 0.15)		//300美元工资时税金
//#define BASE2 (150.00 * 0.20)	//下一个150美元的税金
//
//int main(void)
//{
//	double wt;		//工作时间
//	double total;		//总工资
//	double sj;		//税金
//	double jgz;		//净工资
//	double SA;		//工资等级
//	char i;		//工资等级编号
//	
//
//	printf("*****************************************************************\n");
//	printf("Enter the number corresponding to the desired pay rate or action:\n");
//	printf("a)$8.75/hr\t\tb)$9.33/hr\n");
//	printf("c)$10.00/hr\t\td)$11.20/hr\n");
//	printf("q)quit\n");
//	printf("*****************************************************************\n");
//	while(( i = getchar()) != EOF)
//	{
//		switch(i)
//		{
//		case 'a':
//			SA = 8.75;
//			break;
//		case 'b':
//			SA = 9.33;
//			break;
//		case 'c':
//			SA = 10.00;
//			break;
//		case 'd':
//			SA = 11.20;
//			break;
//		case 'q':
//			SA = 0;
//			printf("Good bye!\n");
//			break;
//		default:
//			SA = i;
//			break;
//		}
//		if(SA != 0 && i >= 'a' && i <= 'd')
//		{
//			printf("Your SA level is %.2lf.\n",SA);
//			printf("Enter your worktime in a week: \n");
//			scanf("%lf",&wt);
//			if(wt <= 30)
//			{
//				total = wt * SA;
//				sj = total * 0.15;
//			}
//			else if(wt > 30 && wt <= MWT)
//			{
//				total = wt * SA;
//				sj = BASE1 + (total - 300.00) * 0.20;
//			}
//			else if(wt > 40 && wt <= 45)
//			{
//				total = 40 * SA + (wt - 40) * SA * 1.5;
//				sj = BASE1 + (total - 300.00) * 0.20;
//			}
//			else
//			{
//				total = 40 * SA + (wt - 40) * SA * 1.5;
//				sj = BASE1 + BASE2 + (total - 450.00) * 0.25;
//			}
//			jgz = total - sj;
//			printf("total\tsj\tjgz\n");
//			printf("%.2f\t%.2f\t%.2f\n",total,sj,jgz);
//			printf("Enter your SA level.\n");
//			while(getchar() != '\n')
//				continue;
//		}
//		else
//		{
//			if(i > 100 || i < 97)
//			{
//				if(i == 'q')
//				{
//					break;
//				}
//				else
//				{
//					printf("Please enter number like 1 to 5.%d\n",i);	
//				}	
//			}
//			else if(i == 'q')
//			{
//				break;
//			}
//		}
//	}
//	return 0;
//}