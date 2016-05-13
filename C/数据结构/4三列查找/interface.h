//接口文件
//基于开放定址法解决冲突，构造散列表实现查找
//汽车租赁系统查找功能实现

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define BOOL int
#define true 1
#define false 0

#define TRADE_NAME_SIZE 20//汽车品牌名称长度
#define KEY_SIZE 7//接受搜索的关键字长度
#define HASH_MAX_SIZE 15//Hash列表大小
#define MOD 12//除留余数系数

//元素类型定义
typedef struct item{
	int carId;//车牌号
	char tradeMark[TRADE_NAME_SIZE];//汽车品牌
	BOOL flag;//汽车是否已租赁,默认为false
}Item;
//查找关键字类型定义
typedef char key[KEY_SIZE];
//定义顺序表的散列查找表
typedef Item HashList[HASH_MAX_SIZE];


/*
操作:初始化HASHLIST，将Hash表置空
操作前:hl为指向HashList结构数组的指针
操作后:HashList表全部为空
*/
void InitHashList(HashList hl);

/*
操作:清空线性表
操作前:hl为指向已初始化的HashList结构数组的指针
操作后:讲Hash线性表清空
*/
void ClearHashList(HashList hl);

/*
操作:向Hash表中插入元素
操作前:hl指向已初始化的HashList结构数组，item为待查找元素
操作后:将元素插入Hash表，成功返回true，失败或表满返回false
*/
BOOL InsertItemIntoHashList(HashList hl,Item item);

/*
操作:在Hash表中查找元素
操作前:hl指向已初始化的Hash结构数组，item为待查找元素
操作后:查找成功，返回元素位置，否则返回-1
*/
int LocateItemFromHashList(HashList hl,Item item);

/*
操作:在Hash表中删除指定元素
操作前:hl指向已初始化的HashList表，item为待删除元素
操作后:删除成功，返回true，否则返回false
*/
BOOL DeleteItemFromHashList(HashList hl,Item item);

/*
操作:除留余数获取Hash值
操作前:传递车牌号carId
操作后:返回根据相应MOD得到的值
*/
int HashDiv(int carId);
#endif