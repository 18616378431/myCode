//a.�����ӡ��һ���ļ��ĵ�һ�С��ڶ����ļ��ĵ�һ�У���һ���ļ��ĵڶ��С��ڶ����ļ��ĵڶ���
//b.�޸ĳ��򣬽��к���ͬ�Ĵ�ӡ��ͬһ����
//���ļ����ݰ��д洢�ڶ�ά������
#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 1024

int main(int argc,char * argv[])
{
	FILE * fp1,* fp2;
	char  f1[BUFSIZE];
	char  f2[BUFSIZE];
	int i;//�����±�
	//�ж�������
	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//���ļ��Թ���ȡ
	if((fp1 = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//����������
	if(setvbuf(fp1,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//���ļ��Թ���ȡ
	if((fp2 = fopen(argv[2],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	//����������
	if(setvbuf(fp2,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//���ļ����ݶ�������
	//putc(getc(fp1),stdout);
	/*i = 0;
	while(fgets(f2[i],BUFSIZE,fp2))
	{
		i++;
	}*/
	//fscanf()����ȡ����
	/*fscanf(fp1,"%s",temp);
	fprintf(stdout,"%s",temp);*/
	
	return 0;
}