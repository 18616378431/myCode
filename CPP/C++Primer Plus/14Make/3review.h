//3.
#ifndef REVIEW3_H_
#define REVIEW3_H_

class Gloam1:private Frabjous
{
private:
	int glip;
public:
	Gloam1(int g = 0,const char * s = "C++");
	Gloam1(int g,const Frabjous & f);
	void tell();
};
Gloam1::Gloam1(int g,const char * s):glip(g),Frabjous(s)
{

}
Gloam1::Gloam1(int g,const Frabjous & f):glip(g),Frabjous(f)
{

}
void Gloam1::tell()
{
	std::cout << glip << ",";
	Frabjous::tell();
}

#endif