//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include"4queue.h"
//#define MIN_PER_HR 60.0
//#define SIZE 2
//
//typedef struct More_queue{
//	Queue line;
//	Item temp;//�˿�����
//	int hours;//ģ��ʱ��
//	int cus_per_hr;//ÿСʱ�˿�ƽ����
//	long cycle,cycleLimit;//������������
//	long turnAway;//���ܹ˿���
//	long customers;//������й˿���
//	long served;//ģ���ڼ�õ�����Ĺ˿���
//	long sum_length_line;//�ۼƶ��г���
//	int wait_time;//�ӵ�ǰ������ʱ��
//	double aver_time_cus_come;//�˿͵���ƽ��ʱ����
//	long sum_wait_time;//�����ۼƵȴ�ʱ��
//}Mqueue;
//
//BOOL newCustomer(double x);
//Item customerComeTime(long comeTime);
//
//int main()
//{
//	Mqueue mq[SIZE];
//	int index;
//
//	for(index = 0;index < SIZE;index++)
//	{	
//		mq[index].turnAway = 0;
//		mq[index].customers = 0;
//		mq[index].served = 0;
//		mq[index].sum_length_line = 0;
//		mq[index].wait_time = 0;
//		mq[index].sum_wait_time = 0;
//
//		InitializeQueue(&(mq[index].line));
//		srand((unsigned int)time(NULL));//��ʼ�����������
//		puts("Case Study:Sigmund Lander's Advice Booth");
//		puts("Enter the simulation hours:");
//		scanf("%d",&(mq[index].hours));
//		mq[index].cycleLimit = (long)MIN_PER_HR * mq[index].hours;//ȡ��ѭ��������ֵ
//		puts("Enter the average number of customers per hour:");
//		scanf("%d",&(mq[index].cus_per_hr));
//		mq[index].aver_time_cus_come = MIN_PER_HR / mq[index].cus_per_hr;//�˿͵�����ƽ��ʱ����
//
//		for(mq[index].cycle = 0;mq[index].cycle < mq[index].cycleLimit;mq[index].cycle++)
//		{
//			if(newCustomer(mq[index].aver_time_cus_come))//���¹˿�
//			{
//				if(QueueIsFull(&(mq[index].line)))	//�����������
//				{
//					mq[index].turnAway++;			//������������
//				}
//				else//��������δ��
//				{
//					mq[index].customers++;//�����е���������
//					mq[index].temp = customerComeTime(mq[index].cycle);//��ʼ���˿���Ϣ
//					EnQueue(mq[index].temp,&(mq[index].line));//���˿ͼ������
//				}
//			}
//			if(!QueueIsEmpty(&(mq[index].line)) && mq[index].wait_time <= 0)
//			{
//				DeQueue(&(mq[index].temp),&(mq[index].line));
//				mq[index].wait_time = mq[index].temp.preocesstime;
//				mq[index].sum_wait_time += mq[index].cycle - mq[index].temp.arrive;//�����ۼƵȴ�ʱ��
//				mq[index].served++;//��������������
//			}
//			if(mq[index].wait_time > 0)
//			{
//				mq[index].wait_time--;
//			}
//			mq[index].sum_length_line += QueueItemCount(&(mq[index].line));
//		}
//		if(mq[index].customers > 0)
//		{
//			printf("customer accepted:%ld\n",mq[index].customers);
//			printf("	customer served:%ld\n",mq[index].served);
//			printf("		turnaway:%ld\n",mq[index].turnAway);
//			printf("Ave Queue Size:%.2f\n",(double)mq[index].sum_length_line / mq[index].cycleLimit);//�ۼƶ��г��ȳ��Լ���������
//			printf("Ave Wait Time:%.2f minutes\n",(double)mq[index].sum_wait_time / mq[index].served);//�ۼƵȴ�ʱ����Ա���������
//		}
//		else
//		{
//			puts("No customers!");
//		}
//		EmptyQueue(&(mq[index].line));
//		puts("Bye!");
//	}
//	return 0;
//}
////�¹˿͵���,xΪ�˿͵�����ƽ��ʱ����(��),���һ�������й˿͵���������true
//BOOL newCustomer(double x)
//{
//	if((rand() * x / RAND_MAX) < 1)
//		return TRUE;
//	else
//		return FALSE;
//}
////����comeTimeΪ�˿͵���ʱ�䣬����Item�ṹ���ýṹ�Ĺ˿͵���ʱ������ΪcomeTime������ѯʱ������Ϊ1-3֮��������
//Item customerComeTime(long comeTime)
//{
//	Item cust;
//
//	cust.preocesstime = rand() % 3 + 1;//�������1-3֮�����ѯʱ��
//	cust.arrive = comeTime;
//	return cust;
//}