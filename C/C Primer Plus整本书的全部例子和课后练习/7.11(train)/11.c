//#include<stdio.h>
//#define XIAN 1.25	//�ʼ۸�1.25��Ԫ/��
//#define TIANCAI 0.65		//��˼۸�0.65��Ԫ/��
//#define HULUOBO 0.89		//���ܲ��۸�0.89��Ԫ/��
//
//int main(void)
//{
//	float x = 0;		//�������ʵ�����
//	float t = 0;		//������˵�����
//	float h = 0;		//������ܲ�������
//	float totxb = 0;		//�������ܰ���
//	float tottb = 0;		//����ܰ���
//	float tothb = 0;		//���ܲ��ܰ���
//	float totalb = 0;		//���в�Ʒ�ܰ���
//	float totalx;		//�������ܷ���
//	float totalt;		//����ܷ���
//	float totalh;		//���ܲ��ܷ���
//	float total;		//������Ʒ�ܷ���
//	float ys;		//�������
//	float zk;		//�ۿ�
//	char ch;		//ѡ��������
//
//	char tj;		//�Ƿ��ύ
//	
//	
//	//��ȡҪ������߲˵İ���,ͬһ�߲˿��ظ���ӹ������
//	printf("Enter what you want to buy('#' to quit!):\n");
//	printf("a)������\tb)���\t\tc)���ܲ�\n");
//	while(scanf("%c",&ch) == 1 && ch != 'q')
//	{
//		switch(ch)
//		{
//		case 'a':
//			printf("����������Ҫ����ĳ����ʵİ���.\n");
//			scanf("%f",&x);
//			totxb += x;
//			printf("continue to type in a or b or c��'q' to quit.\n");
//			break;
//		case 'b':
//			printf("����������Ҫ�������˵İ���.\n");
//			scanf("%f",&t);
//			tottb += t;
//			printf("continue to type in a or b or c��'q' to quit.\n");
//			break;
//		case 'c':
//			printf("����������Ҫ����ĺ��ܲ��İ���.\n");
//			scanf("%f",&h);
//			tothb += h;
//			printf("continue to type in a or b or c��'q' to quit.\n");
//			break;
//		default:
//			break;
//		}
//	}
//	totalb = totxb + tottb + tothb;		//�����߲��ܰ���
//	//�����ܰ������ж��˷�
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
//	total = total - zk + ys;		//�ۿۺ���ܷ���
//	printf("�Ƿ��ύ����(Y/N)?\n");
//	tj = getchar();
//	switch(tj)
//	{
//	case 'Y':
//		printf("�������ύ!\n");
//		break;
//	case 'N':
//		printf("��ӭ����������!\n");
//		break;
//	}
//	printf("\ta)������\tb)���\tc)���ܲ�\n");
//	printf("����:\t%.2f\t\t%.2f\t%.2f\n",XIAN,TIANCAI,HULUOBO);
//	printf("����:\t%.2f\t\t%.2f\t%.2f\n",totxb,tottb,tothb);
//	printf("����:\t%.2f\t\t%.2f\t%.2f\n",totalx,totalt,totalh);
//	printf("\t�ۿ�\t����\t�ܷ���\n\t%.2f\t%.2f\t%.2f\n",zk,ys,total);
//	return 0;
//}