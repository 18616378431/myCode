//#include<stdio.h>
//
//int main(void)
//{
//	int a;
//	int os_ct = 0;
//	int js_ct = 0;
//	float os_tot = 0;
//	float js_tot = 0;
//
//
//	printf("Enter an integer:\n");
//	while((scanf("%d",&a) == 1) && a != 0)
//	{
//		switch(a % 2)
//		{
//		case 0:
//			os_ct++;
//			os_tot += a;
//			break;
//		default:
//			js_ct++;
//			js_tot += a;
//			break;
//		}
//	}
//	printf("os_count = %d,js_count = %d.\n",os_ct,js_ct);
//	printf("os_ave = %.2f,js_ave = %.2f.\n",os_tot/os_ct,js_tot/js_ct);
//	return 0;
//}