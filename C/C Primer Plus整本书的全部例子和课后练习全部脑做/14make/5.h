#define LEN 41
#define SIZE 3
#define CSIZE 4

struct name{
	char fname[LEN];
	char lname[LEN];
};
struct student{
	struct name sname;
	float grade[SIZE];
	float avg;
};