//12.11 队列实现
#include "queue.h"
#include <cstdlib>

//Queue methods
Queue::Queue(int qs):qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
Queue::~Queue()
{
	Node * temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty()const
{
	return items == 0;
}
bool Queue::isfull()const
{
	return items == qsize;
}
int Queue::queuecount()const
{
	return items;
}
//add item to queue
bool Queue::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node;
	if(add == NULL)
		return false;
	add->item = item;
	add->next = NULL;
	items++;
	if(front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
//place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
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
//Customer method
//when is arrival time,processing time set to a random value int the range 1-3
void Customer::set(long when)
{
	arrive = when;
	processtime = std::rand() % 3 + 1;
}
