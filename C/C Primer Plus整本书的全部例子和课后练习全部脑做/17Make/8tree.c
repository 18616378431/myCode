//������ʵ���ļ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"8tree.h"
#include"8list.h"

extern int size;

//�ֲ���������
typedef struct pair{
	Node * parent;//ָ�򸸽ڵ��ָ��
	Node * child;//ָ�������ָ��
}Pair;

//�ֲ�����ԭ��
static Node * MakeNode(const Item * pi);//�����ڵ�
static BOOL ToLeft(const Item *i1,const Item * i2);//�ж�Ԫ��i1�Ƿ��ڵ�ǰ�ڵ��Ԫ��i2�����
static BOOL ToRight(const Item * i1,const Item * i2);//�ж�Ԫ��i1�Ƿ��ڵ�ǰ�ڵ��Ԫ��i2���ұ�
static void AddNode(Node * new_node,Node * root);//��ӽڵ�
static void InOrder(const Node * root,void (* pfun)(Item item));//ʹ�õݹ��ȴ�����������Ȼ��������
static Pair	SeekItem(const Item * pi,const Tree * ptree);//����Ԫ��
static void DeleteNode(Node ** ptr);//ɾ���ڵ�,ptrΪָ��Ŀ��ڵ�ĸ��ڵ�ĳ�Ա��ַ
static void DeleteAllNodes(Node * ptr);//ɾ�����нڵ�
static int GetAllPetNum();//��ȡ���г�������

static void emptyFunc(Item item);//���������������κβ����պ�������¼���еĽڵ㣬�ڵ��еĶ��У������е�Ԫ�ظ���

void print()
{
	print1();
}

//��ʼ����
void InitializeTree(Tree * ptree)
{
	//��ʼ����
	ptree->root = NULL;
	ptree->size = 0;
}
//ȷ�����Ƿ�Ϊ��
BOOL TreeIsEmpty(const Tree * ptree)
{
	if(ptree->root == NULL)
		return TRUE;
	else
		return FALSE;
}
//ȷ�����Ƿ�����
BOOL TreeIsFull(const Tree * ptree)
{
	if(ptree->size == MAXITEMS)
		return TRUE;
	else
		return FALSE;
}
//ȷ�����нڵ������
int TreeItemCount(const Tree * ptree)
{	
	Traverse(ptree,emptyFunc);
	return size;
}
//���Ԫ�أ����ڵ�
BOOL AddItem(const Item * pi,Tree * ptree)
{
	Node * new_node;//�½ڵ�
	Pair look;
	
	//��ʼ�����ҵ�����������ͬ�Ľڵ�look
	/*look.parent = NULL;
	look.child = NULL;*/

	if(TreeIsFull(ptree))//�ж����Ƿ�����
	{
		fprintf(stderr,"Tree is full.\n");
		return FALSE;
	}
	if((look = SeekItem(pi,ptree)).child != NULL)//�����в���Ŀ����Ŀ
	{
		fprintf(stderr,"Attempted to add duplicate item\n");
		//��������Ѿ�������Ӧ�ڵ㣬����ͬ��Ԫ����ӵ����нڵ��б��ĩβ
		if(QueueIsFull(look.child->queue))//�жϵ�ǰ�ڵ��б��Ƿ�����
		{
			fprintf(stderr,"Current node's queue is full.\n");
			return FALSE;
		}
		EnQueue(*pi,look.child->queue);
	}
	else
	{
		new_node = MakeNode(pi);//�����½ڵ㣬�ɹ������½ڵ㣬���򷵻�NULL
		if(new_node == NULL)//����ʧ�ܣ�����false
		{
			fprintf(stderr,"Couldn't create node!\n");
			return FALSE;
		}
		//�ڵ㴴���ɹ�,��������ӽڵ�
		ptree->size++;//���Ĵ�С��1
		if(ptree->root == NULL)//�����Ϊ��
		{
			ptree->root = new_node;
		}
		else
		{
			AddNode(new_node,ptree->root);//�ҵ��½ڵ�Ӧ����ӵ���λ��
		}
	}
	return TRUE;
}
//�ж�Ŀ��Ԫ���Ƿ����������
BOOL InTree(const Item * pi,const Tree * ptree,void (* pfun)(Item item))
{
	Pair look;
	
	return ((look = SeekItem(pi,ptree)).child == NULL)?FALSE:TraverseQueue(look.child->queue,pfun);
}
//ɾ��Ԫ��
BOOL DeleteItem(Item * pi,Tree * ptree)
{
	Pair look;

	look = SeekItem(pi,ptree);//�����в���Ŀ����Ŀ���ɹ��򷵻ذ���Ŀ����Ŀ�ĸ��ڵ�͵�ǰ�ڵ��ָ��Ľṹ��
	if(look.child == NULL)
	{
		return FALSE;
	}
	if(!DeQueue(pi,look.child->queue) || look.child->queue->end == NULL)//Ŀ��ڵ�Ķ���Ϊ�գ���ɾ����Ԫ�غ�Ŀ��ڵ�Ķ���Ϊ��
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
	else//��ǰĿ��ڵ�Ķ��в�Ϊ�գ�ɾ���ɹ�
	{
		puts("Delete pet's inforamtion succesfully!");
	}
	return TRUE;
}
//������,���ҽ��ƶ��������������е�ÿһ���ڵ�
void Traverse(const Tree * ptree,void (* pfun)(Item item))
{
	if(ptree != NULL)
	{
		InOrder(ptree->root,pfun);
	}
}
//�����
void DeleteAll(Tree * ptree)
{
	if(ptree != NULL)
	{
		DeleteAllNodes(ptree->root);
	}
	ptree->root = NULL;
	ptree->size = 0;
}

/*�ֲ�����*/
//�����в�����Ŀ������һ��pair�ṹ��
static Pair SeekItem(const Item * pi,const Tree * ptree)
{
	Pair look;
	
	look.parent = NULL;//���ڵ�ĸ��ڵ�ΪNULL
	look.child = ptree->root;//�Ӹ��ڵ㿪ʼ����
	if(look.child == NULL)//��Ϊ��
		return look;
	while(look.child != NULL)
	{
		if(ToLeft(pi,&(look.child->queue->head->item)))//���Ŀ����Ŀ�ڵ�ǰ�ڵ㣬�����ڵ�����
		{
			look.parent = look.child;//�����ڵ�����Ϊ��ǰ�ڵ�
			look.child = look.child->left;//����ǰ�ڵ�����Ϊ���ڵ����ڵ�
		}
		else if(ToRight(pi,&(look.child->queue->head->item)))//���Ŀ�����ڵ�ǰ�ڵ���ұ�
		{
			look.parent = look.child;//�����ڵ�����Ϊ��ǰ�ڵ�
			look.child = look.child->right;//����ǰ�ڵ�����Ϊ���ڵ���ҽڵ�
		}
		else//����Ȳ���root���ڵ�����Ҳ�����ұߣ���ôĿ��ڵ���Ǹ��ڵ�,����δ�ҵ�Ŀ����Ŀ
		{
			break;//����ѭ��
		}
	}
	return look;//���ش��в��ҵ��������ڵ�ָ��͵�ǰ�ڵ�ָ��Ľṹ��
}
//�ж�Ԫ���Ƿ��ڵ�ǰ�ڵ�����
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
//�ж�Ԫ���Ƿ��ڵ�ǰ�ڵ���Ҷ�
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
//�����ڵ�
static Node * MakeNode(const Item * pi)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));//Ϊ�½ڵ����ռ�
	if(new_node != NULL)//����ɹ�
	{
		new_node->queue = InitializeQueue();
		EnQueue(*pi,new_node->queue);//��Ԫ�صĵ�ַ�����½ڵ��
		new_node->left = new_node->right = NULL;//���½ڵ�����ҽڵ�ָ����Ϊ��
	}
	return new_node;
}
//��������ӽڵ�
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
//ɾ���ڵ�
static void DeleteNode(Node ** ptr)
{
	//ptrΪָ��Ŀ��ڵ�ĸ��ڵ�ָ���Ա�ĵ�ַ
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
	else//��ɾ���Ľڵ��������ӽڵ�
	{
		//�ҵ�������������λ��
		for(temp = (*ptr)->left;temp->right != NULL;temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
//�����ӽڵ㿪ʼ������
static void InOrder(const Node * root,void (* pfun)(Item item))
{
	if(root != NULL)
	{
		InOrder(root->left,pfun);
		TraverseQueue(root->queue,pfun);
		InOrder(root->right,pfun);
	}
}
//ɾ�����нڵ�
static void DeleteAllNodes(Node *root)
{
	Node * pright;//��¼��ǰ�ڵ���ҽڵ�

	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root->queue);
		free(root);
		DeleteAllNodes(pright);
	}
}
//���������������κβ����պ�������¼���еĽڵ㣬�ڵ��еĶ��У������е�Ԫ�ظ���
static void emptyFunc(Item item)
{
	size++;
}