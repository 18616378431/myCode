//包含20行30个整数的文件，读取内容到20x30的int型数组，用int数组初始化20x31的字符阵列
//0代表空格、1代表句号、2代表单引号、3代表:、4代表~、5代表*、6等号=、8代表%、9代表#
//添加尖峰脉冲函数
//函数将每一个值和它的上下左右相邻值比较，如果和周围每个值的差都大于1，则将该值改为所有相邻值的平均值
//注意边界数值
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

	//打开文件
	if((fp = fopen("data","r+")) == NULL)
	{
		fprintf(stderr,"Can't open file \"data\".\n");
		exit(EXIT_FAILURE);
	}
	//创建缓冲区
	if(setvbuf(fp,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Fail to create input buff.\n");
	}
	//初始化文件createFile(fp);
	//读取字符串
	while(fgets(show[i++],3*COLUMN,fp) != NULL)
	{
		;
	}
	//输出数组元素
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
//消除尖峰脉冲,多维数组传递,char (* p)[SIZE],char ar[][SIZE],char [][SIZE]
void delPulse(char (* str)[3*COLUMN])
{
	int i,j;
	//上下左右差值,可以讲上下左右差值计算封装成函数，str,i,j,返回int差值
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	//遍历字符串数组
	for(i = 0;i < LINE;i++)
	{
		for(j = 0;j < 2*COLUMN;j += 2)
		{
			//左上
			if(i == 0 && j == 0)
			{
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((down > 1 || down < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(up,str[i + 1][j],left,str[i][j + 2],2);
				}
			}
			//右上
			else if(i == 0 && j == 58)
			{
				down = getReduce(getInt(str[i][j]),getInt(str[i + 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				if((down >1 || down < -1) && (left > 1 || left < -1))
				{
					str[i][j] = getAvg(up,str[i + 1][j],str[i][j - 2],right,2);
				}
			}
			//左下
			else if(i == 19 && j == 0)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				right = getReduce(getInt(str[i][j]),getInt(str[i][j + 2]));
				if((up > 1 || up < -1) && (right > 1 || right < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],down,left,str[i][j + 2],2);
				}
			}
			//右下
			else if(i == 19 && j == 58)
			{
				up = getReduce(getInt(str[i][j]),getInt(str[i - 1][j]));
				left = getReduce(getInt(str[i][j]),getInt(str[i][j - 2]));
				if((up > 1 || up < -1) && (left > 1 || left < -1))
				{
					str[i][j] = getAvg(str[i - 1][j],down,str[i][j - 2],right,2);
				}
			}
			//上边界
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
			//下边界
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
			//左边界
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
			//右边界
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
			//中间部分
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
//计算字符的int值
int getInt(char ch)
{
	return ch - '0';
}
//计算差值
int getReduce(int a,int b)
{
	return a - b;
}
//计算平均值
char getAvg(int up,int down,int left,int right,int deno)
{
	char avg;
	
	avg = (up + down + left + right) / deno;
	return avg;
}

//生成文件
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
	int i,j;//数组循环

	//将int数组写入文件
	for(i = 0;i < LINE;i++)
	{
		for(j = 0;j < COLUMN;j++)
		{
			fprintf(fp,"%d ",init[i][j]);
		}
		fprintf(fp,"\n");
	}
}