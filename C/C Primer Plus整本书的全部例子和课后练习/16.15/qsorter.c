//��������������鰴��С��������
#include<stdio.h>
#include<stdlib.h>

#define NUM 40

int myCompar(const void * p1,const void * p2);
void fillArr(double arr[],int n);
void showArr(double arr[],int n);

int main()
{
	double vals[NUM];

	fillArr(vals,NUM);
	puts("Random list:");
	showArr(vals,NUM);
	qsort(vals,NUM,sizeof(double),myCompar);
	puts("Sorted list:");
	showArr(vals,NUM);
	return 0;
}
//Ϊ����Ԫ�ظ�ֵ
void fillArr(double arr[],int n)
{
	int index;

	for(index = 0;index < n;index++)
	{
		arr[index] = (double)rand() / ((double)rand() + 0.1);
	}
}
//��ʾ����Ԫ��
void showArr(double arr[],int n)
{
	int index = 0;

	while(index < n)
	{
		printf("%9.4f",arr[index]);
		if(++index % 6 == 0)
			putchar('\n');
	}
	if(index % 6 != 0)
		putchar('\n');
}
int myCompar(const void * p1,const void * p2)
{
	//�����յ�ָ������ת��Ϊ��Ӧ����Ԫ�����͵�ָ��
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;

	if(*a1 < *a2)//��С����
		return -1;
	else if(*a1 == *a2)
		return 0;
	else
		return 1;
}