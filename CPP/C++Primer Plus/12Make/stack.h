//10.10 栈声明
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum{MAX = 10};
	//Item items[MAX];
	Item * pitems;
	int top;//栈顶索引
public:
	//构造函数
	Stack();
	//copy constructor
	Stack(const Stack & s);
	//析构函数
	~Stack();
	//判栈空
	bool isempty()const;
	//判栈满
	bool isfull()const;
	//压入,栈满返回false,否则返回true
	bool push(const Item & item);//添加元素到栈
	//弹出,栈空返回true,否则返回true
	bool pop(Item & item);//弹出栈顶元素到item
	//show
	void showContent();
	//overload
	Stack & Stack::operator= (const Stack & s);
};

#endif
