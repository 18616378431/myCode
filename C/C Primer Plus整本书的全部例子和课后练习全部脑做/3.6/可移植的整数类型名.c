//����ֲ������������
#include<stdio.h>
#include<inttypes.h>
#include<limits.h>

int main(void)
{
	int16_t me16;	//����һ��16λ�з��ű���
	printf("First,assume int16_t is short:");
	printf("me16 = %hd \n",me16);
	printf("Not make any assumption \n");
	printf("Use a \"macro\" from inttypes.h:");
	printf("me16 = %" PRId16 " \n",me16);
	return 0;
}