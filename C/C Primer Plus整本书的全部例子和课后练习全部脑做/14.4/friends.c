//ָ��ṹ��ָ��
#include<stdio.h>
#define LEN 20

struct names{
	char first[LEN];
	char last[LEN];
};
struct guy{
	struct names handle;//Ƕ�׽ṹ
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main()
{
	struct guy fellow[2] = {//����һ����������Ԫ�صĽṹ���飬ÿ��Ԫ�ض���guy���ͽṹ
		{{"Ewen","Villard"},
			"grilled salmon",
			"personality coach",
			58112.00},
		{{"Rodeny","Swillbelly"},
			"tripe",
			"tabloid editor",
			232400}
	};
	struct guy * him;//����ָ��ṹ��ָ��
	//����ṹ��������Ԫ�ص��׵�ַ
	printf("address #1:%p,#2:%p.\n",&fellow[0],&fellow[1]);
	//���߽ṹָ��Ҫָ��ĵ�ַ
	him = &fellow[0];
	//����ṹָ��ָ��ĵ�ַ
	printf("address #1:%p,#2:%p.\n",him,him + 1);
	printf("him->income is %.2f,(*him).income is %.2f.\n",him->income,(*him).income);
	him++;//ָ����ƣ�ָ����һ���ṹ
	printf("him->favfood is %s,him->handle.last is %s.\n",him->favfood,him->handle.last);
	return 0;
}