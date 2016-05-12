//指向结构的指针
#include<stdio.h>
#define LEN 20

struct names{
	char first[LEN];
	char last[LEN];
};
struct guy{
	struct names handle;//嵌套结构
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main()
{
	struct guy fellow[2] = {//声明一个具有两个元素的结构数组，每个元素都是guy类型结构
		{{"Ewen","Villard"},
			"grilled salmon",
			"personality coach",
			58112.00},
		{{"Rodeny","Swillbelly"},
			"tripe",
			"tabloid editor",
			232400}
	};
	struct guy * him;//定义指向结构的指针
	//输出结构数组两个元素的首地址
	printf("address #1:%p,#2:%p.\n",&fellow[0],&fellow[1]);
	//告诉结构指针要指向的地址
	him = &fellow[0];
	//输出结构指针指向的地址
	printf("address #1:%p,#2:%p.\n",him,him + 1);
	printf("him->income is %.2f,(*him).income is %.2f.\n",him->income,(*him).income);
	him++;//指针后移，指向下一个结构
	printf("him->favfood is %s,him->handle.last is %s.\n",him->favfood,him->handle.last);
	return 0;
}