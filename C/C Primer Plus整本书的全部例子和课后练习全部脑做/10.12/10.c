#include<stdio.h>

int main()
{
	float rootbeer[10],things[10][5],*pf,value = 2.2;
	int i = 3;

	rootbeer[2] = value;

	/*scanf("%f",&rootbeer);
	printf("%.2f\n",rootbeer[0]);*/
	
	//rootbeer = value;
	printf("%f\n",rootbeer);
	things[4][4] = rootbeer[3];
	//things[5] = rootbeer;
	//pf = value;
	pf = rootbeer;

	/*
	11................................................
	int arr[800][600];
	12................................................
	double trots[20];
	short clops[10][30];
	long shots[5][10][15];
	
	sum(trots);µ÷ÓÃ
	void sum(double ar[])
	{
		...
	}
	VAL:
	sum(a,b,trots);
	void sum(int rows,int cols,double ar[])
	{
		...
	}
	
	sum1(clops,10)
	void sum1(short ar[][30],int rows)
	{
		...
	}
	VAL:
	sum1(ROWS,COLS,clops);
	void sum1(int rows,int cols,short ar[rows][cols])
	{
		...
	}

	sum2(shots,5);
	void sum2(long ar[][10][15],int rows)
	{
		...
	}
	VAL:
	sum2(5,10,15,shots);
	void sum2(int rows,int cols,int hrz,long ar[rows][cols][hrz])
	{
		...
	}
	13..................................................
	void show(double ar[],int n);
	void show2(double ar2[][3],int n);

	show((double []){8,3,9,2},4);
	show2((double [][3]){{8,3,9},{5,4,1}},2);
	*/
	return 0;
}