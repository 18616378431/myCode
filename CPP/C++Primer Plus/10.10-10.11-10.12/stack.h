//10.10 ջ����
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum{MAX = 10};
	Item items[MAX];
	int top;//ջ������
public:
	//���캯��
	Stack();
	//��ջ��
	bool isempty()const;
	//��ջ��
	bool isfull()const;
	//ѹ��,ջ������false,���򷵻�true
	bool push(const Item & item);//���Ԫ�ص�ջ
	//����,ջ�շ���true,���򷵻�true
	bool pop(Item & item);//����ջ��Ԫ�ص�item
};

#endif
