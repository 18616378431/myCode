#include<stdio.h>
#include<string.h>

//strcmp()�ķ���ֵ��������ͬ����0����һ��������ASC||��ֵ��ȥ�ڶ���������ASC||��ֵ������0������1��С��0������-1
int main()
{
	//��ͬ
	puts("strcmp(\"A\",\"A\") is");
	printf("%d.\n",strcmp("A","A"));
	//
	puts("strcmp(\"A\",\"B\") is");
	printf("%d.\n",strcmp("A","B"));
	//
	puts("strcmp(\"B\",\"A\") is");
	printf("%d.\n",strcmp("B","A"));
	//
	puts("strcmp(\"C\",\"A\") is");
	printf("%d.\n",strcmp("C","A"));
	//
	puts("strcmp(\"Z\",\"a\") is");
	printf("%d.\n",strcmp("Z","a"));
	//
	puts("strcmp(\"apples\",\"apple\")");
	printf("%d.\n",strcmp("apples","apple"));

	return 0;
}