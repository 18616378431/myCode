//ʵ���ļ�
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"interface.h"

//��ʼ��HashList
void InitHashList(HashList hl)
{
	int index;
	
	for(index = 0;index < HASH_MAX_SIZE;index++)
	{
		//��չؼ��ֳ��ƺ�
		hl[index].carId = 0;
	}
}
//���HASH�б�
void ClearHashList(HashList hl)
{
	int index;
	
	for(index = 0;index < HASH_MAX_SIZE;index++)
	{
		//��չؼ��ֳ��ƺ�
		hl[index].carId = 0;
		strcpy(hl[index].tradeMark,"");
		hl[index].flag = false;
	}
}
//������������ɢ�к���
int HashDiv(int carId)
{
	return carId % MOD;
}
//��Hash�б����Ԫ��
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
//��hash���в���Ԫ��
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
//��hash����ɾ��Ԫ��
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
		printf("��ɾ��%d���복������.\n",item.carId);
		return true;
	}
	puts("ɾ��ʧ��");
	return false;
}