///************************************************************************/
///* ��ֵ���ݲ���������ַ���ݲ���                                                                     */
///************************************************************************/
//#include<iostream>
//
//using namespace std;
//
//struct box{
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//
//void showInValue(struct box bv);
//void showInAddress(struct box *bv);
//
//int main()
//{
//	struct box b = {"china",50.0,60.0,70.0,80.0};
//
//	showInValue(b);
//	showInAddress(&b);
//	return 0;
//}
///*��ֵ����box�ṹ*/
//void showInValue(struct box bv)
//{
//	cout << "maker is " << bv.maker << endl;
//	cout << "height is " << bv.height << endl;
//	cout << "width is " << bv.width << endl;
//	cout << "length is " << bv.length << endl;
//	cout << "volume is " << bv.volume << endl;
//}
///*����ַ����box�ṹ*/
//void showInAddress(struct box *bv)
//{
//	cout << "maker is " << bv->maker << endl;
//	cout << "height is " << bv->height << endl;
//	cout << "width is " << bv->width << endl;
//	cout << "length is " << bv->length << endl;
//	cout << "volume is " << bv->volume << endl;
//}