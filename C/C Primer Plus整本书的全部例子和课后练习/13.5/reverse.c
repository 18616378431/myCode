//�����ȡ
#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'

int main(int argc,char * argv[])//ͨ�������в��������ļ�
{
	char ch;//�洢�ļ��ַ�
	FILE *fp;
	long count,last;//�ַ�λ�ü������ļ�ĩβ����

	if((fp = fopen(argv[1],"rb")) == NULL)
	{
		printf("Error open %s file.\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	//��λ���ļ�ĩβ
	fseek(fp,0L,SEEK_END);
	last = ftell(fp);//�����ļ�ָ�뵱ǰλ��
	for(count = 1L;count <= last;count++)
	{
		fseek(fp,-count,SEEK_END);
		ch = getc(fp);
		//���DOS�£�UNIXҲ���Թ���
		if(ch != CNTL_Z && ch != '\r')
		{
			putchar(ch);
		}
		//���Macintosh
		/*if(ch == '\r')
		{
			putchar('\n');
		}
		else
		{
			putchar(ch);
		}*/
	}
	putchar('\n');
	//�ر��ļ�
	if(fclose(fp) != 0)
	{
		fprintf(stderr,"Error closing file.\n");
	}
	return 0;
}