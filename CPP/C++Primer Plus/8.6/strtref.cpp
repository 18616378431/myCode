//传递并返回引用的结构
#include<iostream>

using namespace std;

struct sysop{
	char name[26];
	char quote[64];
	int used;
};

const sysop & use(sysop & sysopref);

int main()
{
	/*sysop looper = {
		"Rick \"Fortran\" Looper",
		"I'm a goto kind of guy.",
		0
	};*/
	sysop looper = {
		"name",
		"quote",
		0
	};

	use(looper);
	cout << "Looper:" << looper.used << " use(s)\n";
	sysop copycat;
	copycat = use(looper);
	cout << "Looper:" << looper.used << " use(s)\n";
	cout << "Copycat:" << copycat.used << " use(s)\n";
	cout << "use(looper):" << use(looper).used << " use(s)\n";

	cout << "Looper address:" << &looper << endl;
	cout << "Copycat address:" << &copycat << endl;
	return 0;
}
const sysop & use(sysop & sysopref)
{
	cout << sysopref.name << " says:";
	cout << sysopref.quote << endl;
	sysopref.used++;
	return sysopref;
}