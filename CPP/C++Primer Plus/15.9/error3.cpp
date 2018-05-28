//15.9 try catch throw
#include <iostream>

double hmean(double a,double b);

int main()
{

	double x,y,z;
	std::cout << "Enter two numbers:";
	while(std::cin >> x >> y)
	{
		try//try block
		{
			z = hmean(x,y);
		}
		catch(const char * s)//exception handler
		{
			std::cout << s << std::endl;
			std::cout << "Enter new pair of numbers:";
			continue;
		}
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>:";
	}
	std::cout << "Bye.\n";

	return 0;
}
double hmean(double a,double b)
{
	if(a == -b)
		throw "bad hmean() arguments:a = -b not allowed";
	return 2.0 * a * b / (a + b);
}