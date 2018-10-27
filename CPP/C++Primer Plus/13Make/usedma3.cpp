////inheritance,friends,dma
//#include <iostream>
//#include "dma.h"
//
//const int MAX = 3;
//const int LEN = 40;
//
//int main(int argc,char * argv[])
//{
//	using namespace std;
//
//	/*BaseDMA shirt("Portabelly",8,"WWW1",1);
//	LacksDMA balloon("red","WWW2",2);
//	HasDMA map("Mercator","WWW3",3);
//	
//	shirt.View();
//	balloon.View();
//	map.View();*/
//
//	ABC * p_abc[MAX];
//	int i;
//
//	for(i = 0;i < MAX;i++)
//	{
//		//fullname
//		char nametemp[LEN];
//		//level
//		int ltemp;
//		//object kind
//		char kind;//1,2,3
//		cout << "===============\nfullname:";
//		cin.getline(nametemp,LEN);
//		cout << "level:";
//		cin >> ltemp;
//		cout << "kind:";
//		while(cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
//		{
//			cin.clear();
//			cout << "Enter either 1,2 or 3:";
//		}
//		if(kind == '1')
//		{
//			while(cin.get() != '\n')
//			{
//				continue;
//			}
//			char labeltemp[LEN];
//			int r;
//			cout << "BaseDMA\n";
//			cout << "Label:";
//			cin.getline(labeltemp,LEN);
//			cout << "Rating:";
//			cin >> r;
//			p_abc[i] = new BaseDMA(labeltemp,r,nametemp,ltemp);
//		}
//		else if(kind == '2')
//		{
//			while(cin.get() != '\n')
//			{
//				continue;
//			}
//			cout << "LacksDMA\n";
//			char colortemp[LEN];
//			cout << "Color:";
//			cin.getline(colortemp,LEN);
//			p_abc[i] = new LacksDMA(colortemp,nametemp,ltemp);
//		}
//		else if(kind == '3')
//		{
//			while(cin.get() != '\n')
//			{
//				continue;
//			}
//			cout << "HasDMA\n";
//			char styletemp[LEN];
//			cout << "Style:";
//			cin.getline(styletemp,LEN);
//			p_abc[i] = new HasDMA(styletemp,nametemp,ltemp);
//		}
//		while(cin.get() != '\n')
//		{
//			continue;
//		}
//	}
//	cout << endl;
//	for(i = 0;i < MAX;i++)
//	{
//		p_abc[i]->View();
//		cout << endl;
//	}
//	//destory
//	for(i = 0;i < MAX;i++)
//	{
//		delete p_abc[i];
//	}
//	cout << "Done\n";
//
//	return 0;
//}