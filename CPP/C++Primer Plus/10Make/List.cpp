//8.
#include <iostream>
#include "List.h"

bool List::addItem(const Item & item)
{
	if(isFull())
		return false;
	items[count++] = item;
	return true;
}
bool List::isFull()const
{
	return count == MAX;
}
bool List::isEmpty()const
{
	return count == 0;
}
void List::visit(void (*pf)(Item &))
{
	for(int i = 0;i < count;i++)
		(*pf)(items[i]);
}
void List::show()const
{
	for(int i = 0;i < count;i++)
		std::cout << "i=" << i << ",item=" << items[i] << std::endl;
}