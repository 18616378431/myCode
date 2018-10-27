//15.5 nested class template
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
	enum{Q_SIZE=10};
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i):item(i),next(0){}
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP & q):qsize(0){}
	QueueTP & operator= (const QueueTP & q){return *this;}
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty()const
	{
		return items == 0;
	}
	bool isfull()const
	{
		return items == qsize;
	}
	int queuecount()const
	{
		return items;
	}
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs = Q_SIZE):qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node * temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node(item);
	if(add == NULL)
		return false;
	if(front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	items++;
	
	return true;
}
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if(front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if(items == 0)
		rear = NULL;

	return true;
}



#endif