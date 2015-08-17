////产生1000个1到10的随机数,打印每个数被产生了多少次,对10个不同的种子值进行计算
//#include<stdio.h>
//#include<stdlib.h>//rand(),srand()原型
//#define MAX 1000
//
//int main()
//{
//	//数字产生的次数
//	int one;	//1
//	int two;	//2
//	int three;	//3
//	int four;	//4
//	int five;	//5
//	int six;	//6
//	int seven;	//7
//	int eight;	//8
//	int nine;	//9
//	int ten;	//10
//
//	int i;
//	unsigned int seed;//种子
//	int sjs;//随机数
//
//	printf("输入种子数值:");
//	while(scanf("%u",&seed) == 1)
//	{
//		srand(seed);
//		one = two = three = four = five = six = seven = eight = nine = ten = 0;
//		for(i = 0;i < MAX;i++)
//		{
//			sjs = rand() % 10 + 1;
//			switch(sjs)
//			{
//			case 1:one++;
//				break;
//			case 2:two++;
//				break;
//			case 3:three++;
//				break;
//			case 4:four++;
//				break;
//			case 5:five++;
//				break;
//			case 6:six++;
//				break;
//			case 7:seven++;
//				break;
//			case 8:eight++;
//				break;
//			case 9:nine++;
//				break;
//			case 10:ten++;
//				break;
//			}
//		}
//		printf("1产生了%d次\n",one);
//		printf("2产生了%d次\n",two);
//		printf("3产生了%d次\n",three);
//		printf("4产生了%d次\n",four);
//		printf("5产生了%d次\n",five);
//		printf("6产生了%d次\n",six);
//		printf("7产生了%d次\n",seven);
//		printf("8产生了%d次\n",eight);
//		printf("9产生了%d次\n",nine);
//		printf("10产生了%d次\n",ten);
//		printf("总次数:%d.\n",one + two + three + four + five + six + seven + eight + nine + ten);
//	}
//	return 0;
//}