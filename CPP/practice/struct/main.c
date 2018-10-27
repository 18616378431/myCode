//#include<stdio.h>
//
////结构体
//struct weapon{
//	char name[20];//名称
//	int attack;//攻击力
//	int price;//价格
//}WEA;
//
//int main()
//{
//	//结构体变量可以在声明时进行定义，也可以在函数中声明
//	//结构体变量初始化
//	struct weapon weapon_1 = {"weapon_name1",100,100};
//	
//	//结构体数组,以及结构体数组初始化
//	struct weapon weapon_2[2] =  {{"arr_weapon_name1",100,100},{"arr_weapon_name2",200,200}};
//
//	//结构体指针
//	struct weapon *p = &weapon_1;
//	
//	//结构体数组指针
//	struct weapon *ptr = weapon_2;//ptr的值为结构体数组首元素地址
//
//	int i;
//
//	//以结构体形式及结构体指针形式访问结构体成员变量
//	printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//		weapon_1.name,weapon_1.attack,weapon_1.price);
//	printf("weapon_name:%s,weapon_attack:%d,weapon_price:%d\n",
//		p->name,p->attack,p->price);
//	
//	//输出结构体数组中结构体变量
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