//结构的伸缩数组成员
#include<stdio.h>
#include<stdlib.h>

struct flex{
	int count;
	double average;
	double scores[];//伸缩数组成员
};

void showVM(const struct flex * pst);

int main()
{
	struct flex * pf1,* pf2;//声明结构指针
	int n = 5;//数组大小
	int i;//下标
	double tot = 0;//所有值总和

	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));//为结构指针分配空间
	pf1->count = n;
	//为伸缩数组元素赋值并计算总和
	for(i = 0;i < n;i++)
	{
		pf1->scores[i] = 20.00 - i;
		tot += pf1->scores[i];
	}
	//计算平均值
	pf1->average = tot / n;
	//显示伸缩数组元素
	showVM(pf1);
	printf("%.2lf.\n",tot);

	n = 9;
	tot = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for(i = 0;i < n;i++)
	{
		pf2->scores[i] = 20.00 - i / 2.0;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showVM(pf2);
	printf("%.2lf.\n",tot);
	//释放内存
	free(pf1);
	free(pf2);
	return 0;
}
void showVM(const struct flex * pst)
{
	int i;
	
	printf("Scores:");
	for(i = 0;i < pst->count;i++)
	{
		printf("%7.2lf",pst->scores[i]);
	}
	printf("\nAverage:%.2lf.\n",pst->average);
}