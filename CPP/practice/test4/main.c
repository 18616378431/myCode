//位操作
#include<stdio.h>

// & | ^ ~ << >>
//按位与、按位或、按位异或、按位取反、按位左移、按位右移
//按位取反为单目运算符，其他为双目运算符

int main()
{
	//int 4字节byte，每字节8位bit

	//#####################位与运算&

	//将变量二进制位逻辑运算,必须以补码方式出现,参与运算的必须是整型或字符型
	//&均为1结果为1，否则为0
	//应用：	迅速清零,任何数与0按位与结果为0
	//			保留数据的指定位,将第二个变量低8位设为1
	//			判断变量奇偶运算,a&1;//结果为1a为奇数，为0则为偶数
	//int a = 4;//00000000 00000000 00000000 00000100
	//int b = 7;//00000000 00000000 00000000 00000111
	//		  //00000000 00000000 00000000 00000100
	//int c = a&b;
	//
	//printf("%d\n",c);


	//###################位或运算|
	//逐位逻辑或运算
	//有一个为1结果为1
	//用途：设置数的指定位a = a|0xFF;//16进制，255
	//int a = 9;//00000000 00000000 00000000 00001001
	//int b = 5;//00000000 00000000 00000000 00000101
	//			
	//int c = a|b;// 00000000 00000000 00000000 00001101

	//printf("%d\n",c);

	//a = a|0xFF;//16进制，255
	//printf("%d\n",a);

	//#####################异或运算^
	//相同为0，不同为1,逐位逻辑异或运算，位互斥，结果为真
	//应用：定位翻转a = a^0xFF;
	//int a = 9;//00001001
	//int b = 5;//00000101

	//int c = a^b;//00001100

	////a = a^0xFF;
	//
	////交换值
	//a = a^b;
	//b = b^a;
	//a = a^b;

	//printf("a=%d,b=%d\n",a,b);

	//printf("%d\n",c);

	//##################按位取反单目运算符~
	//对变量的二进制按位取反
	//~(00001001) = 11110110

	//####################左移运算符<<
	//高位舍弃，低位补零,左移n位，将变量值乘以2的n次方
	//最左端为符号位
	//应用：二倍乘
	//int a = 3;//00000000 00000000 00000000 00000011
	//a = a<<4; //00000000 00000000 00000000 00110000  48
	//

	//int i = 1;//00000001
	//i = i<<2; //00000100 1乘以(2的2次方)，4


	//########################右移运算符>>
	//除以2的n次方
	//数据有符号，根据符号位左边补0或1，符号位为0补0，符号位为1，根据计算机不同补位

	return 0;
}