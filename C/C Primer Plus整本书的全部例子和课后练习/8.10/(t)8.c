#include<stdio.h>

float get_float();

int main(void)
{
	char ch;
	float na;
	float nb;
	float sum;

	
	printf("Enter the operation of your choice:\n");
	printf("a.add\t\ts.subtract\n");
	printf("m.multiply\td.divide\nq.quit\n");
	while((ch = getchar()) != EOF)
	{
		switch(ch)
		{
		case 'a':
			printf("Enter first number:\n");
			na = get_float();
			printf("Enter second number:\n");
			nb = get_float();
			sum = na + nb;
			printf("%.1f + %.1f = %.1f\n",na,nb,sum);
			break;
		case 's':
			printf("Enter first number:\n");
			na = get_float();
			printf("Enter second number:\n");
			nb = get_float();
			sum = na - nb;
			printf("%.1f - %.1f = %.1f\n",na,nb,sum);
			break;
		case 'm':
			printf("Enter first number:\n");
			na = get_float();
			printf("Enter second number:\n");
			nb = get_float();
			sum = na * nb;
			printf("%.1f * %.1f = %.1f\n",na,nb,sum);
			break;
		case 'd':
			printf("Enter first number:\n");
			na = get_float();
			printf("Enter second number:\n");
			nb = get_float();
			if(nb == 0)
			{
				printf("Enter a number other than 0:\n");
				nb = get_float();
			}
			sum  = na / nb;
			printf("%.1f / %.1f = %.1f\n",na,nb,sum);
			break;
		case 'q':
			printf("Good Bye!\n");
			break;
		default:
			printf("Please enter letter such as a,s,m,d or q!\n");
			break;
		}
		if(ch == 'q')
			break;
		while(getchar() != '\n')
			continue;
		printf("Enter the operation of your choice:\n");
		printf("a.add\t\ts.subtract\n");
		printf("m.multiply\td.divide\nq.quit\n");
	}
	return 0;
}
//获取一个浮点型数值
float get_float()
{
	float input;	//存储整数
	char cr;	//存储非法字符
	
	while(scanf("%f",&input) != 1)
	{
		while((cr = getchar()) != '\n')
			putchar(cr);
		printf(" is not a integer!Please try another once.\n");
	}
	return input;
}

//获取两个操作数