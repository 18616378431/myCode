//���ļ�ѹ��Ϊԭ��������֮һ
#include<stdio.h>
#include<stdlib.h>//����exit()
#include<string.h>//strcpy(),strcat()
#define LEN 40

int main(int argc,char * argv[])
{
	FILE * in;//Ҫ��ȡ��д����ļ���ָ��
	FILE * out;
	int ch;//�洢�ļ��ַ�
	char name[LEN];//�洢�ļ�����
	int count = 0;//�ַ�����

	//��������в���
	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//ʵ�����룬���ļ��Ա��ȡ
	if((in = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"Can not open file %s.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//ʵ����������ļ��Ա�д��
	strcpy(name,argv[1]);//�����ļ�����
	strcat(name,".red");//ƴ���ַ��������ļ�����֮�����.red��׺
	if((out = fopen(name,"w")) == NULL)
	{
		fprintf(stderr,"Can't create output file %s.\n",name);
		exit(EXIT_FAILURE);
	}
	printf("%s\n",name);
	//�����ַ�
	while((ch = getc(in)) != EOF)
	{
		if(count++ % 3 == 0)//��ӡÿ�����ַ��ĵ�һ��
		{
			putc(ch,out);
		}
	}
	//��β����,�ļ��رճɹ�����0�����򷵻�EOF
	if(fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr,"Error in closing files.\n");
	}
	return 0;
}