//9.3 头文件coordin.h实现文件
#include<iostream>
#include<cmath>
#include "coordin.h"

//直角坐标转换为极坐标
polar rect_to_polar(rect xypos)
{
	using namespace std;

	polar answer;

	answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
	answer.angle = atan2(xypos.y,xypos.x);
	return answer;
}
//显示极坐标
void show_polar(polar dapos)
{
	using namespace std;

	//弧度to角度系数
	const double RAD_TO_DEG = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ",angle = " << dapos.angle * RAD_TO_DEG;
	cout << " degrees\n";
}