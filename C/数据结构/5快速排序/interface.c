#include<stdio.h>
#include"interface.h"

int partition(List * pList,int low,int high)
{
	Item basic = pList[low].item;
	while(low < high)
	{
		while(low < high && pList[high].item.carId >= basic.carId)
		{
			high--;
		}
		if(low < high)
		{
			pList[low++] = pList[high];
		}
		while(low < high && pList[low].item.carId <= basic.carId)
		{
			low++;
		}
		if(low < high)
		{
			pList[high--] = pList[low];
		}
	}
	pList[low].item = basic;
	return low;
}
void quickSort(List * pList,int low,int high)
{
	int basicSite;
	if(low < high)
	{
		basicSite = partition(pList,low,high);
		quickSort(pList,low,basicSite-1);
		quickSort(pList,basicSite+1,high);
	}
}