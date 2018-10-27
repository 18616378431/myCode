////11.16 镑-英石转换
//#ifndef STONEWT6_H_
//#define STONEWT6_H_
//
//class Stonewt
//{
//private:
//	enum{Lbs_per_stn = 14};//枚举常量
//	//static const int Lbs_per_stn = 14;
//	int stone;//英石
//	double pds_left;
//	double pounds;//磅
//	char mode;//s=>stone mode,p=>pounds mode
//public:
//	Stonewt(double lbs);//for pounds
//	Stonewt(int stn,double lbs);//for stone,lbs
//	Stonewt();//默认构造函数
//	~Stonewt();//析构函数
//	//inline getter
//	double poundsval()const
//	{
//		return pounds;
//	}
//	int stoneval()const
//	{
//		return stone;
//	}
//	void show_lbs()const;//show weight in pounds
//	void show_stn()const;//show weight int stone
//	//status
//	void stone_mode();
//	void pounds_mode();
//	//overload
//	Stonewt operator+ (const Stonewt & t)const;
//	Stonewt operator- (const Stonewt & t)const;
//	Stonewt operator* (double n)const;
//	Stonewt operator/ (double n)const;
//	Stonewt operator% (int n)const;
//	bool operator< (const Stonewt & t)const;
//	//friend inline
//	friend Stonewt operator* (double n,const Stonewt & t)
//	{
//		return t * n;
//	}
//	friend Stonewt operator/ (double n,const Stonewt & t)
//	{
//		return t / n;
//	}
//	friend Stonewt operator% (int n,const Stonewt & t)
//	{
//		return t % n;
//	}
//	friend std::ostream & operator<< (std::ostream & os,const Stonewt & t);
//	
//};
//
//#endif