//5. MI emp.h
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

enum classkind{
	Employee,
	Manager,
	Fink,
	Highfink
};

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
protected:
	const std::string & GetFname()const{return fname;}
	const std::string & GetLname()const{return lname;}
	const std::string & GetJob()const{return job;}
	void SetFname(){std::cout << "Input fname:";std::getline(std::cin,fname);}
	void SetLname(){std::cout << "Input lname:";std::getline(std::cin,lname);}
	void SetJob(){std::cout << "Input job:";std::getline(std::cin,job);}
	void Data()const;
	void FileData(std::ofstream & out)const;
	void getFileData(std::ifstream & in);
	inline void eatLine()const{while(std::cin.get() != '\n')continue;}; 
public:
	abstr_emp();
	abstr_emp(const std::string & fn,const std::string & ln,const std::string & j);
	abstr_emp(const abstr_emp & e);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeAll(std::ofstream & out)const;
	virtual void getAll(std::ifstream & in);
	friend std::ostream & operator<< (std::ostream & os,const abstr_emp & e);
	virtual ~abstr_emp() = 0;
};
class employee:public abstr_emp
{
public:
	employee();
	employee(const std::string & fn,const std::string & ln,const std::string & j);
	~employee();
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeAll(std::ofstream & out)const;
	virtual void getAll(std::ifstream & in);
};
class manager:virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf()const{return inchargeof;}
	int & InChargeOf(){return inchargeof;}
	void SetInChageOf(){std::cout << "Input InChargeOf:";std::cin >> inchargeof;std::cin.get();}
	void writeIncharge(std::ofstream & out)const;
	void getIncharge(std::ifstream & in);
public:
	manager();
	manager(const std::string & fn,const std::string & ln,const std::string & j,int ico = 0);
	manager(const abstr_emp & e,int ico);
	manager(const manager & m);
	~manager();
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeAll(std::ofstream & out)const;
	virtual void getAll(std::ifstream & in);
};
class fink:virtual public abstr_emp
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo()const{return reportsto;}
	std::string & ReportsTo(){return reportsto;}
	void SetReportsto(){std::cout << "Input reportsto:";std::getline(std::cin,reportsto);}
	void writeReportsto(std::ofstream & out)const;
	void getReportsto(std::ifstream & in);
public:
	fink();
	fink(const std::string & fn,const std::string & ln,const std::string & j,const std::string & rpo);
	fink(const abstr_emp & e,const std::string & rpo);
	fink(const fink & f);
	~fink();
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeAll(std::ofstream & out)const;
	virtual void getAll(std::ifstream & in);
};
class highfink:public manager,public fink
{
public:
	highfink();
	highfink(const std::string & fn,const std::string & ln,const std::string & j,const std::string & rpo,int ico);
	highfink(const abstr_emp & e,std::string & rpo,int ico);
	highfink(const fink & f,int ico);
	highfink(const manager & m,const std::string & rpo);
	highfink(const highfink & h);
	~highfink();
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeAll(std::ofstream & out)const;
	virtual void getAll(std::ifstream & in);
};

#endif