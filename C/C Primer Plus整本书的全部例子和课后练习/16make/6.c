////修改16.15，使用qsort()对结构体数组进行排序
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define LEN 40
//#define SIZE 5
//
//typedef struct names{
//	char first[LEN];
//	char last[LEN];
//} NAMES;
//
//int myCompare(const void * p1,const void * p2);
//void show(NAMES * ps);
//
//int main()
//{
//	NAMES staff[SIZE] = {
//		{"Wang","Kang"},
//		{"Michel","Hasn"},
//		{"Jhone","Rose"},
//		{"Lick","Luck"},
//		{"Holly","Petter"},
//	};
//
//	puts("\nBefore qsort");
//	show(staff);
//	qsort(staff,SIZE,sizeof(NAMES),myCompare);
//	puts("\nAfter qsort");
//	show(staff);
//	return 0;
//}
//void show(NAMES * ps)
//{
//	int i;
//
//	for(i = 0;i < SIZE;i++)
//		printf("%s %s\n",ps[i].first,ps[i].last);
//}
//int myCompare(const void * p1,const void * p2)
//{
//	const NAMES * a1 = (const NAMES * )p1;
//	const NAMES * a2 = (const NAMES * )p2;
//	int res = strcmp(a1->first,a2->first);
//	
//	if(res != 0)
//		return res;
//	else
//		return strcmp(a1->last,a2->last);
//	return 0;
//}