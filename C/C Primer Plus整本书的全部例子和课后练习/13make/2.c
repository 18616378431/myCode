////���Ƴ��򣬴������в������Դ�ļ���Ŀ���ļ���,argv[1]Ŀ���ļ���argv[2]Դ�ļ�
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define BUFSIZE 1024
//
//void file_copy(FILE *destination,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE *fa,*fs;
//	//�ж������в��������Ƿ���ȷ
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//��Ŀ���ļ��Թ�д��
//	if((fa = fopen(argv[1],"wb")) == NULL)
//	{
//		fprintf(stderr,"Can not open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//ΪĿ���ļ�����������
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Can not create output buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//�ж��Ƿ�Ϊͬһ���ļ�
//	if(strcmp(argv[1],argv[2]) == 0)
//	{
//		fprintf(stderr,"Can't copy file to itself.\n");
//		exit(EXIT_FAILURE);
//	}
//	if((fs = fopen(argv[2],"rb")) == NULL)
//	{
//		fprintf(stderr,"Can not open input file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	//ΪԴ�ļ�����������
//	if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Can't create input buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//ִ�и��ƺ���
//	file_copy(fa,fs);
//	if(ferror(fa) != 0)
//	{
//		fprintf(stderr,"Error in writing file %s.\n",argv[1]);
//	}
//	if(ferror(fs) != 0)
//	{
//		fprintf(stderr,"Error in reading file %s.\n",argv[2]);
//	}
//return 0;
//}
//void file_copy(FILE *destination,FILE * source)
//{
//	static char temp[BUFSIZE];
//	size_t bytes;
//
//	while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
//	{
//		fwrite(temp,sizeof(char),bytes,destination);
//	}
//}