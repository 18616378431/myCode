////����ʽ��ȡ�ı��ļ�����
////ѭ����ȡ�ļ�λ��
////��ӡ�Ӹ�λ�õ����з�֮�������
////�������ַ���ֹѭ��
//#include<stdio.h>
//#include<stdlib.h>
//#define SIZE 41
//#define LINESIZE 256
//
//int main()
//{
//	FILE * fp;
//	char filename[SIZE];
//	int pos;//�ļ�λ��
//	char ch[LINESIZE];
//
//	puts("Enter filename:");
//	gets(filename);
//	if((fp = fopen(filename,"r")) == NULL)
//	{
//		fprintf(stderr,"Can't open file %s.\n",filename);
//		exit(EXIT_FAILURE);
//	}
//	puts("Position:");
//	while(scanf("%d",&pos) == 1)//���з�ռ�ֽڣ����л��е��ı��±겻׼
//	{
//		fseek(fp,pos - 1,SEEK_SET);//���ļ�ָ���ƶ��������ļ���ʼpos��λ��
//		fscanf(fp,"%s",ch);
//		puts(ch);
//		puts("Position(q to quit):");
//	}
//	return 0;
//}