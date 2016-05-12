////a.程序打印打一个文件的第一行、第二个文件的第一行，第一个文件的第二行、第二个文件的第二行
////b.修改程序，将行号相同的打印到同一行上
////将文件内容按行存储在二维数组中
//#include<stdio.h>
//#include<stdlib.h>
//#define BUFSIZE 1024
//
//int main(int argc,char * argv[])
//{
//	FILE * fp1,* fp2;
//	static char f1[BUFSIZE];
//	static char f2[BUFSIZE];
//	int i = 0;//数组f1下标
//	int j = 0;//数组f2下标
//	int ct;
//
//	int e1,e2;
//	//判断命令行
//	if(argc < 2)
//	{
//		fprintf(stderr,"Usage:%s filename.\n",argv[0]);
//		exit(EXIT_FAILURE);
//	}
//	//打开文件以供读取
//	if((fp1 = fopen(argv[1],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[1]);
//		exit(EXIT_FAILURE);
//	}
//	//创建缓冲区
//	if(setvbuf(fp1,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buff.\n");
//	}
//	//打开文件以供读取
//	if((fp2 = fopen(argv[2],"r")) == NULL)
//	{
//		fprintf(stderr,"Can not open file %s.\n",argv[2]);
//		exit(EXIT_FAILURE);
//	}
//	//创建缓冲区
//	if(setvbuf(fp2,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Fail to create input buff.\n");
//	}
//	//将文件内容读入数组
//	/*for(i = 0;fscanf(fp1,"%s",f1[i]) > 0;i++)
//	{
//		;		
//	}
//	for(j = 0;fscanf(fp2,"%s",f2[j]) > 0;j++)
//	{
//		;
//	}*/
//	//printf("f1 %d,f2 %d.\n",i,j);
//	//交叉输出
//	//a.
//	//for(ct = 0;ct < (i > j?i:j);ct++)
//	//{
//	//	if(f1[ct] != NULL)
//	//	{
//	//		fputs(f1[ct],stdout);//fprintf(stdout,"%s\n",f1[ct]);
//	//		putchar('\n');
//	//	}
//	//	if(f2[ct] != NULL)
//	//	{
//	//		fputs(f2[ct],stdout);//fprintf(stdout,"%s",f2[ct]);
//	//	}
//	//	putchar('\n');
//	//}
//	//b.
//	/*for(ct = 0;ct < (i > j?i:j);ct++)
//	{
//		if(f1[ct] != NULL)
//			fprintf(stdout,"%s",f1[ct]);
//		if(f2[ct] != NULL)
//			fprintf(stdout,"%s",f2[ct]);
//		putchar('\n');
//	}*/
//	//fscanf()不读取换行
//	/*fscanf(fp1,"%s",temp);
//	fprintf(stdout,"%s",temp);*/
//	switch(argv[3][0])
//	{
//	case 'a':
//		while(1)
//		{
//			if((e1 = fscanf(fp1,"%s",f1)) == 1)
//				puts(f1);
//			if((e2 = fscanf(fp2,"%s",f2)) == 1)
//				puts(f2);
//			if(e1 != 1 && e2 != 1)
//				break;
//		}
//		break;
//	case 'b':
//		while(1)
//		{
//			if((e1 = fscanf(fp1,"%s",f1)) == 1)
//				printf("%s",f1);
//			if((e2 = fscanf(fp2,"%s",f2)) == 1)
//				printf("%s",f2);
//			putchar('\n');
//			if(e1 != 1 && e2 != 1)
//				break;
//		}
//		break;
//	}
//	//关闭文件
//	if(ferror(fp1) != 0 || ferror(fp2) != 0)
//	{
//		fprintf(stderr,"Error in reading files.\n");
//	}
//	if(fclose(fp1) != 0 || fclose(fp2) != 0)
//	{
//		fprintf(stderr,"Error in closing files.\n");
//	}
//	return 0;
//}