////a.�����ӡ��һ���ļ��ĵ�һ�С��ڶ����ļ��ĵ�һ�У���һ���ļ��ĵڶ��С��ڶ����ļ��ĵڶ���
////b.�޸ĳ��򣬽��к���ͬ�Ĵ�ӡ��ͬһ����
////���ļ����ݰ��д洢�ڶ�ά������
//#include<stdio.h>
//#include<stdlib.h>
//#define BUFSIZE 1024
//
//int main(int argc,char * argv[])
//{
//	FILE * fp1,* fp2;
//	static char f1[BUFSIZE];
//	static char f2[BUFSIZE];
//	int i = 0;//����f1�±�
//	int j = 0;//����f2�±�
//	int ct;
//
//	int e1,e2;
//	//�ж�������
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//���ļ��Թ���ȡ
//	if((fp1 = fopen(argv[1],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//����������
//	if(setvbuf(fp1,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buff.\n");
//	}
//	//���ļ��Թ���ȡ
//	if((fp2 = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	//����������
//	if(setvbuf(fp2,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buff.\n");
//	}
//	//���ļ����ݶ�������
//	/*for(i = 0;fscanf(fp1,"%s",f1[i]) > 0;i++)
//	{
//		;		
//	}
//	for(j = 0;fscanf(fp2,"%s",f2[j]) > 0;j++)
//	{
//		;
//	}*/
//	//printf("f1 %d,f2 %d.\n",i,j);
//	//�������
//	//a.
//	//for(ct = 0;ct < (i > j?i:j);ct++)
//	//{
//	//	if(f1[ct] != NULL)
//	//	{
//	//		fputs(f1[ct],stdout);//fprintf(stdout,"%s\n",f1[ct]);
//	//		putchar('\n');
//	//	}
//	//	if(f2[ct] != NULL)
//	//	{
//	//		fputs(f2[ct],stdout);//fprintf(stdout,"%s",f2[ct]);
//	//	}
//	//	putchar('\n');
//	//}
//	//b.
//	/*for(ct = 0;ct < (i > j?i:j);ct++)
//	{
//		if(f1[ct] != NULL)
//			fprintf(stdout,"%s",f1[ct]);
//		if(f2[ct] != NULL)
//			fprintf(stdout,"%s",f2[ct]);
//		putchar('\n');
//	}*/
//	//fscanf()����ȡ����
//	/*fscanf(fp1,"%s",temp);
//	fprintf(stdout,"%s",temp);*/
//	switch(argv[3][0])
//	{
//	case 'a':
//		while(1)
//		{
//			if((e1 = fscanf(fp1,"%s",f1)) == 1)
//				puts(f1);
//			if((e2 = fscanf(fp2,"%s",f2)) == 1)
//				puts(f2);
//			if(e1 != 1 && e2 != 1)
//				break;
//		}
//		break;
//	case 'b':
//		while(1)
//		{
//			if((e1 = fscanf(fp1,"%s",f1)) == 1)
//				printf("%s",f1);
//			if((e2 = fscanf(fp2,"%s",f2)) == 1)
//				printf("%s",f2);
//			putchar('\n');
//			if(e1 != 1 && e2 != 1)
//				break;
//		}
//		break;
//	}
//	//�ر��ļ�
//	if(ferror(fp1) != 0 || ferror(fp2) != 0)
//	{
//		fprintf(stderr,"Error in reading files.\n");
//	}
//	if(fclose(fp1) != 0 || fclose(fp2) != 0)
//	{
//		fprintf(stderr,"Error in closing files.\n");
//	}
//	return 0;
//}