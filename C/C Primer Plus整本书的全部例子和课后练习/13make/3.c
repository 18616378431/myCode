////���Ƴ��������в�������Դ�ļ��е�Сд��ĸȫ��ת��Ϊ��д����Ŀ���ļ�ctype.h,�ı�ģʽ
////argv[1]Ŀ���ļ���argv[2]Դ�ļ�
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include<ctype.h>//toupper()
//#include<string.h>//strcmp()
//#define BUFSIZE 1024
//
//void file_copy(FILE * dest,FILE * source);
//
//int main(int argc,char * argv[])
//{
//	FILE * fa,* fs;
//	//�ж�������������Ƿ���ȷ
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//��Ŀ���ļ��Թ�д��
//	if((fa = fopen(argv[1],"w")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//ΪĿ���ļ�����������
//	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create output buff.\n");
//	}
//	//��Դ�ļ�
//	if((fs = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	else//Դ�ļ��򿪳ɹ�
//	{
//		if(strcmp(argv[1],argv[2]) == 0)//�Ƚ��Ƿ�Ϊͬһ���ļ�
//		{
//			fprintf(stderr,"Can't copy it to itself.\n");
//			exit(EXIT_FAILURE);
//		}
//		//ΪԴ�ļ�����������
//		if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
//		{
//			fprintf(stderr,"Fail to create input buff.\n");
//		}
//		file_copy(fa,fs);
//		if(ferror(fa) != 0)
//		{
//			fprintf(stderr,"Error in writing file.\n");
//		}
//		if(ferror(fs) != 0)
//		{
//			fprintf(stderr,"Error in reading file.\n");
//		}
//	}
//	//�ر��ļ�
//	fclose(fa);
//	fclose(fs);
//	return 0;
//}
////�ļ�����
//void file_copy(FILE * dest,FILE * source)
//{
//	char ch;
//	
//	while((ch = getc(source)) != EOF && ch != '\0')
//		putc(toupper(ch),dest);
//}