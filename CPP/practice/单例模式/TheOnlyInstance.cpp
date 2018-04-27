//单元素模式 实现
#include "TheOnlyInstance.h"

TheOnlyInstance * TheOnlyInstance::GetTheOnlyInstance()
{
	static TheOnlyInstance objTheOnlyInstance;
	return &objTheOnlyInstance;
}