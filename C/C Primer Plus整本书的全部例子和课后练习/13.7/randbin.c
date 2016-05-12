//二进制存取
#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 1000//double数组大小

int main()
{
	double numbers[ARRSIZE];
	double value;//fread读取的值
	const char *file = "numbers.dat";
	int i;//索引
	long pos;//文件位置
	FILE * iofile;//文件指针

	//为double数组元素赋值
	for(i = 0;i < ARRSIZE;i++)
	{
		numbers[i] = 100 * i + 1.0 / (i + 1);
	}
	//二进制写模式打开文件
	if((iofile = fopen(file,"wb")) == NULL)
	{
		fprintf(stderr,"Could't open file %s for output.\n",file);
		exit(EXIT_FAILURE);
	}
	//将数组中的数据以二进制模式写入文件
	fwrite(numbers,sizeof(double),ARRSIZE,iofile);
	fclose(iofile);//关闭文件
	//以二进制读取模式打开文件
	if((iofile = fopen(file,"rb")) == NULL)
	{
		fprintf(stderr,"Could not open %s for random access.\n",file);
		exit(EXIT_FAILURE);
	}
	//从文件中读取所选项目
	printf("Enter index 0 - %d.\n",ARRSIZE - 1);
	while(scanf("%d",&i) == 1 && i >= 0 && i < ARRSIZE)
	{
		//计算偏移量
		pos = i * sizeof(double);
		//将文件当前位置移动至pos
		fseek(iofile,pos,SEEK_SET);
		//二进制模式读取当前位置的数据,存储到value中
		fread(&value,sizeof(double),1,iofile);
		printf("The value there is %f.\n",value);
		printf("Next index(out of range to quit).\n");
	}
	return 0;
}