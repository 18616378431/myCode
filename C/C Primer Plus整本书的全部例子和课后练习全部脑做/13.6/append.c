//�Ѷ���ļ�����׷�ӵ�һ���ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024

//��������
void append(FILE * source,FILE * dest);

//�����в�����ʽ������ļ�����׷�ӵ�ͬһ�ļ�
int main(int argc,char * argv[])//argv[1]ΪĿ���ļ����ƣ�argv[2],3,4...ΪԴ�ļ�����
{
	FILE * fa,* fs;//faĿ���ļ���fsԴ�ļ�
	int files = 0;//׷�ӵ��ļ�����
	int i = 2;//Դ�ļ��������в�����argv�����±�2��ʼ��ȡ
	
	//׷��ģʽ��Ŀ���ļ�
	if((fa = fopen(argv[1],"a")) == NULL)
	{
		fprintf(stderr,"Error opening file %s.\n",argv[1]);
		exit(1);
	}
	//ΪĿ���ļ�����1024������,bufΪNULL�������Զ�Ϊ�Լ����仺����
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Can't create ouput buff.\n");
		exit(2);
	}
	//ѭ����ȡ����Դ�ļ�����
	while(argv[i] && argv[i][0] != '\0')
	{
		//�ж�Դ�ļ���Ŀ���ļ������Ƿ���ͬ
		if(strcmp(argv[1],argv[i]) == 0)
		{
			fputs("Can't append file to itself.\n",stderr);
		}
		else if((fs = fopen(argv[i],"r")) == NULL)//��Դ�ļ�
		{
			fprintf(stderr,"Can't open file %s.\n",argv[i]);
		}
		else
		{
			//ΪԴ�ļ����û�����
			if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
			{
				fprintf(stderr,"Can't create input buff");
				continue;
			}
			//
			append(fs,fa);
			if(ferror(fs) != 0)
			{
				fprintf(stderr,"Error in reading file %s.\n",argv[i]);
			}
			if(ferror(fa) != 0)
			{
				fprintf(stderr,"Error in writing file %s.\n",argv[1]);
			}
			//�رյ�ǰԴ�ļ�
			fclose(fs);
			files++;
			printf("File %s appended.\n",argv[i]);
			i++;
		}
	}
	printf("Done.%d files appended.\n",files);
	//�ر�Ŀ���ļ�
	return 0;
}
//fread(),fwrite()ÿ�θ���1024�ֽ�
void append(FILE * source,FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];//����һ�Σ��洢��ȡ���ַ�

	if((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
	{
		fwrite(temp,sizeof(char),bytes,dest);
	}
}