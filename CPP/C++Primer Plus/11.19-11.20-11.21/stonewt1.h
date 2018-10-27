//11.19 类转换为内置类型
#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
	enum{Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn,double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs()const;
	void show_stn()const;
	//类转换函数
	operator int()const;
	operator double()const;
};

#endif