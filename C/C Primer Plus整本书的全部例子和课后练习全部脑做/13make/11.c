////�����г��򣬵�һ������Ϊ�ַ������ڶ�������Ϊ�ļ���
////���ļ��в��ҵ�һ���ַ������У�����ӡ
//#include<stdio.h>
//#include<string.h>//strstr()
//#include<stdlib.h>
//#define SIZE 256
//
//int main(int argc,char * argv[])
//{
//	FILE * fp;
//	char temp[SIZE];
//
//	if(argc < 3)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	if((fp = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	while(fgets(temp,SIZE,fp) != NULL)//���ж�ȡ����ȡ���з�
//		if(strstr(temp,argv[1]) != NULL)
//			fputs(temp,stdout);
//	return 0;
//}