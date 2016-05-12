//动态创建数组
#include<stdio.h>
#include<stdlib.h>

int *make_array(int size,int value);
void show_array(int *p,int size);

int main()
{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements:\n");
	while(scanf("%d",&size) == 1 && size > 1)
	{
		printf("Enter the initialiazation value:\n");
		scanf("%d",&value);
		pa = make_array(size,value);
		if(pa)
		{
			show_array(pa,size);
			free(pa);
		}
		printf("Enter the number of elements(1 to quit):\n");
	}
	printf("Done.\n");
	return 0;
}

int *make_array(int size,int value)
{
	int *p;
	int i;

	p = (int *)malloc(size * sizeof(int));//为数组分配内存
	for(i = 0;i < size;i++)
	{
		p[i] = value;
	}
	return p;
}

void show_array(int *p,int size)
{
	int i;

	for(i = 0;i < size;i++)
	{
		printf("%2d",p[i]);
	}
	printf("\n");
}