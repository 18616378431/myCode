//���ļ�����,��������
#ifndef GOLF_H_
#define GOLF_H_

const int LEN = 4;

struct golf{
	char fullname[LEN];
	int handicap;
};
//��һ���汾
void setgolf(golf & g,char * name,int hc);

//���ذ汾
int setgolf(golf & g);

//����handicapΪ��ֵ
void handicap(golf & g,int hc);

//��ʽ�ṹ������
void showgolf(const golf & g);
#endif