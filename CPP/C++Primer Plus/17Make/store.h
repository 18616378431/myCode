//write vector<string> contents to file
#ifndef STORE_H_
#define STORE_H_

#include <iostream>
#include <fstream>
#include <string>

class store
{
private:
	std::ofstream & o;
public:
	store(std::ofstream & out):o(out){}
	void operator() (const std::string & s);
};

#endif