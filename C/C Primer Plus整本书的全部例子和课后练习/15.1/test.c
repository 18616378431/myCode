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
//		//��number��ָ��λ����ת��
//		number = invert_end(number,4);
//		printf("Inverting the last 4 bits gives\n");
//		show_bstr(itobs(number,bin_str));
//		putchar('\n');
//	}
//	puts("Bye!");
//	return 0;
//}
////λ����ʵ������ת��������
//char * itobs(int n,char * ps)
//{
//	int i;
//	static int size = 8 * sizeof(int);
//
//	for(i = size - 1;i >= 0;i--,n >>= 1)//��������һλ
//	{
//		ps[i] = (01 & n) + '0';	//�����������в�������,�˽���01(000 001)��������λ�����
//								//���룬���Ϊ�������һλ
//	}
//	ps[size] = '\0';//�������һλ��Ϊ\0
//	return ps;
//}
////�ݹ�ʵ�ֶ�����
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
////��ת����ָ��λ��
//int invert_end(int num,int bits)
//{
//	int mask = 0;//����������λ��Ϊ0
//	int bitval = 1;//λ���������ڴ�������
//
//	while(bits-- >0)
//	{
//		mask |= bitval;	//0000 0000 |=
//						//0000 0001 = 0000 0001
//		bitval <<= 1;//λ��������һλ,000 0010,��mask(0000 0001)ѭ����λ������,0000 0011
//		//��������mask��ֵΪָ��λ��������0000 0000 1111(��߰���ָ��������1)
//	}
//	return num ^ mask;//������㣬��ͬΪ�٣���ͬΪ��,ͬΪ0����Ϊ0;ת����������λΪ1��λ����������λΪ0��λ��
//}