//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include"4queue.h"
//#define MIN_PER_HR 60.0
//#define SIZE 2
//
//typedef struct More_queue{
//	Queue line;
//	Item temp;//顾客数据
//	int hours;//模拟时间
//	int cus_per_hr;//每小时顾客平均数
//	long cycle,cycleLimit;//计数器，上限
//	long turnAway;//被拒顾客数
//	long customers;//加入队列顾客数
//	long served;//模拟期间得到服务的顾客数
//	long sum_length_line;//累计队列长度
//	int wait_time;//从当前到空闲时间
//	double aver_time_cus_come;//顾客到来平均时间间隔
//	long sum_wait_time;//队列累计等待时间
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
//		srand((unsigned int)time(NULL));//初始化随机数种子
//		puts("Case Study:Sigmund Lander's Advice Booth");
//		puts("Enter the simulation hours:");
//		scanf("%d",&(mq[index].hours));
//		mq[index].cycleLimit = (long)MIN_PER_HR * mq[index].hours;//取得循环上限数值
//		puts("Enter the average number of customers per hour:");
//		scanf("%d",&(mq[index].cus_per_hr));
//		mq[index].aver_time_cus_come = MIN_PER_HR / mq[index].cus_per_hr;//顾客到来的平均时间间隔
//
//		for(mq[index].cycle = 0;mq[index].cycle < mq[index].cycleLimit;mq[index].cycle++)
//		{
//			if(newCustomer(mq[index].aver_time_cus_come))//有新顾客
//			{
//				if(QueueIsFull(&(mq[index].line)))	//如果队列已满
//				{
//					mq[index].turnAway++;			//被拒人数增加
//				}
//				else//队列人数未满
//				{
//					mq[index].customers++;//队列中的人数增加
//					mq[index].temp = customerComeTime(mq[index].cycle);//初始化顾客信息
//					EnQueue(mq[index].temp,&(mq[index].line));//将顾客加入队列
//				}
//			}
//			if(!QueueIsEmpty(&(mq[index].line)) && mq[index].wait_time <= 0)
//			{
//				DeQueue(&(mq[index].temp),&(mq[index].line));
//				mq[index].wait_time = mq[index].temp.preocesstime;
//				mq[index].sum_wait_time += mq[index].cycle - mq[index].temp.arrive;//队列累计等待时间
//				mq[index].served++;//被服务人数增加
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
//			printf("Ave Queue Size:%.2f\n",(double)mq[index].sum_length_line / mq[index].cycleLimit);//累计队列长度除以计数器上限
//			printf("Ave Wait Time:%.2f minutes\n",(double)mq[index].sum_wait_time / mq[index].served);//累计等待时间除以被服务人数
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
////新顾客到来,x为顾客到来的平均时间间隔(秒),如果一分钟内有顾客到来，返回true
//BOOL newCustomer(double x)
//{
//	if((rand() * x / RAND_MAX) < 1)
//		return TRUE;
//	else
//		return FALSE;
//}
////变量comeTime为顾客到来时间，返回Item结构，该结构的顾客到来时间设置为comeTime，将咨询时间设置为1-3之间的随机数
//Item customerComeTime(long comeTime)
//{
//	Item cust;
//
//	cust.preocesstime = rand() % 3 + 1;//随机生成1-3之间的咨询时间
//	cust.arrive = comeTime;
//	return cust;
//}