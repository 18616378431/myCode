#include<stdio.h>
#define ROWS 3
#define COLS 5

void getE(double ar[][COLS],int n);
double getRowAve(double ar[][COLS],int r);
double getAllRowAve(double ar[][COLS]);
double getMax(double ar[][COLS]);
void showA(double ar[][COLS]);
void showResult(double ar[][COLS]);

int main()
{
	double source[ROWS][COLS];
	//a
	getE(source,ROWS);
	//e��ʾ���,���е�����b,c,d����
	showResult(source);
	return 0;
}
//��ʾ��ȡ��������,VAL:void showA(int row,int cols,double ar[row][cols])
void showA(double ar[][COLS])
{
	int i;
	int j;

	for(i = 0;i < ROWS;i++)
	{
		for(j = 0;j < COLS;j++)
		{
			printf("source[%d][%d] = %.2lf\n",i,j,ar[i][j]);
		}
	}
}
//Ϊ����Ԫ�ظ�ֵVAL:void getE(int row,int cols,ar[row][cols])
void getE(double ar[][COLS],int n)
{
	int i;
	int status;

	for(i = 0;i < ROWS;i++)
	{
		printf("�������%d��������Ԫ��:",i + 1);
		status = scanf("%lf %lf %lf %lf %lf",&ar[i][0],&ar[i][1],&ar[i][2],&ar[i][3],&ar[i][4]);
		if(status != 5)
		{
			break;
		}
	}
}
//��������ÿ�еĺ�,VAL:void getRowAve(int row,int cols,ar[row][cols],int r) 
double getRowAve(double ar[][COLS],int r)
{
	double sumAve = 0;
	int i;

	for( i = 0;i < COLS;i++)
	{
		sumAve += ar[r][i];
	}
	return sumAve;
}
//������������ƽ��ֵ,VAL:double getAllRowAve(int row,int cols,ar[row][cols])
double getAllRowAve(double ar[][COLS])
{
	double sumAllAve = 0;
	int i;

	for(i = 0;i < ROWS;i++)
	{
		sumAllAve += getRowAve(ar,i);
	}
	sumAllAve /= 15;
	return sumAllAve;
}
//�ҳ���15�����е����ֵ,VAL:VAL:double getMax(int row,int cols,ar[row][cols])
double getMax(double ar[][COLS])
{
	double max = 0;
	double temp;
	int i;
	int j;
	int e;

	//�ڲ�����ð������
	for(i = 0;i < ROWS;i++)
	{
		for(j = 0;j < COLS -1;j++)
		{
			for(e = j + 1;e < COLS;e++)
			{
				if(ar[i][j] > ar[i][e])
				{
					temp = ar[i][j];
					ar[i][j] = ar[i][e];
					ar[i][e] = temp;
				}
			}
		}
	}
	//��ȡ����Ԫ�����ֵ
	if(ar[0][4] > ar[1][4] && ar[0][4] > ar[2][4])
	{
		max = ar[0][4];
	}
	if(ar[1][4] > ar[0][4] && ar[1][4] > ar[2][4])
	{
		max = ar[1][4];
	}
	if(ar[2][4] > ar[1][4] && ar[2][4] > ar[0][4])
	{
		max = ar[2][4];
	}
	return max;
}
//��ʾ�����VAL:void showReault(int row,int cols,double ar[row][cols])
void showResult(double ar[][COLS])
{
	int i;
	//b
	for(i = 0;i < ROWS;i++)
	{
		printf("Average of row %d = %.2lf\n",i + 1,getRowAve(ar,i) /COLS);
	}
	//c
	printf("��������ƽ��ֵ:%.2lf\n",getAllRowAve(ar));
	//d
	printf("�����е����ֵΪ:%.2lf\n",getMax(ar));
	//��ʾ����
	//showA(ar);
}