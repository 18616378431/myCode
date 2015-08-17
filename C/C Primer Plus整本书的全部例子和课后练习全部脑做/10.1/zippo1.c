//#include<stdio.h>
//
//int main()
//{
//	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
//
//	//打印数组首元素地址,zippo为数组首元素地址*zippo = zippo[0],zippo[0] = &zippo[0][0],**zippo = zippo[0][0]
//	printf("zippo = %p,zippo + 1 = %p\n",zippo,zippo + 1);
//	//输出zippo首元素地址zippo[0],zippo[0][0]的地址
//	//和第二个元素地址zippo[1],zippo[1][0]
//	printf("zippo[0] = %p,zippo[0] + 1 = %p\n",zippo[0],zippo[0] + 1);
//	//zippo[0]为数组首元素地址
//	//zippo[0] + 1，为内层数组的首元素地址zippo[0][0]
//	printf("*zippo = %p,*zippo + 1 = %p\n",*zippo,*zippo + 1);
//	//*zippo为内层数组首元素地址
//	//*zippo + 1 为内层数组的第二个元素地址
//	printf("zippo[0][0] = %d\n",zippo[0][0]);
//	//内层数组首元素
//	printf("  *zippo[0] = %d\n",*zippo[0]);
//	//内层数组首元素
//	printf("    **zippo = %d\n",**zippo);
//	//内层数组首元素
//	printf("      zippo[2][1] = %d\n",zippo[2][1]);
//	//二维数组，第三行，第二列的元素的数值
//	printf("*(*(zippo + 2) + 1) = %d\n",*(*(zippo + 2) + 1));
//	//同上
//	return 0;
//}