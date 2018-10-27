//4.
#include<iostream>
#include"Sales.h"

namespace SALES
{
	Sales::Sales()
	{
		m_sales[0] = m_sales[1] = m_sales[2] = m_sales[3] = m_average = m_max = m_min = 0;
	}
	Sales::Sales(const double * sales,const int n)
	{
		double average = sales[0];
		double max = sales[0];
		double min = sales[0];
		m_sales[0] = sales[0];

		if(n > QUARTERS)
		{
			for(int i = 1;i < QUARTERS;i++)
			{
				m_sales[i] = sales[i];
				max = max < sales[i]?sales[i]:max;
				min = min > sales[i]?sales[i]:min;
				average += sales[i];
			}
			m_max = max;
			m_min = min;
			m_average = average / QUARTERS;
		}
		else
		{
			for(int i = 1;i < n;i++)
			{
				m_sales[i] = sales[i];
				max = max < sales[i]?sales[i]:max;
				min = min > sales[i]?sales[i]:min;
				average += sales[i];
			}
			m_max = max;
			m_min = min;
			m_average = average / n;
		}
	}
	void Sales::setSales()
	{
		double max = 0;
		double min = 0;
		double average = 0;

		for(int i = 0;i < QUARTERS;i++)
		{
			std::cin >> m_sales[i];
			if(min == 0)
				min = m_sales[i];
			max = max < m_sales[i]?m_sales[i]:max;
			min = min > m_sales[i]?m_sales[i]:min;
			average += m_sales[i];
		}
		m_max = max;
		m_min = min;
		m_average = average / QUARTERS;
	}
	void Sales::showSales()const
	{
		for(int i = 0;i < QUARTERS;i++)
		{
			std::cout << m_sales[i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "average:" << m_average
			<< ",max:" << m_max
			<< ",min:" << m_min << std::endl;
	}
}