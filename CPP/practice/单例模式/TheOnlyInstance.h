#ifndef THE_ONLY_INSTANCE_H_
#define THE_ONLY_INSTANCE_H_

class TheOnlyInstance
{
public:
	static TheOnlyInstance * GetTheOnlyInstance();
protected:
	//inline constructor
	TheOnlyInstance()
	{
		a = 1;
		b = 2;
		c = 3;
	}
private:
	int a;
	int b;
	int c;
};
#endif