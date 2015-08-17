//�����ƴ�ȡ
#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 1000//double�����С

int main()
{
	double numbers[ARRSIZE];
	double value;//fread��ȡ��ֵ
	const char *file = "numbers.dat";
	int i;//����
	long pos;//�ļ�λ��
	FILE * iofile;//�ļ�ָ��

	//Ϊdouble����Ԫ�ظ�ֵ
	for(i = 0;i < ARRSIZE;i++)
	{
		numbers[i] = 100 * i + 1.0 / (i + 1);
	}
	//������дģʽ���ļ�
	if((iofile = fopen(file,"wb")) == NULL)
	{
		fprintf(stderr,"Could't open file %s for output.\n",file);
		exit(EXIT_FAILURE);
	}
	//�������е������Զ�����ģʽд���ļ�
	fwrite(numbers,sizeof(double),ARRSIZE,iofile);
	fclose(iofile);//�ر��ļ�
	//�Զ����ƶ�ȡģʽ���ļ�
	if((iofile = fopen(file,"rb")) == NULL)
	{
		fprintf(stderr,"Could not open %s for random access.\n",file);
		exit(EXIT_FAILURE);
	}
	//���ļ��ж�ȡ��ѡ��Ŀ
	printf("Enter index 0 - %d.\n",ARRSIZE - 1);
	while(scanf("%d",&i) == 1 && i >= 0 && i < ARRSIZE)
	{
		//����ƫ����
		pos = i * sizeof(double);
		//���ļ���ǰλ���ƶ���pos
		fseek(iofile,pos,SEEK_SET);
		//������ģʽ��ȡ��ǰλ�õ�����,�洢��value��
		fread(&value,sizeof(double),1,iofile);
		printf("The value there is %f.\n",value);
		printf("Next index(out of range to quit).\n");
	}
	return 0;
}