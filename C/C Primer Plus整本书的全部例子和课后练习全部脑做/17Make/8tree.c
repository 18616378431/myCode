//二叉树实现文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"8tree.h"
#include"8list.h"

extern int size;

//局部数据类型
typedef struct pair{
	Node * parent;//指向父节点的指针
	Node * child;//指向自身的指针
}Pair;

//局部函数原型
static Node * MakeNode(const Item * pi);//创建节点
static BOOL ToLeft(const Item *i1,const Item * i2);//判断元素i1是否在当前节点的元素i2的左边
static BOOL ToRight(const Item * i1,const Item * i2);//判断元素i1是否在当前节点的元素i2的右边
static void AddNode(Node * new_node,Node * root);//添加节点
static void InOrder(const Node * root,void (* pfun)(Item item));//使用递归先处理左子树，然后右子树
static Pair	SeekItem(const Item * pi,const Tree * ptree);//搜索元素
static void DeleteNode(Node ** ptr);//删除节点,ptr为指向目标节点的父节点的成员地址
static void DeleteAllNodes(Node * ptr);//删除所有节点
static int GetAllPetNum();//获取所有宠物数量

static void emptyFunc(Item item);//遍历树，不进行任何操作空函数，记录树中的节点，节点中的队列，队列中的元素个数

void print()
{
	print1();
}

//初始化树
void InitializeTree(Tree * ptree)
{
	//初始化树
	ptree->root = NULL;
	ptree->size = 0;
}
//确定树是否为空
BOOL TreeIsEmpty(const Tree * ptree)
{
	if(ptree->root == NULL)
		return TRUE;
	else
		return FALSE;
}
//确定树是否已满
BOOL TreeIsFull(const Tree * ptree)
{
	if(ptree->size == MAXITEMS)
		return TRUE;
	else
		return FALSE;
}
//确定树中节点的数量
int TreeItemCount(const Tree * ptree)
{	
	Traverse(ptree,emptyFunc);
	return size;
}
//添加元素，即节点
BOOL AddItem(const Item * pi,Tree * ptree)
{
	Node * new_node;//新节点
	Pair look;
	
	//初始化查找到的与输入相同的节点look
	/*look.parent = NULL;
	look.child = NULL;*/

	if(TreeIsFull(ptree))//判断树是否已满
	{
		fprintf(stderr,"Tree is full.\n");
		return FALSE;
	}
	if((look = SeekItem(pi,ptree)).child != NULL)//在树中查找目标项目
	{
		fprintf(stderr,"Attempted to add duplicate item\n");
		//如果树中已经存在相应节点，则将新同名元素添加到已有节点列表的末尾
		if(QueueIsFull(look.child->queue))//判断当前节点列表是否已满
		{
			fprintf(stderr,"Current node's queue is full.\n");
			return FALSE;
		}
		EnQueue(*pi,look.child->queue);
	}
	else
	{
		new_node = MakeNode(pi);//创建新节点，成功返回新节点，否则返回NULL
		if(new_node == NULL)//创建失败，返回false
		{
			fprintf(stderr,"Couldn't create node!\n");
			return FALSE;
		}
		//节点创建成功,向树中添加节点
		ptree->size++;//树的大小加1
		if(ptree->root == NULL)//如果树为空
		{
			ptree->root = new_node;
		}
		else
		{
			AddNode(new_node,ptree->root);//找到新节点应该添加到的位置
		}
	}
	return TRUE;
}
//判断目标元素是否存在于树中
BOOL InTree(const Item * pi,const Tree * ptree,void (* pfun)(Item item))
{
	Pair look;
	
	return ((look = SeekItem(pi,ptree)).child == NULL)?FALSE:TraverseQueue(look.child->queue,pfun);
}
//删除元素
BOOL DeleteItem(Item * pi,Tree * ptree)
{
	Pair look;

	look = SeekItem(pi,ptree);//在树中查找目标项目，成功则返回包含目标项目的父节点和当前节点的指针的结构体
	if(look.child == NULL)
	{
		return FALSE;
	}
	if(!DeQueue(pi,look.child->queue) || look.child->queue->end == NULL)//目标节点的队列为空，或删除首元素后目标节点的队列为空
	{
		if(look.parent == NULL)
		{
			DeleteNode(&ptree->root);
		}
		else if(look.parent->left == look.child)
		{
			DeleteNode(&look.parent->left);
		}
		else if(look.parent->right == look.child)
		{
			DeleteNode(&look.parent->right);
		}
		ptree->size--;
	}
	else//当前目标节点的队列不为空，删除成功
	{
		puts("Delete pet's inforamtion succesfully!");
	}
	return TRUE;
}
//遍历树,并且将制定函数作用于树中的每一个节点
void Traverse(const Tree * ptree,void (* pfun)(Item item))
{
	if(ptree != NULL)
	{
		InOrder(ptree->root,pfun);
	}
}
//清空树
void DeleteAll(Tree * ptree)
{
	if(ptree != NULL)
	{
		DeleteAllNodes(ptree->root);
	}
	ptree->root = NULL;
	ptree->size = 0;
}

/*局部函数*/
//在树中查找项目，返回一个pair结构体
static Pair SeekItem(const Item * pi,const Tree * ptree)
{
	Pair look;
	
	look.parent = NULL;//根节点的父节点为NULL
	look.child = ptree->root;//从根节点开始查找
	if(look.child == NULL)//树为空
		return look;
	while(look.child != NULL)
	{
		if(ToLeft(pi,&(look.child->queue->head->item)))//如果目标项目在当前节点，即根节点的左边
		{
			look.parent = look.child;//将父节点设置为当前节点
			look.child = look.child->left;//将当前节点设置为根节点的左节点
		}
		else if(ToRight(pi,&(look.child->queue->head->item)))//如果目标向在当前节点的右边
		{
			look.parent = look.child;//将父节点设置为当前节点
			look.child = look.child->right;//将当前节点设置为根节点的右节点
		}
		else//如果既不在root根节点的左边也不在右边，那么目标节点就是根节点,或者未找到目标项目
		{
			break;//跳出循环
		}
	}
	return look;//返回存有查找到包含父节点指针和当前节点指针的结构体
}
//判断元素是否在当前节点的左端
BOOL ToLeft(const Item * i1,const Item * i2)
{
	int comp;

	if((comp = strcmp(i1->petname,i2->petname)) < 0)
		return TRUE;
	else if(comp == 0 && strcmp(i1->petkind,i2->petkind) < 0)
		return FALSE;
	else
		return FALSE;
}
//判断元素是否在当前节点的右端
BOOL ToRight(const Item * i1,const Item * i2)
{
	int comp;

	if((comp = strcmp(i1->petname,i2->petname)) > 0)
		return TRUE;
	else if(comp == 0 && strcmp(i1->petkind,i2->petkind) > 0)
		return FALSE;
	else
		return FALSE;
}
//创建节点
static Node * MakeNode(const Item * pi)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));//为新节点分配空间
	if(new_node != NULL)//分配成功
	{
		new_node->queue = InitializeQueue();
		EnQueue(*pi,new_node->queue);//将元素的地址赋给新节点的
		new_node->left = new_node->right = NULL;//将新节点的左右节点指针置为空
	}
	return new_node;
}
//向树中添加节点
static void AddNode(Node * new_node,Node * root)
{
	if(ToLeft(&new_node->queue->head->item,&root->queue->head->item))
	{
		if(root->left == NULL)
		{
			root->left = new_node;
		}
		else
		{
			AddNode(new_node,root->left);
		}
	}
	else if(ToRight(&new_node->queue->head->item,&root->queue->head->item))
	{
		if(root->right == NULL)
		{
			root->right = new_node;
		}
		else
		{
			AddNode(new_node,root->right);
		}
	}
	else
	{
		fprintf(stderr,"location error int AddNode()\n");
		exit(EXIT_FAILURE);
	}
}
//删除节点
static void DeleteNode(Node ** ptr)
{
	//ptr为指向目标节点的父节点指针成员的地址
	Node * temp;

	puts((*ptr)->queue->head->item.petname);
	if((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else//被删除的节点有两个子节点
	{
		//找到右子树的依附位置
		for(temp = (*ptr)->left;temp->right != NULL;temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
//从左子节点开始遍历树
static void InOrder(const Node * root,void (* pfun)(Item item))
{
	if(root != NULL)
	{
		InOrder(root->left,pfun);
		TraverseQueue(root->queue,pfun);
		InOrder(root->right,pfun);
	}
}
//删除所有节点
static void DeleteAllNodes(Node *root)
{
	Node * pright;//记录当前节点的右节点

	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root->queue);
		free(root);
		DeleteAllNodes(pright);
	}
}
//遍历树，不进行任何操作空函数，记录树中的节点，节点中的队列，队列中的元素个数
static void emptyFunc(Item item)
{
	size++;
}