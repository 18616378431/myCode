//#include<stdio.h>
//
//int main()
//{
//	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
//
//	//��ӡ������Ԫ�ص�ַ,zippoΪ������Ԫ�ص�ַ*zippo = zippo[0],zippo[0] = &zippo[0][0],**zippo = zippo[0][0]
//	printf("zippo = %p,zippo + 1 = %p\n",zippo,zippo + 1);
//	//���zippo��Ԫ�ص�ַzippo[0],zippo[0][0]�ĵ�ַ
//	//�͵ڶ���Ԫ�ص�ַzippo[1],zippo[1][0]
//	printf("zippo[0] = %p,zippo[0] + 1 = %p\n",zippo[0],zippo[0] + 1);
//	//zippo[0]Ϊ������Ԫ�ص�ַ
//	//zippo[0] + 1��Ϊ�ڲ��������Ԫ�ص�ַzippo[0][0]
//	printf("*zippo = %p,*zippo + 1 = %p\n",*zippo,*zippo + 1);
//	//*zippoΪ�ڲ�������Ԫ�ص�ַ
//	//*zippo + 1 Ϊ�ڲ�����ĵڶ���Ԫ�ص�ַ
//	printf("zippo[0][0] = %d\n",zippo[0][0]);
//	//�ڲ�������Ԫ��
//	printf("  *zippo[0] = %d\n",*zippo[0]);
//	//�ڲ�������Ԫ��
//	printf("    **zippo = %d\n",**zippo);
//	//�ڲ�������Ԫ��
//	printf("      zippo[2][1] = %d\n",zippo[2][1]);
//	//��ά���飬�����У��ڶ��е�Ԫ�ص���ֵ
//	printf("*(*(zippo + 2) + 1) = %d\n",*(*(zippo + 2) + 1));
//	//ͬ��
//	return 0;
//}