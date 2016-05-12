//不使用指针，传递结构，返回结构
#include<stdio.h>
#include<string.h>
#define LEN 20

struct namect{
	char fname[LEN];
	char lname[LEN];
	size_t letters;
};

struct namect getInfo(void);
struct namect makeInfo(struct namect make);
void showInfo(const struct namect show);

int main()
{
	struct namect person;

	person = getInfo();
	person = makeInfo(person);
	showInfo(person);
	return 0;
}
struct namect getInfo(void)
{
	struct namect temp;

	puts("Enter your first name:");
	gets(temp.fname);
	puts("Enter your last name:");
	gets(temp.lname);

	return temp;
}
struct namect makeInfo(struct namect make)
{
	make.letters = strlen(make.fname) + strlen(make.lname);

	return make;
}
void showInfo(const struct namect show)
{
	printf("%s %s,there is %d letters in your name.\n",show.fname,show.lname,show.letters);
}