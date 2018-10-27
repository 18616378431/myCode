//7.12 将直角坐标准换为极坐标头文件
//9.1
//struct template and function prototypes

#ifndef COORDIN_H_
#define COORDIN_H_

//极坐标结构体
struct polar{
	double distance;//distance from origin
	double angle;	//direction from origin
};
//直角坐标结构体
struct rect{
	double x;
	double y;
};

//直角坐标转换为极坐标
polar rect_to_polar(rect xypos);
//显示极坐标
void show_polar(polar dapos);

#endif