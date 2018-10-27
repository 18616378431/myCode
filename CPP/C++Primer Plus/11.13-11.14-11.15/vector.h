//11.13 矢量类声明
#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>

namespace VECTOR
{
	class Vector
	{
	private:
		double x;//水平分量
		double y;//垂直分量
		double mag;//矢量长度
		double ang;//矢量方向
		char mode;//'r' = rectangular,'p' = polar
		//私有设置值方法
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1,double n2,char form = 'r');
		void set(double n1,double n2,char form = 'r');
		~Vector();
		double xval()const{return x;}
		double yval()const{return y;}
		double magval()const{return mag;}
		double angval()const{return ang;}
		void polar_mode();//设置mode为p
		void rect_mode();//设置mode为r
		//操作符重载
		Vector operator +(const Vector & b)const;
		Vector operator -(const Vector & b)const;
		Vector operator -()const;
		Vector operator *(double n)const;
		//友元
		friend Vector operator *(double n,const Vector & a);
		friend std::ostream & operator <<(std::ostream & os,const Vector & v);
	};
}

#endif