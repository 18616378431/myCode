////6. Ӣʯ-��ת������
////����ȫ��6��������
////��������pounds��Ա���бȽ�,����boolֵ
////����6�����������,���������г�ʼ��ǰ��������
////ʹ��ѭ����ȡʣ����������������ֵ
////������СԪ�ء����Ԫ�ء����ڵ���11 stone��Ԫ������
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
