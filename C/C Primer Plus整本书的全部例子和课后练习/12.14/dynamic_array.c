//Ϊ���鶯̬����洢�ռ�
#include<stdio.h>
#include<stdlib.h>//malloc(),free()�ṩԭ��

int main()
{
	double * ptd;//ָ�������ڴ���׵�ַ
	int max;
	int number;
	int i = 0;
	//��ȡ������Ҫ��Ԫ��������
	printf("What is the maximum number of type double entries?\n");
	scanf("%d",&max);
	//Ϊ����̬�����ڴ�ռ䲢��������
	ptd = (double *)malloc(max * sizeof(double));//����һ��max��doubleֵ��С���ڴ��,�����׵�ַ����ptd
	if(ptd == NULL)//�ڴ����ʧ�ܣ������쳣��ֹ
	{
		printf("Memory allocation failed.Goodbye!\n");
		exit(EXIT_FAILURE);//EXIT_FAILURE 1
	}
	//Ϊ����Ԫ�ظ�ֵ
	printf("Enter the values(q to quit):");
	while(i < max && scanf("%lf",&ptd[i]) == 1)
	{
		++i;
	}
	//����Ԫ�ظ���
	printf("Here are your %d entries.\n",number = i);
	//�������Ԫ��
	for(i = 0;i < number;i++)
	{
		printf("%7.2f ",ptd[i]);
		if(i % 7 == 6)
		{
			putchar('\n');
		}
	}
	if(i % 7 != 0)
	{
		putchar('\n');
	}
	puts("Done.");
	free(ptd);
	return 0;
}