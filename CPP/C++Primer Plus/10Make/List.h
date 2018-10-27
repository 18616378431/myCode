//8.
#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List
{
private:
	static const int MAX = 5;
	Item items[MAX];
	int count;
	bool isFull()const;
	bool isEmpty()const;
public:
	List(){count = 0;}
	bool addItem(const Item & item);
	void visit(void (*pf)(Item &));
	void show()const;
};

#endif