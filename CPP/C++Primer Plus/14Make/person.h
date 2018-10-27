//4.MI ABC
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//abc
class Person
{
private:
	std::string fname;
protected:
	void Data()const
	{
		std::cout << fname << std::endl;
	}
public:
	Person(std::string f):fname(f){}
	virtual ~Person(){}
	virtual void Show()const = 0
	{
		Data();
	}
	
};
//drived
class Gunslinger:virtual public Person
{
private:
	int kh;
	double drawtime;
protected:
	void Data()const
	{
		std::cout << "KH:" << kh << "Draw():" << Draw() << std::endl;
	}
public:
	Gunslinger(int k,double d,std::string f):kh(k),drawtime(d),Person(f){}
	double Draw()const
	{
		return drawtime;
	}
	virtual void Show()const
	{
		Person::Data();
		Data();
	}
};
class PokerPlayer:virtual public Person
{
protected:
	void Data()const
	{

	}
public:
	PokerPlayer(std::string f):Person(f){}
	virtual void Show()const
	{
		Person::Data();
		Data();
	}
	int Draw()const
	{
		srand(time(NULL));
		return std::rand() % 52 + 1;
	}
};
//MI
class BadDude:public Gunslinger,public PokerPlayer
{
protected:
	void Data()const
	{
		Gunslinger::Data();
		PokerPlayer::Data();
	}
public:
	BadDude(int k,double d,std::string f):Gunslinger(k,d,f),PokerPlayer(f),Person(f){}
	double Gdraw()const
	{
		return Gunslinger::Draw();
	}
	int Cdraw()const
	{
		return PokerPlayer::Draw();
	}
	virtual void Show()const
	{
		Person::Data();
		Data();
	}
};


#endif