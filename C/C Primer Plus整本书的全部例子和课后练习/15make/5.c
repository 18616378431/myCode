////��һ����ֵ������λ������תָ��������λ��������ֵ�����ƶ�ָ������λ��Ȼ����˶�ʧ��λ�������Ҷ�
//#include<stdio.h>
//
//char * itobs(unsigned int x,char * str);
//void move(unsigned int x,unsigned int bit);
//
//char bin_str[8 * sizeof(unsigned int) + 1];
//
//int main()
//{
//	unsigned int x,bit;
//
//	puts("Enter a number and the number of bit:");
//	scanf("%u %u",&x,&bit);
//	itobs(x,bin_str);
//	move(x,bit);
//	return 0;
//}
//char * itobs(unsigned int x,char * str)
//{
//	int i,copy = x;
//	static int size = 8 * sizeof(unsigned int);
//
//	for(i = size - 1;i >= 0;i--,x >>= 1)
//	{
//		str[i] = (01 & x) + '0';
//	}
//	str[size] = '\0';
//	x <<= 32;
//	printf("%d to binary is %s.\n",copy,str);
//	return str;
//}
//void move(unsigned int x,unsigned int bit)
//{
//	printf("Move left %d bits.\n",bit);
//	itobs((x << bit) | (x >> (8 * sizeof(unsigned int) - bit)),bin_str);
//}