#include<stdio.h>

struct thinkerbell{//从右向左填充结构位字段
	unsigned int rp:2;//1.4M软盘驱动器的的数量0,1
	unsigned int   :1;//空白位2
	unsigned int cd:2;//CD-ROM驱动器数量,3,4
	unsigned int   :1;//空白位,5
	unsigned int yp:2;//硬盘驱动器数量,6,7
};

struct Klinkbell{//从左往右填充,int四字节，每字节8位，共32位，要空出24位，与从右向左填充位对齐
	unsigned int   :24;//空白
	unsigned int yp:2;
	unsigned int   :1;
	unsigned int cd:2;
	unsigned int   :1;
	unsigned int rp:2;
};

int main()
{

	return 0;
}