//��̬����һֱ�洢���ڴ��У�trystat()�е��Զ�����fadeÿ�ε���ʱ�����ѳ�ʼ��
#include<stdio.h>

void trystat();

int main()
{
	int count;

	for(count = 1;count <= 3;count++)
	{
		printf("Here comes interation %d\n",count);
		trystat();
	}
	return 0;
}

void trystat()
{
	int fade = 1;
	static int stay = 1;

	printf("fade = %d,stay = %d\n",fade++,stay++);
}