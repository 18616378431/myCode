//Ƕ�׽ṹ
#include<stdio.h>
#define LEN 20

const char * msg[5] = {
		"  Thank you for the wonderful evening.",
		"you certainly prove that a",
		"is a special kind of guy.We must get together",
		"over a delicious ",
		"and have a few laughs"
};
struct names{
	char first[LEN];
	char last[LEN];
};
struct guy{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main()
{
	struct guy fellow = {
		{"Ewen","Villard"},
		"grilled salmon",
		"personality coach",
		51128.00
	};

	printf("Dear %s,\n\n",fellow.handle.first);
	printf("%s%s.\n",msg[0],fellow.handle.first);
	printf("%s%s\n",msg[1],fellow.job);
	printf("%s\n",msg[2]);
	printf("%s%s%s",msg[3],fellow.favfood,msg[4]);
	if(fellow.income > 150000.0)
		puts("!!");
	else if(fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s\n","See you soon");
	printf("%40s\n","Shalala");
	return 0;
}