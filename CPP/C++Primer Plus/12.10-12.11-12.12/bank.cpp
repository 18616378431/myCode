//12.12 程序控制文件
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);//is there a new customer

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));//random initializing of rand()

	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;//of cycles

	cout << "Enter the average number of customers per hour:";
	double arrivesperhour;//average # of arrival per hour,每小时平均到达数量
	cin >> arrivesperhour;
	double min_per_cust;//average time between arrivals
	min_per_cust = MIN_PER_HR / arrivesperhour;//每个客户的平均到达时间间隔

	Item temp;//new customer data
	long turnaways = 0;//turned away by full queue
	long customers = 0;//joined the queue
	long served = 0;//served during the simulation
	long sum_line = 0;//cumulative line length
	int wait_time = 0;//time until autoteller is free
	long line_wait = 0;//cumulative time in line,队列的累积时间
	
	//running the simulation
	for(int cycle = 0;cycle < cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))//have new customer
		{
			if(line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//cycle = time of arrival
				line.enqueue(temp);//add new customer to line
			}
		}
		if(wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);//attend next customer
			wait_time = temp.ptime();//for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if(wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	//reporting results
	if(customers > 0)
	{
		cout << "customers accepted:" << customers << endl;
		cout << "customer served:" << served << endl;
		cout << "turnaways:" << turnaways << endl;
		cout << "average queue size:";
		
		//set printf format
		cout .precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout.setf(ios_base::showpoint);

		cout << (double)sum_line / cyclelimit << endl;
		
		cout << "average wait time:";
		cout << (double)line_wait / served << endl;
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";


	return 0;
}
//x = average time,in minutes,between customers
//return value is true if customer show up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}