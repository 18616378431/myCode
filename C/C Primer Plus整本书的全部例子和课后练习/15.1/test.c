//#include<stdio.h>
//
//char * itobs(int n,char * ps);
//void show_bstr(const char * str);
//void to_binary(int n);
//int invert_end(int num,int bits);
//
//int main()
//{
//	char bin_str[8 * sizeof(int) + 1];
//	int number;
//
//	puts("Enter the integers and see them in binary.");
//	puts("Non-numeric input terminates program.");
//	while(scanf("%d",&number) == 1)
//	{
//		//printf("~0 is %d.\n",~0);
//		itobs(number,bin_str);
//		printf("%d is \n",number);
//		show_bstr(bin_str);
//		putchar('\n');
//		//to_binary(number);
//		//将number做指定位数的转置
//		number = invert_end(number,4);
//		printf("Inverting the last 4 bits gives\n");
//		show_bstr(itobs(number,bin_str));
//		putchar('\n');
//	}
//	puts("Bye!");
//	return 0;
//}
////位操作实现整数转换二进制
//char * itobs(int n,char * ps)
//{
//	int i;
//	static int size = 8 * sizeof(int);
//
//	for(i = size - 1;i >= 0;i--,n >>= 1)//数字右移一位
//	{
//		ps[i] = (01 & n) + '0';	//倒序向数组中插入数据,八进制01(000 001)和数字做位与操作
//								//掩码，结果为数字最后一位
//	}
//	ps[size] = '\0';//数组最后一位设为\0
//	return ps;
//}
////递归实现二进制
//void to_binary(int n)
//{
//	int r;
//
//	r = n % 2;
//	if(n >= 2)
//		to_binary(n / 2);
//	putchar('0' + r);
//}
//void show_bstr(const char * str)
//{
//	int i = 0;
//
//	while(str[i] != '\0')
//	{
//		putchar(str[i]);
//		if(++i % 4 == 0 && str[i] != '\0')
//		{
//			putchar(' ');
//		}
//	}
//}
////反转数字指定位数
//int invert_end(int num,int bits)
//{
//	int mask = 0;//将掩码所有位设为0
//	int bitval = 1;//位变量，用于创建掩码
//
//	while(bits-- >0)
//	{
//		mask |= bitval;	//0000 0000 |=
//						//0000 0001 = 0000 0001
//		bitval <<= 1;//位变量左移一位,000 0010,与mask(0000 0001)循环做位或运算,0000 0011
//		//最终掩码mask的值为指定位数的掩码0000 0000 1111(后边包含指定个数个1)
//	}
//	return num ^ mask;//异或运算，相同为假，不同为真,同为0，则为0;转换所有掩码位为1的位，保留掩码位为0的位置
//}