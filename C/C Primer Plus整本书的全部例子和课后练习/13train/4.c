////����һ�������в���(�洢ȫ��Ϊ������)���׼����stdin������ȫ��Ϊ��������������Щ������������ƽ��ֵ
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#define ARRSIZE 10//�����С
//
//int main(int argc,char * argv[])
//{
//	FILE * fp;
//	double numbers[ARRSIZE];
//	int i;//����
//	double value;
//	double sum = 0;//�����ܺ�
//	size_t bytes;
//
//	/************************************�����ļ���д�븡��������**************************************/
//	//Ϊ���������鸳ֵ
//	for(i = 0;i < ARRSIZE;i++)
//	{
//		numbers[i] = i + 1;
//	}
//	//дģʽ���ļ��Ա㽫����ֵд���ļ�
//	if((fp = fopen(argv[1],"wb")) == NULL)
//	{
//		fprintf(stderr,"Can not open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//������
//	if(setvbuf(fp,NULL,_IOFBF,ARRSIZE) != 0)
//	{
//		fprintf(stderr,"Can not create output buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//������ģʽ������ֵд���ļ���
//	fwrite(numbers,sizeof(double),ARRSIZE,fp);
//	//�ر��ļ�
//	fclose(fp);
//	/************************************�����ļ���д�븡��������**************************************/
//
//	/************************************���ļ��л�ȡ����������**************************************/
//	//��ģʽ���ļ�
//	if((fp = fopen(argv[1],"rb")) == NULL)
//	{
//		fprintf(stderr,"Can not open input file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	i = 0;
//	while((bytes = fread(&value,sizeof(double),1,fp)) > 0)
//	{
//		//printf("%lf.\n",value);
//		sum += value;
//		fseek(fp,++i*sizeof(double),SEEK_SET);
//		
//	}
//	printf("�����СΪ%d,����ֵ��Χ:%.2lf-%.2lf,����ƽ��ֵΪ:%lf.\n",
//						ARRSIZE,numbers[0],numbers[ARRSIZE - 1],sum/ARRSIZE);
//	if(ferror(fp) != 0)
//	{
//		fprintf(stderr,"Error in file.\n");
//		exit(EXIT_FAILURE);
//	}
//	fclose(fp);
//	/************************************���ļ��л�ȡ����������**************************************/
//	return 0;
//}