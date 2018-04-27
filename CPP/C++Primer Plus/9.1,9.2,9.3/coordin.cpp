//9.3 ͷ�ļ�coordin.hʵ���ļ�
#include<iostream>
#include<cmath>
#include "coordin.h"

//ֱ������ת��Ϊ������
polar rect_to_polar(rect xypos)
{
	using namespace std;

	polar answer;

	answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
	answer.angle = atan2(xypos.y,xypos.x);
	return answer;
}
//��ʾ������
void show_polar(polar dapos)
{
	using namespace std;

	//����to�Ƕ�ϵ��
	const double RAD_TO_DEG = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ",angle = " << dapos.angle * RAD_TO_DEG;
	cout << " degrees\n";
}