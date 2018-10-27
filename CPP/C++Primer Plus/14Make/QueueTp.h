//3. QueueTp

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class T>
class QueueTp
{
private:
	enum{MAX=10};
	int len;
	T * data;
	int top;
public:
	QueueTp()
	{
		len = MAX;
		top = 0;
		data = new T[len];
	}
	QueueTp(int l):len(l)
	{
		top = 0;
		data = new T[len];
	}
	~QueueTp()
	{
		delete [] data;
	}
	bool Push(T item);
	bool Pop();
	T & front()const;
	T & rear()const;
	bool isFull()const{return top == len;}
	bool isEmpty()const{return top == 0;}
};
template <class T>
bool QueueTp<T>::Push(T item)
{
	if(isFull())
		return false;
	for(int i = top;i > 0;i--)
		data[i] = data[i - 1];
	data[0] = item;
	top++;
	return true;
}
template <class T>
bool QueueTp<T>::Pop()
{
	if(isEmpty())
		return false;
	top--;
	return true;
}
template <class T>
T & QueueTp<T>::front()const
{
	return data[top - 1];
}
template <class T>
T & QueueTp<T>::rear()const
{
	return data[0];
}


#endif