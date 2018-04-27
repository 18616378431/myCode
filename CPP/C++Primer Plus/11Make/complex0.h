//7. ¸´Êý
#ifndef COMPLEX0_H_
#define COMPLEX0_H_

class Complex
{
private:
	double real;
	double virtual_val;
public:
	Complex();
	Complex(double r,double v);
	~Complex();
	//overload
	Complex operator+ (const Complex & c)const;
	Complex operator- (const Complex & c)const;
	Complex operator* (const Complex & c)const;
	//friend
	friend Complex operator* (int n,const Complex & c)//inline
	{
		return Complex(c.real * n,c.virtual_val * n);
	}
	friend Complex operator~ (const Complex & c)//inline
	{
		return Complex(c.real,-c.virtual_val);
	}
	friend std::ostream & operator<< (std::ostream & os,const Complex & c);
	friend std::istream & operator>> (std::istream & is,Complex & c);
};

#endif