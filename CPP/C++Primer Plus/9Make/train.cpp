//#include<iostream>
//
//void three();
//void four();
//static int average(int a,int b);
//void call();
//
////6
//void six();
//void other();
//void another();
//
//int x = 10;
//int y;
//
////7.
//void seven();
//namespace n1
//{
//	int m = 1;
//}
//namespace n2
//{
//	int m = 2;
//}
//void other1();
//
//
//
//int main()
//{
//	//3.
//	three();
//	//4.
//	four();
//	//5.
//	std::cout << "File1 average = " << average(3,6) << std::endl;
//	call();
//	//6.
//	six();
//	//7.
//	seven();
//	return 0;
//}
////1.a.�Զ�����
////b.��̬ȫ�ֱ���������Ϊ�ⲿ,����һ���ļ���ʹ��extern����
////c.�ڲ����ӵľ�̬����,�ļ�������static,����δ���������ƿռ�������������
////d.�������Եľֲ���̬����,�����������static
//
////2.(1)using����ֻ���������������,using����ָ��������ƿռ���ȫ��������
////	(2)using����ʹ�����ƿռ��еĵ������ƿ���,����������using��������������ͬ,
////		using����ָ��ʹ���ƿռ��е��������ƿ���
////	(3)ʹ��using����ָ��,�����ڰ���using���������ƿռ䱾����С��������������������Щ����
//
////3.��ʹ��using������using����ָ��
//void three()
//{
//	double x;
//	std::cout << "Enter value:";
//	while(!(std::cin >> x))
//	{
//		std::cout << "Bad input,Please enter a number:";
//		std::cin.clear();
//		while(std::cin.get() != '\n')
//			continue;
//	}
//	std::cout << "Value = " <<  x << std::endl;
//}
////4.��ʹ��using����ָ��,ʹ��using����
//void four()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//
//	double x;
//
//	cout << "Enter value:";
//	while(!(cin >> x))
//	{
//		cout << "Bad input,Please enter a number:";
//		cin.clear();
//		while(cin.get() != '\n')
//			continue;
//	}
//	cout << "Value = " << x << endl;
//}
////5.һ���ļ����÷���int,��һ���ļ����÷���double
////����Ĭ��������Ϊ�������ⲿextern,ʹ�þ�̬�����ڲ�������,�ļ�������
////��ÿ���ļ�����δ���������ƿռ䶨��һ�����ز�ͬ���͵ĺ���
//static int average(int a,int b)
//{
//	return (a + b)/2;
//}
////6.��̬ȫ���ⲿ���ӱ���������,�ֲ���������ȫ�ֱ���,δ�������ƿռ�������Ϊ�ļ�
//void six()
//{
//	using namespace std;
//
//	cout << x << endl;
//	{
//		int x = 4;//�����������,����ȫ�ֱ���
//		cout << x << endl;
//		cout << y << endl;//δ��ʼ����ȫ�ֱ���,Ĭ�ϳ�ʼ��Ϊ0
//	}
//	other();
//	another();
//}
//void other()
//{
//	using namespace std;
//
//	int y = 1;//�ֲ���������ͬ��ȫ�ֱ���
//	cout << "Other : " << x << "," << y << endl;
//}
////7.����������������������ƿռ��е�����
//void seven()
//{
//	using namespace std;
//	using namespace n1;
//
//	cout << m << endl;
//	{
//		int m = 4;//�ֲ�����ȫ��
//		cout << m << "," << n1::m << "," << n2::m << endl;
//	}
//	using n2::m;//n2�����ռ��е����Ƹ�����ǰ�����������ƿռ��е�����
//	cout << m << endl;
//	other1();
//}
//void other1()
//{
//	using namespace std;
//	using namespace n2;
//
//	cout << m << endl;
//	{
//		int m = 4;
//		cout << m << "," << n1::m << "," << n2::m << endl;
//	}
//	using n2::m;
//	cout << m << endl;
//}