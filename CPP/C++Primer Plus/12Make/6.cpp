//6.两个队列同时 哪个队列少就优先加入到哪个队列 
//找出平均等候时间1分钟 每小时到达的客户数
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	std::srand(std::time(0));
	std::cout << "Case study:Bank of Heather Automatic Teller\n";
	std::cout << "Enter maximum size of queue:";

	int qs;
	std::cin >> qs;
	Queue line1(qs);
	Queue line2(qs);

	std::cout << "Enter the number of simulation hours:";
	int hours;
	std::cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	std::cout << "Enter the average number of customers per hour:";
	double perhour;
	std::cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp1,temp2;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	long line_wait1 = 0;
	long line_wait2 = 0;

	for(int cycle = 0;cycle < cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(line1.isfull() && line2.isfull())
				turnaways++;
			else
			{
				++customers;
				temp1.set(cycle);
				if(line1.queuecount() < line2.queuecount())
					line1.enqueue(temp1);
				else
					line2.enqueue(temp2);
			}
		}
		if(wait_time1 <= 0 && !line1.isempty())
		{
			line1.dequeue(temp1);
			wait_time1 = temp1.ptime();
			line_wait1 += cycle - temp1.when();
			++served;
		}
		if(wait_time2 <= 0 && !line2.isempty())
		{
			line2.dequeue(temp2);
			wait_time2 = temp2.ptime();
			line_wait2 += cycle - temp2.when();
			++served;
		}
		if(wait_time1 > 0)
			--wait_time1;
		if(wait_time2 > 0)
			--wait_time2;
		sum_line1 += line1.queuecount();
		sum_line2 += line2.queuecount();
	}
	if(customers > 0)
	{
		std::cout << "customers accepted:" << customers << std::endl;
		std::cout << "customers served:" << served << std::endl;
		std::cout << "	turnaways:" << turnaways << std::endl;
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
		std::cout << (double)sum_line1 / cyclelimit << std::endl;
		std::cout << (double)sum_line2 / cyclelimit << std::endl;
		std::cout << "average wait time:" << (double)line_wait1 / served << " minutes" << std::endl;
		std::cout << "average wait time:" << (double)line_wait2 / served << " minutes" << std::endl;
	}
	else
		std::cout << "No customers!\n";
	std::cout << "Done!\n";
	return 0;
}
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}