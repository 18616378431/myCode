////二叉搜索树接口文件
//#ifndef TREE_H_
//#define TREE_H_
//
//#define BOOL int
//#define true 1
//#define false 0
//
//#define SIZE 30
//#define MAXITEM 10
//
//typedef struct item{
//	char word[SIZE];
//	int ct;
//}Item;
//
//typedef struct node{
//	Item item;
//	struct node * left;
//	struct node * right;
//}Node;
//
//typedef struct tree{
//	Node * root;
//	int size;
//}Tree;
//
///*
//操作:将树初始化为空
//操作前:ptree指向一个树
//操作后:树被初始化为空树
//*/
//void InitalizeTree(Tree * ptree);
//
///*
//操作:确定树是否为空
//操作前:ptree指向已初始化的树
//操作后:树为空，返回true，否则返回false
//*/
//BOOL TreeIsEmpty(const Tree * ptree);
//
///*
//操作:确定树是否已满
//操作前:ptree指向已初始化的树
//操作后:树满，返回true，否则返回false
//*/
//BOOL TreeIsFull(const Tree * ptree);
//
///*
//操作:确定树中项目的个数
//操作前:ptree指向已初始化的树
//操作后:返回树中项目的个数
//*/
//int TreeItemCount(const Tree * ptree);
//
///*
//操作:向树中添加一个项目
//操作前:pi指向待添加的项目，ptree指向已初始化的树
//操作后:树未满，将项目添加到树中，返回true，否则返回false
//*/
//BOOL AddItem(Item * pi,Tree * ptree);
//
///*
//操作:在树中查找一个项目
//操作前:pi指向一个项目，ptree指向已初始化的树
//操作后:如果该项目在树中，返回true，否则返回false
//*/
//BOOL InTree(const Item * pi,const Tree * ptree);
//
///*
//操作:从树中删除一个项目
//操作前:pi为待删除项目，ptree指向已初始化的树
//操作后:成功删除，返回true，否则返回false
//*/
//BOOL DeleteItem(const Item * pi,Tree * ptree);
//
///*
//操作:一个函数作用于树中的每一项
//操作前:ptree指向已初始化的树，pfun指向一个函数，接收一个item参数
//操作后:将该函数作用于树中的每一项
//*/
//void Traverse(const Tree * ptree,void(* pfun)(Item item));
//
///*
//操作:从树中删除所有节点
//操作前:ptree指向已初始化的树
//操作后:清空树
//*/
//void DeleteAll(Tree * ptree);
//
///*
//操作:在程序中查找项目，并报告相应节点信息
//操作前:ptree指向已初始化的树，接收一个item
//操作后:找到要查找的项目，并返回
//*/
//void searchNode(const Tree * ptree,const Item item);
//#endif