//7.12 ��ֱ������׼��Ϊ������ͷ�ļ�
//9.1
//struct template and function prototypes

#ifndef COORDIN_H_
#define COORDIN_H_

//������ṹ��
struct polar{
	double distance;//distance from origin
	double angle;	//direction from origin
};
//ֱ������ṹ��
struct rect{
	double x;
	double y;
};

//ֱ������ת��Ϊ������
polar rect_to_polar(rect xypos);
//��ʾ������
void show_polar(polar dapos);

#endif