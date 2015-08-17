//记录看电影名称和评价
//修改，动态内存分配
#include<stdio.h>
#include<stdlib.h>
#define TSIZE 45
//#define FMAX 5

struct film{
	char title[TSIZE];
	int rating;
};

void delMore();
void showList(struct film fs[],int n);

int main()
{
	struct film * movies;
	int i = 0;
	int ct;

	puts("Enter the maximum number of movies you will enter:");
	scanf("%d",&ct);
	movies = (struct film *)malloc(ct * sizeof(struct film));
	delMore();
	puts("Enter the first film name:");
	while(i < ct && gets(movies[i].title) && movies[i].title[0] != '\0')
	{
		puts("Enter your rating:");
		scanf("%d",&movies[i++].rating);
		delMore();
		puts("Enter the next movie(empty line to quit):");
	}
	if(i == 0)
		puts("Too bad!No data!");
	else
		puts("Here is the movies list:");
	showList(movies,i);
	puts("Bye!");
	free(movies);
	return 0;
}
void delMore()
{
	while(getchar() != '\n')
		continue;
}
void showList(struct film fs[],int n)
{
	int i;

	for(i = 0;i < n;i++)
		printf("Movies:%-9s rating:%-5d\n",fs[i].title,fs[i].rating);
}