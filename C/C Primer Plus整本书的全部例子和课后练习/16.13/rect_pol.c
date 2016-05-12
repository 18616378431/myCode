//把直角坐标转换为极坐标
#include<stdio.h>
#include<math.h>
#define RAD_TO_DEG (180 / (4 * atan(1)))	//π的值:4*atan(1)，弧度转换为度乘180 除以(4 * atan(1))

typedef struct polar_v{
	double magnitude;
	double angle;
}POLAR_V;
typedef struct rect_v{
	double x;
	double y;
}RECT_V;

POLAR_V rect_to_polar(RECT_V rv);

int main()
{
	POLAR_V result;
	RECT_V input;

	puts("Enter x,y coordinates:enter q to quit:");
	while(scanf("%lf %lf",&input.x,&input.y) == 2)
	{
		result = rect_to_polar(input);
		printf("magnitude = %0.2f,angle = %0.2f\n",result.magnitude,result.angle);
	}
	return 0;
}
POLAR_V rect_to_polar(RECT_V rv)
{
	POLAR_V pv;

	pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
	if(pv.magnitude == 0)
	{
		pv.angle = 0;
	}
	else
	{
		pv.angle = RAD_TO_DEG * atan2(rv.y,rv.x);
	}
	return pv;
}