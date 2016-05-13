//˳���洢�ṹ��ѧ���ϻ�����ϵͳ
#ifndef HOME1_H_
#define HOME1_H_

//#include<stdbool.h>

#define bool int
#define true 1
#define false 0

#define MAXSIZE 100
#define NAMESIZE 256

typedef struct item{
	int stuId;
	char name[NAMESIZE];
}Item;

/*
����:����ձ�
����ǰ:seqLenΪ˳�����
������:����������Ϊ0
*/
void InitalizeSeq(int * seqLen);
/*
����:�ж�˳����Ƿ�����
����ǰ:seqLenΪ��ǰ˳�����
������:����������true�����򷵻�false
*/
bool SeqIsFull(const int * seqLen);
/*
����:�ж�˳����Ƿ�Ϊ��
����ǰ:seqLenΪ��ǰ˳�����
������:Ϊ�գ�����true�����򷵻�false
*/
bool SeqIsEmpty(const int * seqLen);
/*
����:����Ԫ�أ�β��
����ǰ:pSeqָ��˳�������,seqLenΪ��ǰ˳�����,tempΪ��Ҫ�����Ԫ��
������:������ĩβ���һ��Ԫ�أ�����ɹ�������true�����򷵻�false
*/
bool AddItem(Item * pSeq,int * seqLen,const Item * temp);
/*
����:����ָ��Ԫ��
����ǰ:pSeqָ��˳���tempΪ������Ԫ��
������:�ҵ�Ŀ��Ԫ�أ�����true�����򷵻�false������ʾ��Ϣ
*/
bool SeekItem(Item * pSeq,int * seqLen, Item temp);
/*
����:ɾ��˳���ĵ�i��Ԫ��
����ǰ:pSeqָ��˳���iΪҪɾ����Ԫ��
������:���Ԫ��i�ڱ��У�ִ��ɾ������������true�����򷵻�false
*/
bool DeleteItem(Item * pSeq,int * seqLen,int i);
/*
����:������Ա�
����ǰ:seqLenΪ˳�����
������:��˳�������Ϊ0
*/
void EmptyList(int * seqLen);
/*
����:��ָ������������˳���
����ǰ:pSeqָ��һ��˳�������
������:��ָ������������˳����е�ÿһ��Ԫ��
*/
void Traverse(Item * pSeq,int * seqLen,void (*pfun)(Item item));
#endif