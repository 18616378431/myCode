////��string�����ַ���ת��Ϊ��д
//#include<iostream>
//#include<string>//string����,std���ƿռ��еĶ���
//
//void change(std::string & s);
//
//int main()
//{
//	std::string str;
//	std::cout << "Enter a string (q to quit):";
//
//	while(getline(std::cin,str))
//	{
//		if(str.size() == 1 && str[0] == 'q')
//		{
//			break;
//		}
//		change(str);
//		std::cout << str << std::endl;
//		std::cout << "Next string (q to quit):";
//	}
//	return 0;
//}
//void change(std::string & s)
//{
//	for(int i = 0;i < s.size();i++)
//	{
//		s[i] = toupper(s[i]);
//	}
//}