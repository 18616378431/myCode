#include<stdio.h>//���ļ����б�׼�������
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
		while(getchar() != '\n')//�н�β֮ǰ���������ʣ���ַ�ֱ������
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