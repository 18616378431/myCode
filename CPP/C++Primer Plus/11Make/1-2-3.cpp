////11.15 �����·����,������㳤�ȳ���50Ӣ��
//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<fstream>
//#include"vector.h"
//
//int main()
//{
//	using namespace std;
//	using VECTOR::Vector;
//	
//	srand(time(0));//���������������
//	double direction;//����
//	Vector step;
//	Vector result;
//	unsigned long steps = 0;//�ܲ���
//	double target;//Ŀ�����
//	double dstep;//ÿ������
//	ofstream out;//�����������ļ�
//	//�̶����롢�������Դ��������������С�������ܲ���
//	unsigned long n,max = 0,min = 0,total = 0;
//	
//
//	out.open("1.txt",ios_base::out);
//
//	cout << "Enter target distance(q to quit):";
//	while(cin >> target)
//	{
//		cout << "Enter step length:";
//		if(!(cin >> dstep))
//			break;
//		out << "Target Distance:" << target << ",Step Size:" << dstep << "\n";
//		cout << "Enter times:";
//		if(!(cin >> n))
//			break;
//		for(unsigned long i = 0;i < n;i++)
//		{
//			result.set(0,0);
//			steps = 0;
//			while(result.magval() < target)
//			{
//				out << steps << ":(x,y) = (" << result.xval() << "," << result.yval() << ")\n";
//				direction = rand() % 360;
//				step.set(dstep,direction,'p');
//				result = result + step;
//				steps++;
//			}
//			if(i == 0)
//			{
//				max = min = steps;
//			}else if(steps >= max)
//				max = steps;
//			else if(steps <= min)
//				min = steps;
//			
//			total += steps;
//
//			cout << "After " << steps << " steps,the subject "
//				<< "has the following location:\n";
//			cout << result << endl;
//			result.polar_mode();
//			cout << "or\n" << result << endl;
//			cout << "Average outward distance per step = "
//				<< result.magval()/steps << endl;
//
//			//result to file
//			result.rect_mode();
//			out << "After " << steps << " steps,the subject "
//				<< "has the following location:\n";
//			out << result << endl;
//			result.polar_mode();
//			out << "or\n" << result << endl;
//			out << "Average outward distance per step = "
//				<< result.magval()/steps << endl;
//			cout << "====================================\n";
//			
//		}
//		cout << "Max:" << max << ".Min:" << min << ",Average:" << total / n << endl;
//
//		/*steps = 0;
//		result.set(0.0,0.0);*/
//		cout << "Enter target distance(q to quit):";
//	}
//	cout << "Bye\n";
//	return 0;
//}