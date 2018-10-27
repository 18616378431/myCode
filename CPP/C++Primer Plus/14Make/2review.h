//2.
#ifndef REVIEW2_H_
#define REVIEW2_H_

class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char * s = "C++"){strncpy(fab,s,19);}
	virtual void tell(){std::cout << fab << std::endl;}
};
class Gloam
{
private:
	int glip;
	Frabjous fb;
public:
	Gloam(int g = 0,const char * s = "C++");
	Gloam(int g,const Frabjous & f);
	void tell();
};
Gloam::Gloam(int g,const char * s):glip(g),fb(s)
{

}
Gloam::Gloam(int g,const Frabjous & f):glip(g),fb(f)
{

}
void Gloam::tell()
{
	std::cout << glip << ",";
	fb.tell();
}

#endif