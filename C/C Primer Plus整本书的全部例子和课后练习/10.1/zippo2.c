//#include<stdio.h>
//
//int main()
//{
//	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
//	int (* pa)[2];		//pa指向一个包含两个int值的数组
//	pa = zippo;
//
//	printf("pa = %p,pa + 1 = %p\n",pa,pa + 1);
//	printf("pa[0] = %p,pa[0] + 1 = %p\n",pa[0],pa[0] + 1);
//	printf("*pa = %p,*pa + 1 = %p\n",*pa,*pa + 1);
//
//	printf("pa[0][0] = %d\n",pa[0][0]);
//	printf("  *pa[0] = %d\n",*pa[0]);
//	printf("    **pa = %d\n",**pa);
//	printf("      pa[2][1] = %d\n",pa[2][1]);
//	printf("*(*(pa + 2) + 1) = %d\n",*(*(pa + 2) + 1));
//	return 0;
//}