////�ṹǶ�ף�����������Ա�Ľṹ��һ����ᱣ�Ϻţ��ڶ�����һ������������Ա�Ľṹ�������м�������
////����5���ṹ���飬ֻ����м����ĵ�һ����ĸ�Ĵ�д�����һ����(.)����Ϊ�գ������
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
//	//printf("%d.\n",sizeof(test));//��СΪ128
//	//printf("%d.\n",sizeof(test.myName));//���Ϊ123,
//	//printf("%d.\n",sizeof(test.shbzNum));//��СΪ4
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