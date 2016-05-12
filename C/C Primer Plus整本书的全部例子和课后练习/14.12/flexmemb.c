//�ṹ�����������Ա
#include<stdio.h>
#include<stdlib.h>

struct flex{
	int count;
	double average;
	double scores[];//���������Ա
};

void showVM(const struct flex * pst);

int main()
{
	struct flex * pf1,* pf2;//�����ṹָ��
	int n = 5;//�����С
	int i;//�±�
	double tot = 0;//����ֵ�ܺ�

	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));//Ϊ�ṹָ�����ռ�
	pf1->count = n;
	//Ϊ��������Ԫ�ظ�ֵ�������ܺ�
	for(i = 0;i < n;i++)
	{
		pf1->scores[i] = 20.00 - i;
		tot += pf1->scores[i];
	}
	//����ƽ��ֵ
	pf1->average = tot / n;
	//��ʾ��������Ԫ��
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
	//�ͷ��ڴ�
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