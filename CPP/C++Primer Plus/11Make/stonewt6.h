////11.16 ��-Ӣʯת��
//#ifndef STONEWT6_H_
//#define STONEWT6_H_
//
//class Stonewt
//{
//private:
//	enum{Lbs_per_stn = 14};//ö�ٳ���
//	//static const int Lbs_per_stn = 14;
//	int stone;//Ӣʯ
//	double pds_left;
//	double pounds;//��
//	char mode;//s=>stone mode,p=>pounds mode
//public:
//	Stonewt(double lbs);//for pounds
//	Stonewt(int stn,double lbs);//for stone,lbs
//	Stonewt();//Ĭ�Ϲ��캯��
//	~Stonewt();//��������
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