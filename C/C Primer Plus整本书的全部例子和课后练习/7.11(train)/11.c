//#include<stdio.h>
//#define XIAN 1.25	//鲜价格1.25美元/磅
//#define TIANCAI 0.65		//甜菜价格0.65美元/磅
//#define HULUOBO 0.89		//胡萝卜价格0.89美元/磅
//
//int main(void)
//{
//	float x = 0;		//购买朝鲜鲜的重量
//	float t = 0;		//购买甜菜的重量
//	float h = 0;		//购买胡萝卜的重量
//	float totxb = 0;		//朝鲜鲜总磅数
//	float tottb = 0;		//甜菜总磅数
//	float tothb = 0;		//胡萝卜总磅数
//	float totalb = 0;		//所有产品总磅数
//	float totalx;		//朝鲜鲜总费用
//	float totalt;		//甜菜总费用
//	float totalh;		//胡萝卜总费用
//	float total;		//所有商品总费用
//	float ys;		//运输费用
//	float zk;		//折扣
//	char ch;		//选择购买种类
//
//	char tj;		//是否提交
//	
//	
//	//获取要购买各蔬菜的磅数,同一蔬菜可重复添加购买磅数
//	printf("Enter what you want to buy('#' to quit!):\n");
//	printf("a)朝鲜鲜\tb)甜菜\t\tc)胡萝卜\n");
//	while(scanf("%c",&ch) == 1 && ch != 'q')
//	{
//		switch(ch)
//		{
//		case 'a':
//			printf("请输入您所要购买的朝鲜鲜的磅数.\n");
//			scanf("%f",&x);
//			totxb += x;
//			printf("continue to type in a or b or c，'q' to quit.\n");
//			break;
//		case 'b':
//			printf("请输入您所要购买的甜菜的磅数.\n");
//			scanf("%f",&t);
//			tottb += t;
//			printf("continue to type in a or b or c，'q' to quit.\n");
//			break;
//		case 'c':
//			printf("请输入您所要购买的胡萝卜的磅数.\n");
//			scanf("%f",&h);
//			tothb += h;
//			printf("continue to type in a or b or c，'q' to quit.\n");
//			break;
//		default:
//			break;
//		}
//	}
//	totalb = totxb + tottb + tothb;		//所有蔬菜总磅数
//	//根据总磅数，判定运费
//	if(x != 0 || t != 0 || h != 0)
//	{
//		if(totalb <= 5)
//		{
//			ys = 3.50;
//		}
//		else if(totalb > 5 && totalb <= 20)
//		{
//			ys = 10.00;
//		}
//		else
//		{
//			ys = 8.00 + (totalb - 20) * 0.1;
//		}
//	}
//	else
//	{
//		ys = 0;
//	}
//	totalx = totxb * XIAN;
//	totalt = tottb * TIANCAI;
//	totalh = tothb * HULUOBO;
//	total = totalx + totalt + totalh;
//	if(total >= 100)
//	{
//		zk = total * 0.05;
//	}
//	else
//	{
//		zk = 0;
//	}
//	total = total - zk + ys;		//折扣后的总费用
//	printf("是否提交订单(Y/N)?\n");
//	tj = getchar();
//	switch(tj)
//	{
//	case 'Y':
//		printf("订单已提交!\n");
//		break;
//	case 'N':
//		printf("欢迎您继续购物!\n");
//		break;
//	}
//	printf("\ta)朝鲜鲜\tb)甜菜\tc)胡萝卜\n");
//	printf("单价:\t%.2f\t\t%.2f\t%.2f\n",XIAN,TIANCAI,HULUOBO);
//	printf("磅数:\t%.2f\t\t%.2f\t%.2f\n",totxb,tottb,tothb);
//	printf("费用:\t%.2f\t\t%.2f\t%.2f\n",totalx,totalt,totalh);
//	printf("\t折扣\t运输\t总费用\n\t%.2f\t%.2f\t%.2f\n",zk,ys,total);
//	return 0;
//}