namespace SALES
{
	//constant define
	const int QUARTERS = 4;

	//type
	struct Sales{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	//function КЏЪ§жиди
	void setSales(Sales & s,const double ar[],int n);

	void setSales(Sales & s);

	void showSales(const Sales & s);

	double getMax(const double ar[],int n);

	double getMin(const double ar[],int n);
}