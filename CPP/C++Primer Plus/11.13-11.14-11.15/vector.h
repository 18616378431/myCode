//11.13 ʸ��������
#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>

namespace VECTOR
{
	class Vector
	{
	private:
		double x;//ˮƽ����
		double y;//��ֱ����
		double mag;//ʸ������
		double ang;//ʸ������
		char mode;//'r' = rectangular,'p' = polar
		//˽������ֵ����
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
		void polar_mode();//����modeΪp
		void rect_mode();//����modeΪr
		//����������
		Vector operator +(const Vector & b)const;
		Vector operator -(const Vector & b)const;
		Vector operator -()const;
		Vector operator *(double n)const;
		//��Ԫ
		friend Vector operator *(double n,const Vector & a);
		friend std::ostream & operator <<(std::ostream & os,const Vector & v);
	};
}

#endif