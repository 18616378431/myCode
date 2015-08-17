//#include<stdio.h>
//
//int main(void)
//{
//	int low,up;
//	int sum,dis;
//	sum = 0;
//	printf("Enter low and up:");
//	scanf("%d%d",&low,&up);
//	dis = up - low;
//	while(up > low)
//	{
//		for(;low <= up;low++)
//		{
//			sum += low*low;
//		}
//		low = up - dis;
//		printf("%d to %d's square is %d.\n",low,up,sum);
//		sum = 0;
//		printf("Enter low and up:");
//		scanf("%d%d",&low,&up);
//	}
//		printf("Done \n");
//	return 0;
//}