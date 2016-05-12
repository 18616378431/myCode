//产生随机数
//无标准输入输出，不需包含标准输入输出头文件

static unsigned long int next = 1;//文件作用域、静态存储时期、内部链接
int rand0(void)
{
	//产生伪随机数公式
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536)%32768;
}
