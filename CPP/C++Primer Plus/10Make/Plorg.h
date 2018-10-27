//7.
#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	static const int MAX = 20;
	char name[MAX];
	int ci;
public:
	Plorg();
	Plorg(char * my_name,int my_ci = 0);
	void modifyCI(int my_ci);
	void showPlorg()const;
};

#endif