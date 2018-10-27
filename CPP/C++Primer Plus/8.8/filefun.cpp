#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

const int LIMIT = 5;

void file_it(ostream & os,double fo,const double fe[],int n);

int main()
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if(!fout.is_open())
	{
		cout << "Can't open file " << fn << ".Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your telescope objective in mm:";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths,in mm,of " << LIMIT << " eyepieces:\n";
	for(int i = 0;i < LIMIT;i++)
	{
		cout << "Eyepiece #" << i + 1 << ":";
		cin >> eps[i];
	}
	file_it(fout,objective,eps,LIMIT);
	file_it(cout,objective,eps,LIMIT);
	cout << "Done.\n";
	return 0;
}
//基类引用可以指向派生类
void file_it(ostream & os,double fo,const double fe[],int n)
{
	//保持格式化状态类型
	ios_base::fmtflags initial;
	//将输出格式设置为定点表示法模式
	initial = os.setf(ios_base::fixed);

	//0个小数位
	os.precision(0);
	os << "Focal length of objective:" << fo << "mm.\n";
	//显示小数模式
	os.setf(ios_base::showpoint);
	os.precision(1);
	//下次输出使用的字段宽度
	os.width(12);
	os << "f eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for(int i = 0;i < n;i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo/fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}