//多文件扩展命名空间需要包含头文件
#include<iostream>
#include"four.h"

namespace SALES
{
	void setSales(Sales & s,const double ar[],int n)
	{
		double total = 0;
		for(int i = 0;i < QUARTERS;i++)
		{
			if(i <= n)
			{
				total += ar[i];
				s.sales[i] = ar[i];
			}
			else
			{
				s.sales[i] = 0;
			}
		}
		s.average = total / QUARTERS;
		s.max = getMax(ar,n);
		s.min = getMin(ar,n);
	}

	void setSales(Sales & s)
	{
		double total = 0;

		for(int i = 0;i < QUARTERS;i++)
		{
			std::cout << "sales:";
			std::cin >> s.sales[i];
			total += s.sales[i];
		}
		s.average = total / QUARTERS;
		s.max = getMax(s.sales,QUARTERS);
		s.min = getMin(s.sales,QUARTERS);

	}

	void showSales(const Sales & s)
	{
		std::cout << "Sales:\n";
		for(int i = 0;i < QUARTERS;i++)
		{
			std::cout << s.sales[i] << "\t";
		}
		std::cout << "\n";
		std::cout << "average:" << s.average;
		std::cout << ",maximum:" << s.max;
		std::cout << ",minimum:" << s.min << std::endl;
	}
	double getMax(const double ar[],int n)
	{
		double max = ar[0];

		for(int i = 1;i < n;i++)
		{
			if(max < ar[i])
			{
				max = ar[i];
			}
		}
		return max;
	}

	double getMin(const double ar[],int n)
	{
		double min = ar[0];

		for(int i = 1;i < n;i++)
		{
			if(min > ar[i])
			{
				min = ar[i];
			}
		}
		return min;
	}
}
