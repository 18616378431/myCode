//��Ԫ��ģʽ ʵ��
#include "TheOnlyInstance.h"

TheOnlyInstance * TheOnlyInstance::GetTheOnlyInstance()
{
	static TheOnlyInstance objTheOnlyInstance;
	return &objTheOnlyInstance;
}