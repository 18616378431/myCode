//����20��30���������ļ�����ȡ���ݵ�20x30��int�����飬��int�����ʼ��20x31���ַ�����
//0����ո�1�����š�2�������š�3����:��4����~��5����*��6�Ⱥ�=��8����%��9����#
//��Ӽ�����庯��
//������ÿһ��ֵ������������������ֵ�Ƚϣ��������Χÿ��ֵ�Ĳ����1���򽫸�ֵ��Ϊ��������ֵ��ƽ��ֵ
//ע��߽���ֵ
#include<stdio.h>
#include<stdlib.h>//exit()
#include<ctype.h>//itoa()
#define LINE 20
#define COLUMN 30
#define BUFSIZE 1024

void createFile(FILE * fp);
void delPulse(char str[][3*COLUMN]);
int getInt(char ch);
int getReduce(int a,int b);
char getAvg(int up,int down,int left,int right,int deno);

int main()
{
	FILE * fp;
	char show[LINE][3*COLUMN];
	int i = 0;
	int j  =0;

	//���ļ�
	if((fp = fopen("data","r+")) == NULL)
	{
		fprintf(stderr,"Can't open file \"data\".\n");
		exit(EXIT_FAILURE);
	}
	//����������
	if(setvbuf(fp,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//��ʼ���ļ�createFile(fp);
	//��ȡ�ַ���
	while(fgets(show[i++],3*COLUMN,fp) != NULL)
	{
		;
	}
	//�������Ԫ��
	//for(i = 0;i < LINE;i++)
	//	fputs(show[i],stdout);
	//putchar('\n');
	delPulse(show);
	/*for(i = 0;i < LINE;i++)
	{
		puts(show[i]);
	}
	return 0;*/
	for(i = 0;i < LINE;i++)
	{
		for(j = 0;j < 2*COLUMN;j++)
		{
			switch(show[i][j])
			{
			case '0':printf(" ");break;
			case '1':printf(".");break;
			case '2':printf("'");break;
			case '3':printf(":");break;
			case '4':printf("~");break;
			case '5':printf("*");break;
			case '6':printf("=");break;
			case '8':printf("%%");break;
			case '9':printf("#");break;
			}
		}
		putchar('\n');
	}
	if(ferror(fp) != 0)
	{
		fprintf(stderr,"Error in reading file\"data\".\n");
	}
	if(fclose(fp) != 0)
	{
		fprintf(stderr,"Error in closing file \"data\".\n");
	}
	puts("Done");
	return 0;
}
//�����������,��ά���鴫��,char (* p)[SIZE],char ar[][SIZE],char [][SIZE]
void delPulse(char (* str)[3*COLUMN])
{
	int i,j;
	//�������Ҳ�ֵ,���Խ��������Ҳ�ֵ�����װ�ɺ�����str,i,j,����int��ֵ
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	//�����ַ�������
	for(i = 0;i < LINE;i++)
	{
		for(j = 0;j < 2*COLUMN;j += 2)
		{
			//����
			if(i == 0 && j == 0)
			{
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((down > 1 || down < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(up,str[i + 1][j],left,str[i][j + 2],2);
				}
			}
			//����
			else if(i == 0 && j == 58)
			{
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				if((down >1 || down < -1) && (left > 1 || left < -1))
				{
					str[i][j] = getAvg(up,str[i + 1][j],str[i][j - 2],right,2);
				}
			}
			//����
			else if(i == 19 && j == 0)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((up > 1 || up < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],down,left,str[i][j + 2],2);
				}
			}
			//����
			else if(i == 19 && j == 58)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				if((up > 1 || up < -1) && (left > 1 || left < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],down,str[i][j - 2],right,2);
				}
			}
			//�ϱ߽�
			else if(i == 0 && j != 0 && j != 58)
			{
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((down >1 || down < -1) && (left > 1 || left < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(up,str[i + 1][j],str[i][j - 2],str[i][j + 2],3);
				}
			}
			//�±߽�
			else if(i == 19 && j != 0 && j != 58)
			{
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((down >1 || down < -1) && (left > 1 || left < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(up,str[i - 1][j],str[i][j - 2],str[i][j + 2],3);
					
				}
			}
			//��߽�
			else if(i != 0 && i != 19 && j == 0)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				if((up >1 || up < -1) && (right > 1 || right < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],str[i + 1][j],left,str[i][j + 2],3);
				}
			}
			//�ұ߽�
			else if(i != 0 && i != 19 && j == 58)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				if((up >1 || up < -1) && (left > 1 || left < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],str[i + 1][j],str[i][j - 2],right,3);
				}
			}
			//�м䲿��
			if(i != 0 && i != 19 && j != 0 && j != 58)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((up >1 || up < -1) && (down > 1 || down < -1) && (left > 1 || left < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],str[i + 1][j],str[i][j - 2],str[i][j + 2],4);
				}
			}
		}
	}
}
//�����ַ���intֵ
int getInt(char ch)
{
	return ch - '0';
}
//�����ֵ
int getReduce(int a,int b)
{
	return a - b;
}
//����ƽ��ֵ
char getAvg(int up,int down,int left,int right,int deno)
{
	char avg;
	
	avg = (up + down + left + right) / deno;
	return avg;
}

//�����ļ�
void createFile(FILE * fp)
{
	int init[LINE][COLUMN] = {
		{0,0,9,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,2,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,9,0,0,0,0,0,0,0,5,8,9,9,8,5,5,2,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,1,9,8,5,4,5,2,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,9,0,0,0,0,0,0,0,5,8,9,9,8,5,0,4,5,2,0,0,0,0,0,0,0,0},
		{0,0,9,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,4,5,2,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,1,8,5,0,0,0,4,5,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,4,5,2,0,0,0,0,0},
		{5,5,5,5,5,5,5,5,5,5,5,5,5,8,9,9,8,5,5,5,5,5,5,5,5,5,5,5,5,5},
		{8,8,8,8,8,8,8,8,8,8,8,8,5,8,9,9,8,5,8,8,8,8,8,8,8,8,8,8,8,8},
		{9,9,9,9,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,3,9,9,9,9,9,9,9},
		{8,8,8,8,8,8,8,8,8,8,8,8,5,8,9,9,8,5,8,8,8,8,8,8,8,8,8,8,8,8},
		{5,5,5,5,5,5,5,5,5,5,5,5,5,8,9,9,8,5,5,5,5,5,5,5,5,5,5,5,5,5},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,6,6,0,0,0,0,0,0},
		{0,0,0,0,2,2,0,0,0,0,0,0,5,8,9,9,8,5,0,0,5,6,0,0,6,5,0,0,0,0},
		{0,0,0,0,3,3,0,0,0,0,0,0,5,8,9,9,8,5,0,5,6,1,1,1,1,6,5,0,0,0},
		{0,0,0,0,4,4,0,0,0,0,0,0,5,8,9,9,8,5,0,0,5,6,0,0,6,5,0,0,0,0},
		{0,0,0,0,5,5,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,6,6,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,5,8,9,9,8,5,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	int i,j;//����ѭ��

	//��int����д���ļ�
	for(i = 0;i < LINE;i++)
	{
		for(j = 0;j < COLUMN;j++)
		{
			fprintf(fp,"%d ",init[i][j]);
		}
		fprintf(fp,"\n");
	}
}