//#include<stdio.h>
//
//void to_base_n(int n,int p);
//
//int main()
//{
//	int num;
//	int bina;
//	printf("Enter two integer numbers:");
//	//printf("fanhuizhi = %d.\n",scanf("%d%d",&num,&bina));
//	while(scanf("%d%d",&num,&bina) == 2)
//	{
//		//scanf("%d",&bina);
//		//printf("bina = %d.\n",bina);
//		to_base_n(num,bina);
//		putchar('\n');
//		printf("Enter two integer numbers:");
//	}
//	return 0;
//}
//
//void to_base_n(int n,int p)
//{
//	int r;
//	//printf("p = %d.\n",p);
//	r = n % p;
//	if(n >= p)
//	{
//		to_base_n(n / p,p);
//	}
//	//printf("*************result.\n");
//	putchar('0' + r);
//	return ;
//
//}