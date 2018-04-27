//14.16 use char * Stack<Type> template <class Type>
//tempalte class for char *
#include <iostream>
#include <cstdlib>//rand() srand()
#include <ctime>//time()
#include "stcktp1.h"

const int num = 10;

int main()
{
	std::srand(std::time(0));
	std::cout << "Please enter stacksize:";
	int stacksize;
	std::cin >> stacksize;
	//create empty stack
	Stack<const char *> st(stacksize);
	
	//in basket
	const char * in[num] = {
		"1:w1","2:w2",
		"3:w3","4:w4",
		"5:w5","6:w6",
		"7:w7","8:w8",
		"9:w9","10:w10"
	};
	//out basket
	const char * out[num];

	int processed = 0;
	int nextin = 0;
	while(processed < num)
	{
		if(st.isempty())
			st.push(in[nextin++]);
		else if(st.isfull())
			st.pop(out[processed++]);
		else if(std::rand() % 2 && nextin < num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for(int i = 0;i < num;i++)
		std::cout << out[i] << std::endl;
	
	std::cout << "Bye.\n";

	return 0;
}