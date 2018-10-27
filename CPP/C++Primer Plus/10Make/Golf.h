//3.
#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
	static const int LEN = 40;
	char m_fullanme[LEN];
	int m_handicap;
public:
	Golf();
	Golf(const char * fullname,const int handicap = 0);
	int setGolf();
	void setHandicap(const int handicap);
	void showGolf()const;
};

#endif