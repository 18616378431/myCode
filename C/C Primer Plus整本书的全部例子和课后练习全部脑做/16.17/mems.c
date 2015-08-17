//memcpy()¡¢memmove()£¬string.h¿â£¬¸´ÖÆº¯Êý,strcpy(),strncpy()
#include<stdio.h>
#include<string.h>
#define SIZE 10

void show(const int arr[],int n);

int main()
{
	int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int target[SIZE];
	double curious[SIZE / 2] = {1.0,2.0,3.0,4.0,5.0};

	puts("memcpy() used:");
	puts("values (original data):");
	show(values,SIZE);
	memcpy(target,values,SIZE * sizeof(int));
	puts("\ntarget (copy of values):");
	show(target,SIZE);

	puts("\nUsing memmove() width overlapping ranges:");
	memmove(values + 2,values,5 * sizeof(int));
	puts("values -- elements 0 - 5 copied to 2 - 7:");
	show(values,SIZE);
	puts("");

	puts("using memcpy() to copy double to int:");
	memcpy(target,curious,(SIZE / 2) * sizeof(double));
	puts("target -- 5 doubles into 10 int position:");
	show(target,SIZE);
	
	return 0;
}
void show(const int arr[],int n)
{
	int i = 0;
	while(i < n)
	{
		printf("%d ",arr[i++]);
	}
}