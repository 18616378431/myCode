//17 Make Review

//1.iostream��C++I/O�еĽ�ɫ
//����������������仺����,���ļ����������ڹ��������������ࡢ�����Ͳ��ݷ�
//��Щ����������ڴ���I/O�����ͻ�����
//���ļ���������һЩ��׼����(cin��cout��cerr��clog����Ӧ�Ŀ��ַ�����)
//���ڴ�����ÿ����������������������

//2.��������Ϊ����Ҫ����ת��
//������������һϵ���ַ�,����121�����������ַ�,ÿ���ַ�����һ��һ�ֽڵĶ��������ʾ
//Ҫ�����ֵ�洢Ϊint��,����뽫��3���ַ�ת��Ϊ121�Ķ����Ʊ�ʾ

//3.��׼������׼���������
//Ĭ�������,��׼����ͱ�׼���󶼽���Ϣ���͸���׼����豸(��ʾ��)
//������ض����ļ�ʱ,��׼���������ӵ���Ļ,��׼������ļ�����

//4.Ϊʲôcout������ʾ��ͬ��C++����
//��Ϊostream����Ϊÿ���������Ͷ����������ص�<<������,ʹ������C++��������ƥ��
//operator<<(char &)

//5.��������Ķ������һ����ʹ�ÿ�����ʽ����
//���ص�operator<< ()���������ص�ǰ���ö���,ostream &,���ض�����Ե�����һ����

//6.�Ի���ǰ׺��ʮ���ơ��˽��ơ�ʮ��������ʾ����

//7.��ָ����ʽ��ʾ��������

//8.ct1 = 5 �����հ� ct2 = 9 ��ȡ���ϴ������������뻺�����Ļ��з�

//9.cin.ignore(80,'\n')��while(cin.get() != '\n')continue;������
//�����г���80���ַ�ignore��������������,�����������������ǰ80���ַ�

//#include <iostream>
//#include <iomanip>

//using namespace std;

//int main()
//{
	//6
	/*int x;
	cout << "Enter an number:";
	cin >> x;
	cout << setw(15) << "base ten"
		<< setw(15) << "base sixteen"
		<< setw(15) << "base eight" << endl;
	cout.setf(ios_base::showbase);
	cout << setw(15) << x << hex << setw(15) << x << setw(15) << oct << x << endl;*/

	//7
	//char name[20];
	//float wage;
	//float h;
	//cout << "Enter your name:";
	//cin.getline(name,20);
	//cout << "Enter your hourly wages:";
	//cin >> wage;
	//cout << "Enter number of hours worked:";
	//cin >> h;
	////cout.setf(ios_base::fixed,ios_base::floatfield);
	////cout.setf(ios_base::showpoint);
	////cout.setf(ios_base::right,ios_base::adjustfield);
	//cout << fixed << showpoint << right;

	//cout << "First format:\n";
	//cout << setw(20) << name << ":$" 
	//	<< setw(10) << setprecision(2) << wage << ":" 
	//	<< setw(10) << setprecision(1)  << h << endl;

	////cout.setf(ios_base::left,ios_base::adjustfield);
	//cout << left;
	//cout << "Second format:\n";
	//cout << setw(20) << name << ":$" << setw(10) << setprecision(2) << wage << ":" << setprecision(1) << setw(10) << h << endl;
	
	//8
	/*char ch;
	int ct1 = 0;
	cin >> ch;
	while(ch != 'q')
	{
		ct1++;
		cin >> ch;
	}

	int ct2 = 0;
	cin.get(ch);
	while(ch != 'q')
	{
		ct2++;
		cin.get(ch);
	}

	cout << "ct1 = " << ct1 << ";ct2 = " << ct2 << "\n";*/

//	return 0;
//}

