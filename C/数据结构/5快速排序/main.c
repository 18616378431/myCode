#include<stdio.h>
#include"interface.h"

int main(int argc,char * argv[])
{
	List sortList[] = {
		{6,"d",false},
		{2,"b",false},
		{7,"e",false},
		{1,"a",false},
		{3,"c",false},
		{9,"f",false},
		{4,"g",false},
	};
	int size = sizeof(sortList)/sizeof(List);
	int i;

	puts("≈≈–Ú«∞:");
	for(i = 0;i < size;i++)
	{
		printf("carId=%d,tradeMark=%s.\n",sortList[i].item.carId,sortList[i].item.tradeMark);
	}
	quickSort(sortList,0,size - 1);
	puts("≈≈–Ú∫Û:");
	for(i = 0;i < size;i++)
	{
		printf("carId=%d,tradeMark=%s.\n",sortList[i].item.carId,sortList[i].item.tradeMark);
	}
	return 0;
}