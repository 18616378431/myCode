//11.14 矢量类定义
#include<cmath>
#include"vector.h"

using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 57.2957795130823;

	//private
	/*void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang()
	{
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y,x);
	}*/
	//polar coordinate
	void Vector::set_x(const double mag,const double ang)
	{
		x = mag * cos(ang);
	}
	void Vector::set_y(const double mag,const double ang)
	{
		y = mag * sin(ang);
	}
	//public method
	Vector::Vector()
	{
		//x = y = mag = ang = 0.0;
		x = y = 0.0;
		mode = 'r';
	}
	//r 直角坐标
	//p 极坐标
	Vector::Vector(double n1,double n2,char form)
	{
		mode = form;
		if(form == 'r')
		{
			x = n1;
			y = n2;
			/*set_mag();
			set_ang();*/
		}
		else if(form == 'p')
		{
			set_x(n1,n2 / Rad_to_deg);
			set_y(n1,n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0\n";
			//x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = 'r';
		}
	}
	void Vector::set(double n1,double n2,char form)
	{
		mode = form;
		if(form == 'r')
		{
			x = n1;
			y = n2;
			/*set_mag();
			set_ang();*/
		}
		else if(form == 'p')
		{
			set_x(n1,n2 / Rad_to_deg);
			set_y(n1,n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0.\n";
			//x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = 'r';
		}
	}
	Vector::~Vector()
	{

	}
	double Vector::magval()const
	{
		
		return sqrt(x * x + y * y);
	}
	double Vector::angval()const
	{
		double ang;
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y,x);
		return ang;
	}
	void Vector::polar_mode()
	{
		mode = 'p';
	}
	void Vector::rect_mode()
	{
		mode = 'r';
	}
	//操作符重载
	Vector Vector::operator +(const Vector & b)const
	{
		return Vector(x + b.x,y + b.y);
	}
	Vector Vector::operator -(const Vector & b)const
	{
		return Vector(x - b.x,y - b.y);
	}
	//反转矢量符号
	Vector Vector::operator -()const
	{
		return Vector(-x,-y);
	}
	//矢量*n
	Vector Vector::operator *(double n)const
	{
		return Vector(x * n,y * n);
	}
	//友元
	//矢量*n
	Vector operator *(double n,const Vector & a)
	{
		return a * n;
	}
	//mode r 显示直角坐标
	//mode p 显示极坐标
	std::ostream & operator <<(std::ostream & os,const Vector & v)
	{
		if(v.mode == 'r')
		{
			os << "(x,y) = (" << v.x << "," << v.y << ")";
		}
		else if(v.mode == 'p')
		{
			os << "(m,a) = (" << v.magval() << "," << v.angval() * Rad_to_deg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	}
	//convert
	Vector::operator double()const
	{
		return magval();
	}
}