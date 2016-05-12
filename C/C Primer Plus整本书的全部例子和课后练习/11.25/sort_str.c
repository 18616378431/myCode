#include<stdio.h>
#include<string.h>
#define SIZE 81
#define LIM 5

void ststr(char * strings[],int num);

int main()
{
	char input[LIM][SIZE];
	char * ptstr[LIM];
	int ct = 0;
	int k;

	while(ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}
	ststr(ptstr,ct);
	for(k = 0;k < ct;k++)
	{
		puts(ptstr[k]);
	}
	return 0;
}
//×Ö·û´®Ö¸ÕëÅÅÐò
void ststr(char * strings[],int num)
{
	char * temp;
	int top,seek;

	for(top = 0;top < num - 1;top++)
	{
		for(seek = top + 1;seek < num;seek++)
		{
			if(strcmp(strings[top],strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}