////new布局操作符指定区域分配内存和heap分配内存
//#include<iostream>
//#include<new>
//
//const int LEN = 512;
//const int N = 2;
//
//char buffer[LEN];
//
//struct chaff{
//	char dross[20];
//	int slag;
//};
//
//void set_value(struct chaff & c);
//void show_value(const struct chaff & c);
//
//int main()
//{
//	//布局new操作符需包含头文件new
//	struct chaff * pcn = new (buffer) chaff[N];
//	//堆分配
//	struct chaff * pch = new chaff[N];
//	int i = 0;
//
//	std::cout << "Buffer address\n" << "Heap:\t" << pch;
//	std::cout << "\nStatic:\t" << (void *)buffer << std::endl;
//	for(i = 0;i < N;i++)
//	{
//		std::cout << "Enter new\n";
//		set_value(pcn[i]);
//		std::cout << "Enter heap\n";
//		set_value(pch[i]);
//	}
//	for(i = 0;i < N;i++)
//	{
//		std::cout << "new\n";
//		show_value(pcn[i]);
//		std::cout << "heap\n";
//		show_value(pch[i]);
//	}
//	return 0;
//}
//void set_value(struct chaff & c)
//{
//	char tmp[LEN];
//
//	std::cout << "Enter dross:";
//	std::cin >> tmp;
//	strcpy(c.dross,tmp);
//	std::cout << "Enter slag:";
//	std::cin >> c.slag;
//}
//void show_value(const struct chaff & c)
//{
//	std::cout << "Dross:" << c.dross;
//	std::cout << ",slag:" << c.slag;
//	std::cout << ",address:" << &c << std::endl;
//}