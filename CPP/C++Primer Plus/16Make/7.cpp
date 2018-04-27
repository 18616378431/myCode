////7. random_shuffle => srand(time(NULL))
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//typedef vector<int> vint;
//
//vint Lotto(int n,int choose);
//
//int main()
//{
//	vint winners;
//	winners = Lotto(51,6);
//
//	ostream_iterator<int,char> out(cout," ");
//	copy(winners.begin(),winners.end(),out);
//	cout << endl;
//
//	return 0;
//}
//
//vint Lotto(int n,int choose)
//{
//	srand(time(NULL));
//	vint temp,result;
//	int i;
//	for(i = 0;i < n;i++)
//	{
//		temp.push_back(i + 1);
//	}
//	for(i = 0;i < choose;i++)
//	{
//		random_shuffle(temp.begin(),temp.end());
//		result.push_back(temp.front());
//	}
//	sort(result.begin(),result.end());
//
//	return result;
//}