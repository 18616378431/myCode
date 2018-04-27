#include<stdio.h>
#include<stdlib.h>

//创建节点
Node *makeNode();

typedef struct {
	int num;
	struct Node *next;
} Node;

int main()
{
	Node *lib = (Node *)malloc(sizeof(Node));
	
	lib->num = 1;
	lib->next = NULL;

	return 0;
}

Node *makeNode()
{
	Node *node = (Node *)malloc(sizeof(Node));
	return node;
}