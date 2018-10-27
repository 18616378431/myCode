////6. 英石-磅转换程序
////重载全部6个操作符
////操作符对pounds成员进行比较,返回bool值
////包含6个对象的数组,数组声明中初始化前三个对象
////使用循环读取剩余三个对象设置其值
////报告最小元素、最大元素、大于等于11 stone的元素数量
//#include<iostream>
//#include"stonewt6.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	Stonewt pavarotti = 260;
//	Stonewt wolfe(285.7);
//	Stonewt taft(21,8);
//
//	cout << "The pavarotti weighed ";
//	pavarotti.show_stn();
//	pavarotti.pounds_mode();
//	cout << pavarotti << "\n";
//
//	cout << "The wolfe weighed ";
//	wolfe.show_stn();
//	wolfe.pounds_mode();
//	cout << wolfe << "\n";
//
//	cout << "The taft weighed ";
//	taft.show_lbs();
//	taft.pounds_mode();
//	cout << taft << "\n";
//
//	cout << "+:" << pavarotti + wolfe << endl;
//	cout << "-:" << pavarotti - wolfe << endl;
//	cout << "*:" << 2 * pavarotti << endl;
//	cout << "/:" << 2 / pavarotti << endl;
//	cout << "%:" << 15 % pavarotti << endl;
//
//	Stonewt wolf[6] = {
//		Stonewt(200),
//		Stonewt(100),
//		Stonewt(300)
//	};
//	double pounds;
//	int eleven = 0;
//	Stonewt min,max;
//
//	for(int i = 0;i < 6;i++)
//	{
//		if(wolf[i].poundsval() == 0)
//		{
//			cout << "Enter pounds:";
//			cin >> pounds;
//			wolf[i] = Stonewt(pounds);
//		}
//		if(wolf[i].stoneval() > 11)
//		{
//			eleven++;
//		}
//		if(i == 0)
//		{
//			min = max = wolf[i];
//		}
//		else if((min < wolf[i]) == false)
//		{
//			min = wolf[i];
//		}
//		else if(max < wolf[i])
//		{
//			max = wolf[i];
//		}
//		
//	}
//	cout << "Max:" << max << endl;
//	cout << "Min:" << min << endl;
//	cout << "litter than 11 stone numbers:" << eleven << endl;
//
//	return 0;
//}
