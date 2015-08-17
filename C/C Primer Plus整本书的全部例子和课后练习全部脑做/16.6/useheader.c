#include<stdio.h>
#include"names_st.h"

int main()
{	
	NAMES candit;
	
	getName(&candit);
	printf("Let's welcome ");
	showName(&candit);
	printf(" to this program!\n");
	return 0;
}