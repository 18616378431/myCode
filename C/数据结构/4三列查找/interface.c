//实现文件
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"interface.h"

//初始化HashList
void InitHashList(HashList hl)
{
	int index;
	
	for(index = 0;index < HASH_MAX_SIZE;index++)
	{
		//清空关键字车牌号
		hl[index].carId = 0;
	}
}
//清空HASH列表
void ClearHashList(HashList hl)
{
	int index;
	
	for(index = 0;index < HASH_MAX_SIZE;index++)
	{
		//清空关键字车牌号
		hl[index].carId = 0;
		strcpy(hl[index].tradeMark,"");
		hl[index].flag = false;
	}
}
//除留余数构建散列函数
int HashDiv(int carId)
{
	return carId % MOD;
}
//向Hash列表插入元素
BOOL InsertItemIntoHashList(HashList hl,Item item)
{
	int hash_key,init_key;

	hash_key = init_key = HashDiv(item.carId);
	while(hl[hash_key].carId != 0 && hl[hash_key].carId != item.carId)
	{
		hash_key = (hash_key + 1) % MOD;
		if(init_key == hash_key)
		{
			break;
		}
	}
	if(hl[hash_key].carId == 0)
	{
		hl[hash_key].carId = item.carId;
		strcpy(hl[hash_key].tradeMark,item.tradeMark);
		return true;
	}
	return false;
}
//从hash表中查找元素
int LocateItemFromHashList(HashList hl,Item item)
{
	int hash_key,init_key;

	hash_key = init_key = HashDiv(item.carId);
	while(hl[hash_key].carId != 0 && hl[hash_key].carId != item.carId)
	{
		hash_key = (hash_key + 1) % MOD;
		if(init_key == hash_key)
		{
			break;
		}
	}
	if(hl[hash_key].carId == item.carId)
	{
		return init_key;
	}
	else
	{
		return -1;
	}
}
//从hash表中删除元素
BOOL DeleteItemFromHashList(HashList hl,Item item)
{
	int hash_key,init_key;

	hash_key = init_key = HashDiv(item.carId);
	while(hl[hash_key].carId != 0 && hl[hash_key].carId != item.carId)
	{
		hash_key = (hash_key + 1) % MOD;
		if(init_key == hash_key)
		{
			break;
		}
	}
	if(hl[hash_key].carId == item.carId)
	{
		hl[hash_key].carId = 0;
		printf("已删除%d号码车辆数据.\n",item.carId);
		return true;
	}
	puts("删除失败");
	return false;
}