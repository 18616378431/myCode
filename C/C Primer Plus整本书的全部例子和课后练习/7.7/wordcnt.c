#include<stdio.h>
#include<ctype.h>		//Ϊisspace()�ṩ����ԭ��
#define bool int
#define TRUE 1
#define FALSE 0
#define STOP '|'

int main(void)
{
	char c;		//�����ַ�
	char prev;		//ǰһ�������ַ�
	long n_chars = 0L;		//�ַ���
	int n_lines = 0;		//����
	int n_words = 0;	//������
	int p_lines = 0;	//����������
	bool inword = FALSE;	//c��һ�������У�inwordΪtrue
	int hh = 0;		//ͳ�ƻ��з�����'\n'

	printf("Enter next to be analyzed(| to termate): \n");
	prev = '\n';		//����ʶ����������
	while((c = getchar()) != STOP)
	{
		if(c != ' ')		//c��Ϊ�հ��ַ�ʱ���ַ�������
		{
			n_chars++;		//ͳ���ַ�
		}
		if(c == '\n')
		{
			hh += 1;
			n_lines++;//ͳ����
		}
		if(!isspace(c) && !inword)		//cΪ�ַ�'w',isspace()Ϊ�٣�!isspace()Ϊ��
		{
			inword = TRUE;		//��ʼһ���µ���
			n_words++;		//ͳ�Ƶ���
		}
		if(isspace(c) && inword)		//������ַ�cΪ�ո񣬻��л��Ʊ��ʱ��isspace()Ϊ��
		{
			inword = FALSE;		//�ﵽ����β��
			prev = c;		//���β���ַ���Ϊ'\n',���ַ�������prev��
		}
	}
	if(prev != '\n')		//�����β���ַ���Ϊ'\n'ʱ�������һ����������
	{
		p_lines = 1;
	}

	printf("characters = %ld,words = %d,lines = %d,",n_chars - hh,n_words,n_lines);
	printf("partial lines = %d.\n",p_lines);
	return 0;
}