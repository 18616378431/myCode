//14.7 MI multi inheritance
#ifndef WORK0_H_
#define WORK0_H_

#include <string>

//abstract base class
class Worker
{
private:
	std::string fullname;
	long id;
public:
	Worker():fullname("no one"),id(0L){}
	Worker(const std::string & s,long n):fullname(s),id(n){}
	virtual ~Worker() = 0;//pure virtual destructor
	virtual void Set();
	virtual void Show()const;
};
//is-a derived class
class Waiter:public Worker
{
private:
	int panache;
public:
	Waiter():Worker(),panache(0){}
	Waiter(const std::string & s,long n,int p = 0):Worker(s,n),panache(p){}
	Waiter(const Worker & wk,int p = 0):Worker(wk),panache(p){}
	virtual void Set();
	virtual void Show()const;
};
//is-a derived class
class Singer:public Worker
{
protected:
	enum{other,alto,contralto,soprano,bass,baritone,tenor};
	enum{Vtypes=7};
private:
	static char * pv[Vtypes];
	int voice;
public:
	Singer():Worker(),voice(other){}
	Singer(const std::string & s,long n,int v = other):Worker(s,n),voice(v){}
	Singer(const Worker & wk,int v = other):Worker(wk),voice(v){}
	virtual void Set();
	virtual void Show()const;
};

//test case
class Test
{
private:
	int a;
	int b;
public:
	int c;
};

#endif
