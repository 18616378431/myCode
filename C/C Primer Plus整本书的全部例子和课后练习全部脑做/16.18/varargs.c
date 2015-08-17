//�ɱ�����ĺ���,parmN,...,va_list,va_start(),va_arg(),va_end(),va_copy()
#include<stdio.h>
#include<stdarg.h>

double sum(int lim,...);

int main()
{
	double s,t;

	s = sum(3,1.1,2.2,3.3);
	t = sum(6,1.2,2.3,3.4,4.5,5.6,6.7);
	printf("s is %.2lf,t is %.2lf.\n",s,t);
	return 0;
}
//���
double sum(int lim,...)
{
	va_list ap;//�������ڴ�Ų����ı���
	double tot = 0;
	int i;

	va_start(ap,lim);//��ap��ʼ��Ϊ�����б�
	for(i = 0;i < lim;i++)
		tot += va_arg(ap,double);//���ʲ����б��е�ÿһ��
	va_end(ap);//������
	return tot;
}