//#include<stdio.h>
//
//int main(void)
//{
//	int a;
//	int os_ct = 0;//ż������
//	int js_ct = 0;//��������
//	float os_tot = 0;//ż���ܺ�
//	float js_tot = 0;//�����ܺ�
//
//	printf("Enter an integer:\n");
//	while(scanf("%d",&a) == 1 && a != 0)
//	{
//		if(a % 2 == 0)
//		{
//			os_tot += a;
//			os_ct++;
//		}
//		else
//		{
//			js_tot += a;
//			js_ct++;
//		}
//	}
//	printf("os_count = %d,js_count = %d.\n",os_ct,js_ct);
//	printf("os_ave = %.2f,js_ave = %.2f.\n",os_tot/os_ct,js_tot/js_ct);
//	return 0;
//}