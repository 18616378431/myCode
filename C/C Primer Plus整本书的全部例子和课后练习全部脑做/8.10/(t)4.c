//#include<stdio.h>
//#include<ctype.h>		//�ṩispunct()����ԭ��
//
//int main(void)
//{
//	char ch;
//	int count = 0;		//���ʸ���
//	int len = 0;		//ÿ�����ʵ���ĸ����
//	int totlen = 0;		//���е��ʵ���ĸ����
//	float ave;
//
//	while((ch = getchar()) != EOF)
//	{
//		if(ispunct(ch) || isspace(ch))
//		{
//			count++;	
//			totlen += len;
//			len = 0;
//			if(ch != '\n')
//			{
//				continue;	
//			}
//			else
//			{
//				break;
//			}	
//		}
//		len++;
//	}
//	ave = (float)totlen/count;
//	printf("��ĸ����:%d,���ʸ���:%d,ÿ������ƽ����ĸ��:%.2f\n",totlen,count,ave);
//	return 0;
//}