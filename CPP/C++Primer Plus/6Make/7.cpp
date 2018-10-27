//#include<iostream>
//#include<string>
//#include<cctype>
//
//using namespace std;
//
//bool check(char ch);
//
//int main()
//{
//	string str;
//	int vowels = 0,consonants = 0,others = 0;
//	
//	cout << "Enter words (q to quit)\n";
//	while(cin >> str && str != "q")
//	{
//		if(isalpha(str[0]))
//		{
//			if(check(tolower(str[0])))
//			{
//				vowels++;
//			}
//			else
//			{
//				consonants++;
//			}
//		}
//		else
//		{
//			others++;	
//		}
//	}
//	cout << vowels << " words beginning with vowels\n"
//		<< consonants << " words beginning with consonants\n"
//		<< others << " others" << endl;
//	return 0;
//}
//bool check(char ch)
//{
//	switch(ch)
//	{
//	case 'a':
//	case 'e':
//	case 'i':
//	case 'o':
//	case 'u':
//		return true;
//		break;
//	default:
//		return false;
//		break;
//	}
//}