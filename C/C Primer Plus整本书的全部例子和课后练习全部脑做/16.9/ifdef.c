//��������,#ifdef��#else��#endif
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

	printf("The file is %s.\n",__FILE__);//��ǰԴ�ļ�����
	printf("The date is %s.\n",__DATE__);//Ԥ��������
	printf("The time is %s.\n",__TIME__);//�ļ�����ʱ��
	//printf("The version is %s.\n",__STDC_VARSION__);C99��׼��__STDC_VARSION__����C99ʱΪ199901L
	printf("The line is %d.\n",__LINE__);//��ǰ�к�
	//printf("The functon is %s.\n",__func__);
	whyMe();
}

void whyMe()
{
	//printf("This is function %s.\n",__func__);C99���ã�__func__����ǰ�������Ƶ��ַ���
	printf("This is line %d.\n",__LINE__);
}