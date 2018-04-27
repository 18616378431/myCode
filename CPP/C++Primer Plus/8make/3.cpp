////将string对象字符串转换为大写
//#include<iostream>
//#include<string>//string对象,std名称空间中的对象
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