//fprintf(),fscanf(),rewind()����ʹ��
#include<stdio.h>
#include<stdlib.h>//exit()ԭ��
#define MAX 40

int main()
{
	FILE * fp;
	char words[MAX];
	//�򿪲������ļ��Թ���д
	if((fp = fopen("words","a+")) == NULL)//�Կɶ�д׷��ģʽ���ļ����ļ��������򴴽�
	{
		fprintf(stdout,"Can't open \"words\" file.");
		exit(EXIT_FAILURE);
	}
	printf("Enter words to add to file.\n");
	while(gets(words) != NULL && words[0] != '\0')//���ļ���д������
	{
		fprintf(fp,"%s",words);
	}
	puts("File contents.");
	rewind(fp);//���ļ�ָ�����õ��ļ���ʼ��
	while(fscanf(fp,"%s",words) == 1)
	{
		puts(words);
	}
	//�ر��ļ�
	if((fclose(fp)) != 0)//0Ϊ�رճɹ�������EOFʧ��
	{
		fprintf(stderr,"Error Closing file.\n");
	}
	return 0;
}