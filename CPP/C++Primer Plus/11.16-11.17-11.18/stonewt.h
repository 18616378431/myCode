//11.16 镑-英石转换
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum{Lbs_per_stn = 14};//枚举常量
	//static const int Lbs_per_stn = 14;
	int stone;//英石
	double pds_left;
	double pounds;//磅
public:
	Stonewt(double lbs);//for pounds
	Stonewt(int stn,double lbs);//for stone,lbs
	Stonewt();//默认构造函数
	~Stonewt();//析构函数
	void show_lbs()const;//show weight in pounds
	void show_stn()const;//show weight int stone
};

#endif