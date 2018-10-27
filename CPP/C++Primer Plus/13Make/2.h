//1.��ͨ��̳�
#ifndef CD_H_
#define CD_H_

//represents a CD disk base class
class Cd
{
private:
	char * performers;//[50]
	char * label;//[20];
	int selections;//number of selections
	double playtime;//playing time in minutes
protected:
	enum{MAX = 50,LMAX = 20};
	std::ios_base::fmtflags SetFormat()const;
public:
	Cd();
	Cd(const char * s1,const char * s2,int n,double x);
	Cd(const Cd & cs);
	Cd & operator= (const Cd & cs);
	virtual ~Cd();
	virtual void Report()const;//reports all CD data
};

//derived class
class Classic:public Cd
{
private:
	char * major;//[50];
public:
	Classic();
	Classic(const char * m,const char * s1,const char * s2,int n,double x);
	Classic(const Classic & cs);
	Classic & operator= (const Classic & cs);
	virtual ~Classic();
	virtual void Report()const;//reports classic data
};

#endif