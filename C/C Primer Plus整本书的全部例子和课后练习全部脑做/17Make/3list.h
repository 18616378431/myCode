////list�ӿ��ļ�
//#ifndef LIST_H_//��ֹ��ΰ���
//#define LIST_H_
//
////enum BOOL {false,true};
//#define BOOL int
//#define true 1
//#define false 0
//
//#define TSIZE 45
//#define MAXSIZE 100
//
//typedef struct film{
//	char title[TSIZE];
//	int rating;
//}Item;
//
//typedef struct list{
//	Item entries[MAXSIZE];//��Ŀ����
//	int items;//��Ŀ����
//}List;
//
////����ԭ��
////����:��ʼ��һ���б�
////����ǰ:plistָ��һ���б�
////������:���б���ʼ��Ϊһ�����б�
//void InitializeList(List * plist);
//
///*
//����:ȷ���б��Ƿ�Ϊ��
//����ǰ:plistָ��һ���ѳ�ʼ�����б�
//������:������б�Ϊ���򷵻�true�����򷵻�false
//*/
//BOOL ListIsEmpty(const List * plist);
//
///*
//����:ȷ���б��Ƿ�����
//����ǰ:plistָ��һ���ѳ�ʼ�����б�
//������:������б������򷵻�true�����򷵻�false
//*/
//BOOL ListIsFull(const List * plist);
//
///*
//����:ȷ���б�����Ŀ�ĸ���
//����ǰ:plistָ��һ���ѳ�ʼ�����б�
//������:���ظ��б�����Ŀ�ĸ���
//*/
//unsigned int ListItemCount(const List * plist);
//
///*
//����:���б�β�����һ����Ŀ
//����ǰ:item��Ҫ��ӵ��б�β������Ŀ
//		plistָ��һ���ѳ�ʼ�����б�
//������:������ܵĻ������б�ĩβ���һ����Ŀ
//		��������true�����򷵻�false
//*/
//BOOL AddItem(Item item,List * plist);
//
///*
//����:��һ�������������б��е�ÿ����Ŀ
//����ǰ:plistָ��һ���ѳ�ʼ�����б�
//		pfunִ���Ǹ�һ������
//		�ú�������һ��Item�������޷���ֵ
//������:pfunָ��ĺ������������б��ÿһ��
//*/
//void Traverse(const List * plist,void (* pfun)(Item item));
//
///*
//����:�ͷ��ѷ�����ڴ�
//����ǰ:plistָ��һ���ѳ�ʼ�����б�
//������:Ϊ���б������ڴ��Ѿ��ͷ�
//		���Ҹ��б���Ϊ���б�
//*/
//void EmptyTheList(List * plist);
//
//#endif