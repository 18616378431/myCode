////����1000��1��10�������,��ӡÿ�����������˶��ٴ�,��10����ͬ������ֵ���м���
//#include<stdio.h>
//#include<stdlib.h>//rand(),srand()ԭ��
//#define MAX 1000
//
//int main()
//{
//	//���ֲ����Ĵ���
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
//	unsigned int seed;//����
//	int sjs;//�����
//
//	printf("����������ֵ:");
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
//		printf("1������%d��\n",one);
//		printf("2������%d��\n",two);
//		printf("3������%d��\n",three);
//		printf("4������%d��\n",four);
//		printf("5������%d��\n",five);
//		printf("6������%d��\n",six);
//		printf("7������%d��\n",seven);
//		printf("8������%d��\n",eight);
//		printf("9������%d��\n",nine);
//		printf("10������%d��\n",ten);
//		printf("�ܴ���:%d.\n",one + two + three + four + five + six + seven + eight + nine + ten);
//	}
//	return 0;
//}