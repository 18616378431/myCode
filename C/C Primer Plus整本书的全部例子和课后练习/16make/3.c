//������ת��Ϊֱ������
//#include<stdio.h>
//#include<math.h>
//#define DEG_TO_RAD ((4 * atan(1)) / 180)
//
//typedef struct polar_v{
//	double maginitude;//����
//	double angle;//�Ƕ�
//} POLAR_V;//������
//typedef struct rect_v{
//	double x;
//	double y;
//} RECT_V;//ֱ������
//RECT_V polar_to_rect(POLAR_V pv);
//
//int main()
//{
//	RECT_V result;
//	POLAR_V input;
//
//	puts("Enter magnitude and angle:");
//	while(scanf("%lf %lf",&input.maginitude,&input.angle) == 2)
//	{
//		result = polar_to_rect(input);
//		printf("x = %.2lf,y = %.2lf.\n",result.x,result.y);
//		puts("Enter magnitude and angle:");
//	}
//	return 0;
//}
//RECT_V polar_to_rect(POLAR_V pv)
//{
//	RECT_V result;
//
//	double rad = pv.angle * DEG_TO_RAD;
//	result.x = pv.maginitude * cos(rad);
//	result.y = pv.maginitude * sin(rad);
//	return result;
//}