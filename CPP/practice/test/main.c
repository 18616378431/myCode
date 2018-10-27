#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STR_LENGTH 1024

int main()
{
	
	char str[MAX_STR_LENGTH];
	FILE * fp; 
	int i = 0;
	time_t st,ed;

	st = time(NULL);

	fp = fopen("C:\\soft\\myproject\\test\\doc\\ViewLog.log","r");
	while(fgets(str,MAX_STR_LENGTH,fp))
	{
		printf("%s\n",str);
	}
	fclose(fp);

	ed = time(NULL);
	printf("读取100w数据时间:%d\n",(ed-st));
	return 0;
}