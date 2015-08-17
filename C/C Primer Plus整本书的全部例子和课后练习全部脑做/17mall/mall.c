#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
#define MIN_PER_HR 60.0

BOOL newCustomer(double x);
Item customerComeTime(long comeTime);

int main()
{
	Queue line;
	Item temp;//�˿�����
	int hours;//ģ��ʱ��
	int cus_per_hr;//ÿСʱ�˿�ƽ����
	long cycle,cycleLimit;//������������
	long turnAway = 0;//���ܹ˿���
	long customers = 0;//������й˿���
	long served = 0;//ģ���ڼ�õ�����Ĺ˿���
	long sum_length_line = 0;//�ۼƶ��г���
	int wait_time = 0;//�ӵ�ǰ������ʱ��
	double aver_time_cus_come;//�˿͵���ƽ��ʱ����
	long sum_wait_time = 0;//�����ۼƵȴ�ʱ��

	InitializeQueue(&line);
	srand((unsigned int)time(NULL));//��ʼ�����������
	puts("Case Study:Sigmund Lander's Advice Booth");
	puts("Enter the simulation hours:");
	scanf("%d",&hours);
	cycleLimit = (long)MIN_PER_HR * hours;//ȡ��ѭ��������ֵ
	puts("Enter the average number of customers per hour:");
	scanf("%d",&cus_per_hr);
	aver_time_cus_come = MIN_PER_HR / cus_per_hr;//�˿͵�����ƽ��ʱ����

	for(cycle = 0;cycle < cycleLimit;cycle++)
	{
		if(newCustomer(aver_time_cus_come))//���¹˿�
		{
			if(QueueIsFull(&line))	//�����������
			{
				turnAway++;			//������������
			}
			else//��������δ��
			{
				customers++;//�����е���������
				temp = customerComeTime(cycle);//��ʼ���˿���Ϣ
				EnQueue(temp,&line);//���˿ͼ������
			}
		}
		if(!QueueIsEmpty(&line) && wait_time <= 0)
		{
			DeQueue(&temp,&line);
			wait_time = temp.preocesstime;
			sum_wait_time += cycle - temp.arrive;//�����ۼƵȴ�ʱ��
			served++;//��������������
		}
		if(wait_time > 0)
		{
			wait_time--;
		}
		sum_length_line += QueueItemCount(&line);
	}
	if(customers > 0)
	{
		printf("customer accepted:%ld\n",customers);
		printf("	customer served:%ld\n",served);
		printf("		turnaway:%ld\n",turnAway);
		printf("Ave Queue Size:%.2f\n",(double)sum_length_line / cycleLimit);//�ۼƶ��г��ȳ��Լ���������
		printf("Ave Wait Time:%.2f minutes\n",(double)sum_wait_time / served);//�ۼƵȴ�ʱ����Ա���������
	}
	else
	{
		puts("No customers!");
	}
	EmptyQueue(&line);
	puts("Bye!");
	return 0;
}
//�¹˿͵���,xΪ�˿͵�����ƽ��ʱ����(��),���һ�������й˿͵���������true
BOOL newCustomer(double x)
{
	if((rand() * x / RAND_MAX) < 1)
		return TRUE;
	else
		return FALSE;
}
//����comeTimeΪ�˿͵���ʱ�䣬����Item�ṹ���ýṹ�Ĺ˿͵���ʱ������ΪcomeTime������ѯʱ������Ϊ1-3֮��������
Item customerComeTime(long comeTime)
{
	Item cust;

	cust.preocesstime = rand() % 3 + 1;//�������1-3֮�����ѯʱ��
	cust.arrive = comeTime;
	return cust;
}