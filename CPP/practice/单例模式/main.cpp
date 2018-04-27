//测试单元素模式
#include <iostream>
#include "TheOnlyInstance.h"

using namespace std;

int main()
{
	TheOnlyInstance *p1TheOnlyInstance = TheOnlyInstance::GetTheOnlyInstance();
	TheOnlyInstance *p2TheOnlyInstance = TheOnlyInstance::GetTheOnlyInstance();
	TheOnlyInstance *p3TheOnlyInstance = TheOnlyInstance::GetTheOnlyInstance();

	cout << "sizeof(TheOnlyInstance) = " << sizeof(TheOnlyInstance) << endl;
	return 0;
}