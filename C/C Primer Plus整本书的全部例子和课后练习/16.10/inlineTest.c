#include<stdio.h>
//��������
inline void eatLine()//C99����
{
	while(getchar() != '\n')
		continue;
}
extern double square(double);//ͬһ�ļ��п��Խ�square()����Ϊ�ⲿ����
inline double square(double);
double square(double x)
{
	return x * x;
}

int main()
{
	eatLine();
	return 0;
}