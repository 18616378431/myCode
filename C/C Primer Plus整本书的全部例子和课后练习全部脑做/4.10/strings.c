//字符串的格式化
#include<stdio.h>
#define BLURB "Authentic imitation!"

int main(void)
{
	int a;
	scanf("%d",&a);
	printf("/%2s/ \n",BLURB);
	printf("/%25s/ \n",BLURB);
	printf("/%24.5s/ \n",BLURB);
	printf("/%-24.5s/ \n",BLURB);
	return 0;
}