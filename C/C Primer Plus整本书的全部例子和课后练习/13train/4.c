////接受一个命令行参数(存储全部为浮点数)或标准输入stdin，输入全部为浮点数，计算这些浮点数的算数平均值
//#include<stdio.h>
//#include<stdlib.h>//exit()
//#define ARRSIZE 10//数组大小
//
//int main(int argc,char * argv[])
//{
//	FILE * fp;
//	double numbers[ARRSIZE];
//	int i;//索引
//	double value;
//	double sum = 0;//数据总和
//	size_t bytes;
//
//	/************************************创建文件并写入浮点数数据**************************************/
//	//为浮点数数组赋值
//	for(i = 0;i < ARRSIZE;i++)
//	{
//		numbers[i] = i + 1;
//	}
//	//写模式打开文件以便将数组值写入文件
//	if((fp = fopen(argv[1],"wb")) == NULL)
//	{
//		fprintf(stderr,"Can not open output file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//缓冲区
//	if(setvbuf(fp,NULL,_IOFBF,ARRSIZE) != 0)
//	{
//		fprintf(stderr,"Can not create output buff.\n");
//		exit(EXIT_FAILURE);
//	}
//	//二进制模式将数组值写入文件中
//	fwrite(numbers,sizeof(double),ARRSIZE,fp);
//	//关闭文件
//	fclose(fp);
//	/************************************创建文件并写入浮点数数据**************************************/
//
//	/************************************从文件中获取浮点数数据**************************************/
//	//读模式打开文件
//	if((fp = fopen(argv[1],"rb")) == NULL)
//	{
//		fprintf(stderr,"Can not open input file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	i = 0;
//	while((bytes = fread(&value,sizeof(double),1,fp)) > 0)
//	{
//		//printf("%lf.\n",value);
//		sum += value;
//		fseek(fp,++i*sizeof(double),SEEK_SET);
//		
//	}
//	printf("数组大小为%d,数组值范围:%.2lf-%.2lf,算数平均值为:%lf.\n",
//						ARRSIZE,numbers[0],numbers[ARRSIZE - 1],sum/ARRSIZE);
//	if(ferror(fp) != 0)
//	{
//		fprintf(stderr,"Error in file.\n");
//		exit(EXIT_FAILURE);
//	}
//	fclose(fp);
//	/************************************从文件中获取浮点数数据**************************************/
//	return 0;
//}