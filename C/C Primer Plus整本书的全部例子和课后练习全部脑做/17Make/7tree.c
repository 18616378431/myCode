////二叉搜索树实现文件
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include"7tree.h"
//
//typedef struct pair{
//	Node * parent;
//	Node * child;
//}Pair;
//
//static Pair SeekItem(const Item * pi,const Tree * ptree);//在树中查找项目
//static Node * MakeNode(const Item * pi);//创建节点
//static BOOL ToLeft(const Item * i1,const Item * i2);//判断新项目位置
//static BOOL ToRight(const Item * i1,const Item * i2);
//static void AddNode(Node * new_node,Node * root);//将节点添加到树中
//static void DeleteNode(Node ** ptr);//从树中删除节点
//static void InOrder(const Node * root,void (* pfun)(Item item));//将函数作用于每个节点
//static void DeleteAllNodes(Node * root);//删除所有节点
//
////初始化树
//void InitalizeTree(Tree * ptree)
//{
//	ptree->root = NULL;
//	ptree->size = 0;
//}
////确定树是否已满
//BOOL TreeIsFull(const Tree * ptree)
//{
//	if(ptree->size == MAXITEM)
//		return true;
//	else
//		return false;
//}
////确定树是否为空
//BOOL TreeIsEmpty(const Tree * ptree)
//{
//	if(ptree->root == NULL)
//		return true;
//	else
//		return false;
//}
////确定树中项目数量
//int TreeItemCount(const Tree * ptree)
//{
//	return ptree->size;
//}
////向树中添加项目
//BOOL AddItem(Item * pi,Tree * ptree)
//{
//	Node * new_node;
//
//	if(TreeIsFull(ptree))
//	{
//		fprintf(stderr,"Tree is full!\n");
//		return false;
//	}
//	if(SeekItem(pi,ptree).child != NULL)
//	{
//		//fprintf(stderr,"The item.word %s exists\n",pi->word);
//	}
//	new_node = MakeNode(pi);
//	if(new_node == NULL)
//	{
//		fprintf(stderr,"Create new node failed!\n");
//		return false;
//	}
//	ptree->size++;
//	pi->ct = 1;
//	if(TreeIsEmpty(ptree))
//	{
//		ptree->root = new_node;
//	}
//	else
//	{
//		AddNode(new_node,ptree->root);
//	}
//	return true;
//}
////检查项目是否在树中
//BOOL InTree(const Item * pi,const Tree * ptree)
//{
//	return (SeekItem(pi,ptree).child == NULL)?false:true;
//}
////从树中删除项目
//BOOL DeleteItem(const Item * pi,Tree * ptree)
//{
//	Pair look;
//
//	look = SeekItem(pi,ptree);
//	if(look.child == NULL)
//		return false;
//	if(look.parent == NULL)
//		DeleteNode(&ptree->root);
//	else if(look.parent->left == look.child)
//		DeleteNode(&look.parent->left);
//	else if(look.parent->right == look.child)
//		DeleteNode(&look.parent->right);
//	ptree->size--;
//	return true;
//}
////将函数作用于树的每一项
//void Traverse(const Tree * ptree,void(* pfun)(Item item))
//{
//	if(ptree != NULL)
//		InOrder(ptree->root,pfun);
//}
//void DeleteAll(Tree * ptree)
//{
//	if(ptree != NULL)
//		DeleteAllNodes(ptree->root);
//	ptree->root = NULL;
//	ptree->size = 0;
//}
//void searchNode(const Tree * ptree,const Item item)
//{
//	Pair look;
//
//	look = SeekItem(&item,ptree);
//	printf("The word times is %d.\n",look.child->item.ct);
//}
//
///*局部函数*/
//static Pair SeekItem(const Item * pi,const Tree * ptree)
//{
//	Pair look;
//
//	look.parent = NULL;
//	look.child = ptree->root;
//	if(look.child == NULL)
//		return look;
//	while(look.child != NULL)
//	{
//		if(ToLeft(pi,&(look.child->item)))
//		{
//			look.parent = look.child;
//			look.child = look.child->left;
//		}
//		else if(ToRight(pi,&(look.child->item)))
//		{
//			look.parent = look.child;
//			look.child = look.child->right;
//		}
//		else//目标项目即不在左边也不在右边，则相等
//		{
//			break;//look.child为目标项目节点地址
//		}
//	}
//	return look;
//}
////判断目标项目在当前节点的左边还是右边
//static BOOL ToLeft(const Item * i1,const Item * i2)
//{
//	int comp;
//
//	if((comp = strcmp(i1->word,i2->word)) < 0)
//		return true;
//	else
//		return false;
//}
////判断目标项目在当前节点的左边还是右边
//static BOOL ToRight(const Item * i1,const Item * i2)
//{
//	int comp;
//
//	if((comp = strcmp(i1->word,i2->word)) > 0)
//		return true;
//	else
//		return false;
//}
////创建节点
//static Node * MakeNode(const Item * pi)
//{
//	Node * new_node;
//	
//	new_node = (Node *)malloc(sizeof(Node));
//	if(new_node != NULL)
//	{
//		new_node->item = *pi;
//		new_node->left = NULL;
//		new_node->right = NULL;
//		new_node->item.ct = 1;
//	}
//	return new_node;
//}
////将节点添加到树中
//static void AddNode(Node * new_node,Node * root)//接受新节点和根节点
//{
//	if(ToLeft(&new_node->item,&root->item))
//	{
//		if(root->left == NULL)
//		{
//			root->left = new_node;
//		}
//		else
//		{
//			AddNode(new_node,root->left);
//		}
//	}
//	else if(ToRight(&new_node->item,&root->item))
//	{
//		if(root->right == NULL)
//		{
//			root->right = new_node;
//		}
//		else
//		{
//			AddNode(new_node,root->right);
//		}
//	}
//	else
//	{
//		root->item.ct++;
//		//fprintf(stderr,"Same word!\n");
//	}
//}
////从树中删除节点
//static void DeleteNode(Node ** ptr)
//{
//	Node * temp;
//
//	puts((*ptr)->item.word);
//	if((*ptr)->left == NULL)
//	{
//		temp = *ptr;
//		*ptr = (*ptr)->right;
//		free(temp);
//	}
//	else if((*ptr)->right == NULL)
//	{
//		temp = *ptr;
//		*ptr = (*ptr)->left;
//		free(temp);
//	}
//	else
//	{
//		for(temp = (*ptr)->left;temp->right != NULL;temp = temp->right)
//			continue;
//		temp->right = (*ptr)->right;
//		temp = *ptr;
//		*ptr = (*ptr)->left;
//		free(temp);
//	}
//}
//static void InOrder(const Node * root,void (* pfun)(Item item))
//{
//	if(root != NULL)
//	{
//		InOrder(root->left,pfun);
//		(*pfun)(root->item);
//		InOrder(root->right,pfun);
//	}
//}
//static void DeleteAllNodes(Node * root)
//{
//	Node * pright;
//
//	if(root != NULL)
//	{
//		pright = root->right;
//		DeleteAllNodes(root->left);
//		free(root);
//		DeleteAllNodes(pright);
//	}
//}