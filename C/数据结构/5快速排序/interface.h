//�ӿ�
//��������ϵͳ��������
//˳���ʵ��
#ifndef INTERFACE_H_
#define INTERFACE_H_

#define BOOL int
#define true 1
#define false 0

#define tradeNameLen 30

typedef struct item{
	int carId;
	char tradeMark[tradeNameLen];
	BOOL flag;
}Item;

typedef struct list{
	Item item;
}List;

/*
����:��������˳���,�����㷨
����ǰ:pListָ���ʼ����˳���
������:����˳���
*/
int partition(List * pList,int low,int high);
/*
����:�ݹ���ÿ�������
����ǰ:pListָ���ʼ����˳���
������:��������˳���
*/
void quickSort(List * pList,int low,int high);
#endif