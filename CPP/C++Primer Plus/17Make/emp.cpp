//5.MI
#include "emp.h"

//abc and pure virtual function
abstr_emp::abstr_emp():fname("none"),lname("none"),job("none")
{

}
abstr_emp::abstr_emp(const std::string & fn,const std::string & ln,const std::string & j)
	:fname(fn),lname(ln),job(j)
{

}
abstr_emp::abstr_emp(const abstr_emp & e):fname(e.fname),lname(e.lname),job(e.job)
{

}
void abstr_emp::Data()const
{
	std::cout << "fname:" << fname
		<< ",lname:" << lname
		<< ",job:" << job << std::endl;
}
void abstr_emp::ShowAll()const
{
	Data();
}
void abstr_emp::SetAll()
{
	SetFname();
	SetLname();
	SetJob();
}
std::ostream & operator<< (std::ostream & os,const abstr_emp & e)
{
	os << "fname:" << e.fname
		<< ",lname:" << e.lname
		<< ",job:" << e.job << std::endl;
	return os;
}
void abstr_emp::FileData(std::ofstream & out)const
{
	out << fname << "\n" << lname << "\n" << job << "\n";
}
void abstr_emp::getFileData(std::ifstream & in)
{
	std::getline(in,fname);
	std::getline(in,lname);
	std::getline(in,job);

	//in >> fname >> lname >> job;
}
void abstr_emp::writeAll(std::ofstream & out)const//out ofstream
{
	FileData(out);
}
void abstr_emp::getAll(std::ifstream & in)//in ifstream
{
	getFileData(in);
}
abstr_emp::~abstr_emp()
{

}

//employee
employee::employee():abstr_emp()
{

}
employee::employee(const std::string & fn,const std::string & ln,const std::string & j)
	:abstr_emp(fn,ln,j)
{

}
employee::~employee()
{

}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}
void employee::writeAll(std::ofstream & out)const
{
	abstr_emp::writeAll(out);
}
void employee::getAll(std::ifstream & in)
{
	abstr_emp::getAll(in);
}

//manager
manager::manager():abstr_emp()
{
	inchargeof = 0;
}
manager::manager(const std::string & fn,const std::string & ln,const std::string & j,int ico)
	:abstr_emp(fn,ln,j)
{
	inchargeof = ico;
}
manager::manager(const abstr_emp & e,int ico):abstr_emp(e)
{
	inchargeof = ico;
}
manager::manager(const manager & m):abstr_emp((const abstr_emp &)m)
{
	inchargeof = m.inchargeof;
}
manager::~manager()
{

}
void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	std::cout << "inchargeof:" << inchargeof << std::endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	SetInChageOf();
}
void manager::writeIncharge(std::ofstream & out)const
{
	out << inchargeof << "\n";
}
void manager::getIncharge(std::ifstream & in)
{
	in >> inchargeof;
	in.get();
}
void manager::writeAll(std::ofstream & out)const
{
	abstr_emp::writeAll(out);
	writeIncharge(out);
}
void manager::getAll(std::ifstream & in)
{
	abstr_emp::getAll(in);
	getIncharge(in);
}

//fink
fink::fink():abstr_emp()
{
	reportsto = "NULL";
}
fink::fink(const std::string & fn,const std::string & ln,const std::string & j,const std::string & rpo)
	:abstr_emp(fn,ln,j),reportsto(rpo)
{

}
fink::fink(const abstr_emp & e,const std::string & rpo):abstr_emp(e),reportsto(rpo)
{

}
fink::fink(const fink & f):abstr_emp((const abstr_emp &)f)
{
	reportsto = f.reportsto;
}
fink::~fink()
{

}
void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	std::cout << "reportsto:" << ReportsTo() << std::endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	SetReportsto();
}
void fink::writeReportsto(std::ofstream & out)const
{
	out << reportsto << "\n";
}
void fink::getReportsto(std::ifstream & in)
{
	std::getline(in,reportsto);
	//in >> reportsto;//discard \n
}
void fink::writeAll(std::ofstream & out)const
{
	abstr_emp::writeAll(out);
	writeReportsto(out);
}
void fink::getAll(std::ifstream & in)
{
	abstr_emp::getAll(in);
	getReportsto(in);
}

//highfink
highfink::highfink():abstr_emp(),manager(),fink()
{

}
highfink::highfink(const std::string & fn,const std::string & ln,const std::string & j,const std::string & rpo,int ico)
	:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo)
{

}
highfink::highfink(const abstr_emp & e,std::string & rpo,int ico)
	:abstr_emp(e),manager((const abstr_emp &)e,ico),fink((const abstr_emp &)e,rpo)
{

}
highfink::highfink(const fink & f,int ico)
	:abstr_emp((const abstr_emp &)f),manager((const abstr_emp &)f,ico),fink(f)
{

}
highfink::highfink(const manager & m,const std::string & rpo)
	:abstr_emp((const abstr_emp &)m),manager(m),fink((const abstr_emp &)m,rpo)
{
	
}
highfink::highfink(const highfink & h)
	:abstr_emp((const abstr_emp &)h),manager((const manager &)h),fink((const fink &)h)
{

}
highfink::~highfink()
{

}
void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	std::cout << "InChargeOf:" << InChargeOf() << std::endl;
	std::cout << "Reportsto:" << ReportsTo() << std::endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::SetInChageOf();
	fink::SetReportsto();
}
void highfink::writeAll(std::ofstream & out)const
{
	abstr_emp::writeAll(out);
	manager::writeIncharge(out);
	fink::writeReportsto(out);

}
void highfink::getAll(std::ifstream & in)
{
	abstr_emp::getAll(in);
	manager::getIncharge(in);
	fink::getReportsto(in);
}