////�����в�����д13.6,����ļ�׷�ӵ�һ���ļ�,argv[1]Ŀ���ļ���argv[2]....Դ�ļ�
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include<string.h>//strcmp()
//#define BUFSIZE 1024
//
//void append(FILE * dest,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE * fa,* fs;
//	int files = 0;//��¼�ļ�����
//	int i = 2;//����
//
//	if(argc == 1)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//��Ŀ���ļ�
//	if((fa = fopen(argv[1],"w")) == NULL)
//	{
//		fprintf(stderr,"Can't open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//ΪĿ���ļ�����������
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create output buff.\n");
//	}
//	while(argv[i])
//	{
//		//�ж��Ƿ�Ϊͬһ�ļ�
//		if(strcmp(argv[i],argv[1]) == 0)
//		{
//			fprintf(stderr,"Can't append to itself.\n");
//			continue;
//		}
//		//��Դ�ļ��Թ���ȡ
//		if((fs = fopen(argv[i],"r")) == NULL)
//		{
//			fprintf(stderr,"Can not open input file %s.\n",argv[i]);
//			exit(EXIT_FAILURE);
//		}
//		//ΪԴ�ļ�����������
//		if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//		{
//			fprintf(stderr,"Can not create input buff.\n");
//			continue;
//		}
//		append(fa,fs);
//		if(ferror(fs) != 0)
//		{
//			fprintf(stderr,"Error in reading file.\n");
//		}
//		if(ferror(fa) != 0)
//		{
//			fprintf(stderr,"Error in writing file.\n");
//		}
//		files++;
//		fclose(fs);
//		printf("file %s appened.\n",argv[i]);
//		i++;
//	}
//	fclose(fa);
//	printf("%d files appended.\n",files);
//	printf("Done.\n");
//	return 0;
//}
////׷���ļ�
//void append(FILE * dest,FILE * source)
//{
//	static char temp[BUFSIZE];
//	size_t bytes;//�ɹ�������Ŀ����
//
//	while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
//	{
//		fwrite(temp,sizeof(char),bytes,dest);
//	}
//}