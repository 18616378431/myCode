//诊断库assert.h，数学库使用
#include<stdio.h>
#include<math.h>
#include<assert.h>

int main()
{
	double x,y,z;

	puts("Enter a pair of number(0 0 ti quit):");
	while(scanf("%lf %lf",&x,&y) == 2 && x != 0 && y != 0)
	{
		z = x * x - y * y;
		assert(z >= 0);
		printf("answer is %.2lf.\n",sqrt(z));
		puts("Enter next pair of number(0 0 to quit):");
	}
	puts("Done");
	return 0;
}