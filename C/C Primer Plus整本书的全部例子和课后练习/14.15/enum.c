#include<stdio.h>
#include<string.h>//strcmp()
#define true 1
#define false 0
#define LEN 30
#define BOOL int

//Ã¶¾Ù
enum spectrum{red,orange,yellow,green,blue,violet};
const char * colors[] = {"red","orange","yellow","green","blue","violet"};

int main()
{
	char choice[LEN];
	enum spectrum color;
	BOOL color_is_found = false;

	puts("Enter a color(empty line to quit):");
	while(gets(choice) != NULL && choice[0] != '\0')
	{
		for(color =red;color <= violet;color++)
		{
			if(strcmp(choice,colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if(color_is_found)
		{
			switch(color)
			{
			case red:puts("Roses are red.");break;
			case orange:puts("Poppies are orange.");break;
			case green:puts("Grass are green.");break;
			case blue:puts("Bluebells are blue.");break;
			case violet:puts("Violet are violet.");break;
			case yellow:puts("Sunflowers are yellow.");break;
			}
		}
		else
		{
			printf("I don't know about the color %s.\n",choice);
		}
		color_is_found = false;
		puts("Enter next color(empty line to quit):");
	}
	puts("GoodBye!");
	return 0;
}