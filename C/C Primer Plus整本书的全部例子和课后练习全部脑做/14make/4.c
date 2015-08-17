////结构嵌套，包含两个成员的结构，一个社会保障号，第二个是一个包含三个成员的结构，名，中间名，姓
////创建5个结构数组，只输出中间名的第一个字母的大写，外加一个点(.)，若为空，则不输出
//#include<stdio.h>
//#define LEN 41
//#define SIZE 5
//
//struct name{//#define LEN 41
//	char fName[LEN];
//	char mName[LEN];
//	char lName[LEN];
//};
//typedef struct info{
//	long shbzNum;
//	struct name myName;
//}INFO;
//
//void showInfo(INFO ps[],int ct);
//
//int main()
//{
//	INFO myInfo[SIZE] = {
//		{302039823,{"Dribble","Moniter","Flossie"}},
//		{302039824,{"Wang","Jian","Kang"}},
//		{302039825,{"Jone","","Rose"}},
//		{302039826,{"Week","Lucky","Hibinate"}},
//		{302039827,{"Good","Thank","Evening"}},
//	};
//
//	showInfo(myInfo,SIZE);
//
//	//INFO test;
//	//printf("%d.\n",sizeof(test));//大小为128
//	//printf("%d.\n",sizeof(test.myName));//结果为123,
//	//printf("%d.\n",sizeof(test.shbzNum));//大小为4
//	return 0;
//}
//void showInfo(INFO ps[],int ct)
//{
//	int i;
//
//	for(i = 0;i < ct;i++)
//	{
//		printf("%s,%s ",ps[i].myName.fName,ps[i].myName.lName);
//		if(ps[i].myName.mName[0] != '\0')
//		{
//			printf("%c.",ps[i].myName.mName[0]);
//		}
//		printf(" - %ld.\n",ps[i].shbzNum);
//	}
//}