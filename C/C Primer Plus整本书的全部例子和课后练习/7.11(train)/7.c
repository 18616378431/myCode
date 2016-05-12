//#include<stdio.h>
//#define SA 10.00	//基本工资等级10.00$/h
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
//
//	printf("Enter your worktime in a week: \n");
//	scanf("%lf",&wt);
//	if(wt <= 30)
//	{
//		total = wt * SA;
//		sj = total * 0.15;
//	}
//	else if(wt > 30 && wt <= MWT)
//	{
//		total = wt * SA;
//		sj = BASE1 + (total - 300.00) * 0.20;
//	}
//	else if(wt > 40 && wt <= 45)
//	{
//		total = 40 * SA + (wt - 40) * SA * 1.5;
//		sj = BASE1 + (total - 300.00) * 0.20;
//	}
//	else
//	{
//		total = 40 * SA + (wt - 40) * SA * 1.5;
//		sj = BASE1 + BASE2 + (total - 450.00) * 0.25;
//	}
//	jgz = total - sj;
//	printf("total\tsj\tjgz\n");
//	printf("%.2f\t%.2f\t%.2f\n",total,sj,jgz);
//	return 0;
//}