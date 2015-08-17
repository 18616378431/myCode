//#include<stdio.h>
//#include<stdlib.h>//exit()
//#include"6.h"
//#define SIZE 6
//#define BUFSIZE 1024
//
//void createFile(void);
//
//int main()
//{
//	FILE * fp;
//	BASEBALL base[SIZE];
//	int i = 0,j,ct;
//	size_t byte;
//	BASEBALL all = {
//		0
//	};
//
//	//createFile();
//	if((fp = fopen("baseball","r")) == NULL)
//	{
//		fprintf(stderr,"Can't open file.\n");
//		exit(EXIT_FAILURE);
//	}
//	if(setvbuf(fp,NULL,_IOFBF,BUFSIZE) != 0)
//	{
//		fprintf(stderr,"Can't create input buffer.\n");
//		exit(EXIT_FAILURE);
//	}
//	while((byte = fread(&base[i],sizeof(BASEBALL),1,fp)) > 0)
//	{
//		i++;
//	}
//	ct = i;
//	//找到同一个球员的的成绩并合并，将后者设置为0
//	for(i = 0;i < ct - 1;i++)
//	{
//		for(j = i + 1;j < ct;j++)
//		{
//			if(base[i].ballNum == base[j].ballNum)
//			{
//				base[i].stageNum += base[j].stageNum;
//				base[i].shotNum += base[j].shotNum;
//				base[i].run_base_num += base[j].run_base_num;
//				base[i].run_rbi += base[j].run_rbi;
//
//				base[j].stageNum = 0;
//				base[j].shotNum = 0;
//				base[j].run_base_num = 0;
//				base[j].run_rbi = 0;
//			}
//		}
//	}
//	//计算球员的击球平均成功率
//	puts("All information:");
//	for(i = 0;i < ct;i++)
//	{
//		if(base[i].shotNum != 0)
//		{
//			base[i].successAvg = (float)base[i].shotNum / base[i].stageNum;
//			all.stageNum += base[i].stageNum;
//			all.shotNum += base[i].shotNum;
//			all.run_base_num += base[i].run_base_num;
//			all.run_rbi += base[i].run_rbi;
//			all.successAvg += base[i].successAvg;
//			printf("%-2d %-6s %-6s %-2d %-2d %-2d %-2d %-2.2f.\n",base[i].ballNum,base[i].fn,base[i].ln,base[i].stageNum,base[i].shotNum,base[i].run_base_num,base[i].run_rbi,base[i].successAvg);
//		}		
//	}
//	printf("\t\t %-2d %-2d %-2d %-2d %-2.2f.\n",all.stageNum,all.shotNum,all.run_base_num,all.run_rbi,all.successAvg / SIZE);
//	//createFile();创建二进制数据文件
//	return 0;
//}
////创建程序所需数据文件
//void createFile(void)
//{
//	FILE * fp;
//	BASEBALL bb[SIZE] = {
//		{4,"Jessie","Joybat",5,2,1,1},
//		{17,"Prate","Kelly",3,2,0,2},
//		{4,"Jessie","Joybat",6,1,3,2},
//		{11,"Kity","Wall",2,2,3,1},
//		{9,"Jone","Block",6,3,0,1},
//		{9,"Jone","Block",2,1,1,1},
//	};
//	int size = sizeof(bb);
//
//	if((fp = fopen("baseball","wb")) == NULL)
//	{
//		fprintf(stderr,"Can't open file.\n");
//		exit(EXIT_FAILURE);
//	}
//	fwrite(bb,size,1,fp);
//	if(fclose(fp) != 0)
//	{
//		fprintf(stderr,"Error closing file.\n");
//		exit(EXIT_FAILURE);
//	}
//	
//	/*if((fp = fopen("baseball","rb")) == NULL)
//	{
//		fprintf(stderr,"Can't open file.\n");
//		exit(EXIT_FAILURE);
//	}
//	fread(test,size,1,fp);
//	for(i = 0;i < 5;i++)
//	{
//		printf("%d\n",test[i].ballNum);	
//	}
//	fclose(fp);*/
//	puts("Successfully");
//}