#ifndef 5ADT_H_
#define 5ADT_H_

/*BOOL����C���Զ���*/
#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAXSTACK 100

typedef int Item;

typedef struct stack{
	Item item[MAXSTACK];
	int top;//��һ����λ������
}Stack;

/*
����:��ջ��ʼ��Ϊ��
����ǰ:psָ��ջ
������:ջ����ʼ��Ϊ��
*/
void InitalizeStack(Stack * ps);
/*
����:ȷ��ջ�Ƿ�Ϊ��
����ǰ:psָ���ѳ�ʼ����ջ
������:Ϊ�գ�����true�����򷵻�false
*/
BOOL StackIsEmpty(const Stack * ps);
/*
����:ȷ��ջ�Ƿ�����
����ǰ:psָ���ѳ�ʼ����ջ
������:����������true�����򷵻�false
*/
BOOL StackIsFull(const Stack * ps);
/*
����:��ջ�����һ��
����ǰ:psָ���ѳ�ʼ����ջ��itemΪҪ�ŵ�ջ������Ŀ
������:���ջ��Ϊ�գ���item�ŵ�ջ��������true�����򣬷���false
*/
BOOL Push(Item item,Stack * ps);
/*
����:��ջ��ɾ��һ��
����ǰ:psָ���ѳ�ʼ����ջ
������:���ջ��Ϊ�գ���ջ����Ŀ��ֵ��pitem����ɾ��������true������ò�����ʹջΪ�գ�����ջ;���ջ��ʼ��λ�գ���������false
*/
BOOL Pop(Stack * ps,Item * pItem);
/*
����:���ջ
����ǰ:psָ���ѳ�ʼ����ջ
������:���ջ��Ϊ�գ����ջ��Ϊ���򲻽����κβ���
*/
void EmptyStack(Stack * ps);
#endif