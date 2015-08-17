//字符数组大小
#define SLEN 32

//结构声明
struct names_st{
	char first[SLEN];
	char last[SLEN];
};

//类型定义
typedef struct names_st NAMES;

//函数声明
void getName(NAMES * ps);
void showName(const NAMES * ps);