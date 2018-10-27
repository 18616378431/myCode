//review 4
#ifndef REVIEW4_H_
#define REVIEW4_H_

//class Stack1<Worker *>
class Stack1
{
private:
	enum{MAX=3};
	Worker * items[MAX];
	int top;
public:
	Stack1();
	bool isempty();
	bool isfull();
	bool push(const Worker * & item);
	bool pop(Worker * & item);
};

#endif