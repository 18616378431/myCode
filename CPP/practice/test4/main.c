//λ����
#include<stdio.h>

// & | ^ ~ << >>
//��λ�롢��λ�򡢰�λ��򡢰�λȡ������λ���ơ���λ����
//��λȡ��Ϊ��Ŀ�����������Ϊ˫Ŀ�����

int main()
{
	//int 4�ֽ�byte��ÿ�ֽ�8λbit

	//#####################λ������&

	//������������λ�߼�����,�����Բ��뷽ʽ����,��������ı��������ͻ��ַ���
	//&��Ϊ1���Ϊ1������Ϊ0
	//Ӧ�ã�	Ѹ������,�κ�����0��λ����Ϊ0
	//			�������ݵ�ָ��λ,���ڶ���������8λ��Ϊ1
	//			�жϱ�����ż����,a&1;//���Ϊ1aΪ������Ϊ0��Ϊż��
	//int a = 4;//00000000 00000000 00000000 00000100
	//int b = 7;//00000000 00000000 00000000 00000111
	//		  //00000000 00000000 00000000 00000100
	//int c = a&b;
	//
	//printf("%d\n",c);


	//###################λ������|
	//��λ�߼�������
	//��һ��Ϊ1���Ϊ1
	//��;����������ָ��λa = a|0xFF;//16���ƣ�255
	//int a = 9;//00000000 00000000 00000000 00001001
	//int b = 5;//00000000 00000000 00000000 00000101
	//			
	//int c = a|b;// 00000000 00000000 00000000 00001101

	//printf("%d\n",c);

	//a = a|0xFF;//16���ƣ�255
	//printf("%d\n",a);

	//#####################�������^
	//��ͬΪ0����ͬΪ1,��λ�߼�������㣬λ���⣬���Ϊ��
	//Ӧ�ã���λ��תa = a^0xFF;
	//int a = 9;//00001001
	//int b = 5;//00000101

	//int c = a^b;//00001100

	////a = a^0xFF;
	//
	////����ֵ
	//a = a^b;
	//b = b^a;
	//a = a^b;

	//printf("a=%d,b=%d\n",a,b);

	//printf("%d\n",c);

	//##################��λȡ����Ŀ�����~
	//�Ա����Ķ����ư�λȡ��
	//~(00001001) = 11110110

	//####################���������<<
	//��λ��������λ����,����nλ��������ֵ����2��n�η�
	//�����Ϊ����λ
	//Ӧ�ã�������
	//int a = 3;//00000000 00000000 00000000 00000011
	//a = a<<4; //00000000 00000000 00000000 00110000  48
	//

	//int i = 1;//00000001
	//i = i<<2; //00000100 1����(2��2�η�)��4


	//########################���������>>
	//����2��n�η�
	//�����з��ţ����ݷ���λ��߲�0��1������λΪ0��0������λΪ1�����ݼ������ͬ��λ

	return 0;
}