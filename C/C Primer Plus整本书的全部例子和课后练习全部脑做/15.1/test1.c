#include<stdio.h>

struct thinkerbell{//�����������ṹλ�ֶ�
	unsigned int rp:2;//1.4M�����������ĵ�����0,1
	unsigned int   :1;//�հ�λ2
	unsigned int cd:2;//CD-ROM����������,3,4
	unsigned int   :1;//�հ�λ,5
	unsigned int yp:2;//Ӳ������������,6,7
};

struct Klinkbell{//�����������,int���ֽڣ�ÿ�ֽ�8λ����32λ��Ҫ�ճ�24λ��������������λ����
	unsigned int   :24;//�հ�
	unsigned int yp:2;
	unsigned int   :1;
	unsigned int cd:2;
	unsigned int   :1;
	unsigned int rp:2;
};

int main()
{

	return 0;
}