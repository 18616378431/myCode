////ջ�ӿ��ļ�
//#ifndef STACK_H_
//#define STACK_H_
//
//#define MAX 256
//
//#define BOOL int
//#define true 1
//#define false 0
//
//typedef char Item;
//
//typedef struct stack{
//	Item item[MAX];
//	int top;//��һ����λ������
//}Stack;
//
///*
//����:��ʼ��ջΪ��
//����ǰ:psָ��һ��ջ
//������:��ջ��ʼ��Ϊ��ջ
//*/
//void InitalizeStack(Stack * ps);
//
///*
//����:ȷ��ջ�Ƿ�Ϊ��
//����ǰ:psָ���ѳ�ʼ����ջ
//������:ջΪ�գ�����true�����򷵻�false
//*/
//BOOL StackIsEmpty(const Stack * ps);
//
///*
//����:ȷ��ջ�Ƿ�����
//����ǰ:psָ���ѳ�ʼ����ջ
//������:ջ��������true�����򷵻�false
//*/
//BOOL StackIsFull(const Stack * ps);
//
///*
//����:��ջ�����һ����Ŀ
//����ǰ:psָ���ѳ�ʼ����ջ��itemΪҪ��ӵ���Ŀ
//������:��ջ�����һ����Ŀ�����ջΪ�գ�����Ŀ��ӽ�ȥ������true�����ջ��������false
//*/
//BOOL Push(Item * item,Stack * ps);
//
///*
//����:��ջ��ɾ��һ����Ŀ
//����ǰ:psָ���ѳ�ʼ����ջ
//������:���ջ��Ϊ��,ɾ��ջ�������true������ò���ʹջΪ�գ�����ջΪ��;���ջ��ʼ��Ϊ�գ�����false
//*/
//BOOL Pop(Stack * ps);
//
///*
//����:���ջ
//����ǰ:psָ���ѳ�ʼ����ջ
//������:ջ�����
//*/
//void EmptyStack(Stack * ps);
//#endif