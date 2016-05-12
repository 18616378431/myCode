//#include<stdio.h>
//#include"5.h"
//
//extern struct student stu[CSIZE];
//struct student * ps = stu;
//int count = 0;//记录结构体数组中已经初始化成员的数量
//
//void getInfo();
//void show();
//
//int main()
//{
//	getInfo();
//	show();
//	return 0;
//}
//
//void getInfo()
//{
//	int i = 0,j;
//	float totalGrade;
//
//	puts("Enter the first name of student:");
//	while(i < CSIZE && gets(stu[i].sname.fname) != NULL && stu[i].sname.fname[0] != '\0')
//	{
//		puts("The last name:");
//		gets(stu[i].sname.lname);
//		puts("Enter the grade of student:");
//		totalGrade = 0;
//		for(j = 0;j < SIZE;j++)
//		{
//			scanf("%f",&stu[i].grade[j]);
//			totalGrade += stu[i].grade[j];
//		}
//		while(getchar() != '\n')//去除多余字符及换行
//			continue;
//		stu[i].avg = totalGrade / SIZE;
//		i++;
//		count++;
//		puts("Enter the first name of student:");
//	}
//	
//}
//void show()
//{
//	int i,j;
//
//	printf("firstname\tlastname\tgrade1\tgrade2\tgrade3\taverageGrade\n");
//	for(i = 0;i < count;i++)
//	{
//		printf("%s\t%s",stu[i].sname.fname,stu[i].sname.lname);
//		for(j = 0;j < SIZE;j++)
//		{
//			printf("\t%.2f\t",stu[i].grade[j]);
//		}
//		printf("%.2f.\n",stu[i].avg);
//	}
//}