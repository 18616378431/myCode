#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char ch;
	int a_ct,e_ct,i_ct,o_ct,u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("Enter some text;'#' to quit! \n");
	while((ch = getchar()) != '#')
	{
		ch = toupper(ch);		//将获取字母转换为大写
		switch(ch)
		{
		case 'A':
			a_ct++;
			break;
		case 'E':
			e_ct++;
			break;
		case 'I':
			i_ct++;
			break;
		case 'O':
			o_ct++;
			break;
		case 'U':
			u_ct++;
			break;
		default:
			break;
		}
	}
	printf("number of vowels:\nA\tE\tI\tO\tU\n");
	printf("%d\t%d\t%d\t%d\t%d\n",a_ct,e_ct,i_ct,o_ct,u_ct);
	return 0;
}
