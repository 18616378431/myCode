//#include<stdio.h>
//
////�ṹ��
//struct weapon{
//	char name[20];//����
//	int attack;//������
//	int price;//�۸�
//}WEA;
//
//int main()
//{
//	//�ṹ���������������ʱ���ж��壬Ҳ�����ں���������
//	//�ṹ�������ʼ��
//	struct weapon weapon_1 = {"weapon_name1",100,100};
//	
//	//�ṹ������,�Լ��ṹ�������ʼ��
//	struct weapon weapon_2[2] =  {{"arr_weapon_name1",100,100},{"arr_weapon_name2",200,200}};
//
//	//�ṹ��ָ��
//	struct weapon *p = &weapon_1;
//	
//	//�ṹ������ָ��
//	struct weapon *ptr = weapon_2;//ptr��ֵΪ�ṹ��������Ԫ�ص�ַ
//
//	int i;
//
//	//�Խṹ����ʽ���ṹ��ָ����ʽ���ʽṹ���Ա����
//	printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//		weapon_1.name,weapon_1.attack,weapon_1.price);
//	printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//		p->name,p->attack,p->price);
//	
//	//����ṹ�������нṹ�����
//	for(i = 0;i < 2;i++)
//	{
//		printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//			weapon_2[i].name,weapon_2[i].attack,weapon_2[i].price);
//	}
//	for(i = 0;i < 2;i++)
//	{
//		printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//			ptr->name,ptr->attack,ptr->price);
//		ptr++;
//	}
//	
//	
//
//	
//	
//	return 0;
//}