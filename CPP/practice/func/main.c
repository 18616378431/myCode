#include<stdio.h>

int func(int n);

int main()
{
	int n,result;

	printf("please input n:\n");
	scanf("%d",&n);
	result = func(n);
	//printf("result=%d\n",result);
	return 0;
}
//ตÝน้
int func(int n)
{
	int r;
	if(n < 0)
	{
		printf("Data error!\n");
		return ;
	}else if(n == 0 || n == 1){
		r = 1;
	}else{
		r = func(n - 1)*n;
	}
	return r;
}