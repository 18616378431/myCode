//条件编译,#ifdef、#else、#endif
#include<stdio.h>
#define JUST_CHEKING
#define LIMIT 4
#include"nams_st.h"
#include"nams_st.h"

void whyMe();

int main()
{
	int i;
	int total = 0;
	NAMES winner ={"wang","kang"};
	
	for(i = 0;i < LIMIT;i++)
	{
		total += 2 * i * i +1;
#ifdef JUST_CHEKING
		printf("i = %d,runing total = %d.\n",i,total);
#endif
	}
	printf("Grand total = %d.\n",total);
	printf("The winner is %s %s.\n",winner.first,winner.last);

	printf("The file is %s.\n",__FILE__);//当前源文件名称
	printf("The date is %s.\n",__DATE__);//预处理日期
	printf("The time is %s.\n",__TIME__);//文件编译时间
	//printf("The version is %s.\n",__STDC_VARSION__);C99标准，__STDC_VARSION__设置C99时为199901L
	printf("The line is %d.\n",__LINE__);//当前行号
	//printf("The functon is %s.\n",__func__);
	whyMe();
}

void whyMe()
{
	//printf("This is function %s.\n",__func__);C99可用，__func__代表当前函数名称的字符串
	printf("This is line %d.\n",__LINE__);
}