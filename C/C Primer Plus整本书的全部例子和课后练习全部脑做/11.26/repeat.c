#include<stdio.h>
//���в�����main����,������������
//argv[0]ָ��ǰ����argv[1]ָ���һ���������Դ�����
int main(int argc,char *argv[])
{
	int count;

	printf("The command line has %d arguments.\n",argc - 1);
	for(count = 1;count < argc;count++)
	{
		printf("%d:%s\n",count,argv[count]);
	}
	printf("\n");
	return 0;
}