//11.16 ��-Ӣʯת��
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum{Lbs_per_stn = 14};//ö�ٳ���
	//static const int Lbs_per_stn = 14;
	int stone;//Ӣʯ
	double pds_left;
	double pounds;//��
public:
	Stonewt(double lbs);//for pounds
	Stonewt(int stn,double lbs);//for stone,lbs
	Stonewt();//Ĭ�Ϲ��캯��
	~Stonewt();//��������
	void show_lbs()const;//show weight in pounds
	void show_stn()const;//show weight int stone
};

#endif