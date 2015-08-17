#include<stdio.h>//该文件进行标准输入输出
#include"names_st.h"

void getName(NAMES * ps)
{
	int i = 0;

	printf("Enter your first name:");
	fgets(ps->first,SLEN,stdin);
	while(ps->first[i] != '\n' && ps->first[i] != '\0')
		i++;
	if(ps->first[i] == '\n')
		ps->first[i] = '\0';
	else
		while(getchar() != '\n')//行结尾之前结束，清除剩余字符直到换行
			continue;
	printf("Enter your last name:");
	fgets(ps->last,SLEN,stdin);
	i = 0;
	while(ps->last[i] != '\n' && ps->last[i] != '\0')
		i++;
	if(ps->last[i] == '\n')
		ps->last[i] = '\0';
	else
		while(getchar() != '\n')
			continue;
}

void showName(const NAMES * ps)
{
	printf("%s %s ",ps->first,ps->last);
}