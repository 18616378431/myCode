////һ������ַ����ĺ������ڶ���������Ϊ0���ӡ�������ô������ַ���
//#include<iostream>
//
//using namespace std;
//
//void print_str(const char * str,int flag = 0);
//
//int main()
//{
//	char str[] = "Hello World!";
//
//	cout << "#1" << endl;
//	print_str(str);
//	cout << "#2" << endl;
//	print_str(str,1991);
//	cout << "#3" << endl;
//	print_str(str,1991);
//	cout << "#4" << endl;
//	print_str(str,1991);
//	return 0;
//}
//
//void print_str(const char * str,int flag)
//{
//	static int count = 0;
//	count++;
//	if(flag == 0)
//	{
//		cout << str << endl;
//	}
//	else
//	{
//		for(int i = 0;i < count;i++)
//		{
//			cout << str << endl;
//		}
//	}
//}