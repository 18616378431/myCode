//多文件编译,函数重载
#ifndef GOLF_H_
#define GOLF_H_

const int LEN = 4;

struct golf{
	char fullname[LEN];
	int handicap;
};
//第一个版本
void setgolf(golf & g,char * name,int hc);

//重载版本
int setgolf(golf & g);

//重置handicap为新值
void handicap(golf & g,int hc);

//显式结构体内容
void showgolf(const golf & g);
#endif