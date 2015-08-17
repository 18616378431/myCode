extern double square(double);//其他文件中使具有外部链接的函数
double square(double x)
{
	double y;
	y = x * x;
	return y;
}