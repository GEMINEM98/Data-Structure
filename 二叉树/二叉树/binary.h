#pragma once

#include<stdio.h>
#include<malloc.h>

#include"queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode BTNode;
typedef struct BinaryTreeNode
{
	// 该结点有三个域，第一个域是左孩子指针，第二个域是存的数据，第三个域是右孩子指针
	struct BinaryTreeNode* _left;
	BTDataType _data;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* a, int* pi);// 构建二叉树
void BinaryTreeDestory(BTNode** root);// 销毁二叉树

int BinaryTreeSize(BTNode* root);// 二叉树的结点个数
int BinaryTreeLeafSize(BTNode* root);// 二叉树叶子结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);// 二叉树第K层结点个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);// 二叉树查找结点x

void BinaryTreePrevOrder(BTNode* root);// 先序遍历
void BinaryTreeInOrder(BTNode* root);// 中序遍历
void BinaryTreePostOrder(BTNode* root);// 后序遍历
void BinaryTreeLevelOrder(BTNode* root);// 层序遍历

int BinaryTreeComplete(BTNode* root);// 判断二叉树是否为完全二叉树


BTNode* BinaryTreeCreate(BTDataType* a, int* pi)// 构建二叉树
{
	if (a[*pi] == '#')
		return NULL;

	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = a[*pi];

	++(*pi);
	node->_left = BinaryTreeCreate(a, pi);

	++(*pi);
	node->_right = BinaryTreeCreate(a, pi);

	return node;
}

void BinaryTreeDestory(BTNode** root)// 销毁二叉树
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)// 二叉树的结点个数
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)// 二叉树叶子结点个数
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)// 二叉树第K层结点个数
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)// 二叉树查找结点x
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left != NULL)
		return left;

	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right != NULL)
		return right;

	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)// 先序遍历
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)// 中序遍历
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)// 后序遍历
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root) // 层序遍历
{ 
	Queue q;	
	QueueInit(&q);	
	if (root != NULL)		
		QueuePush(&q, root);// 把树的根节点存到队列里，队列里的元素是一个完整的树节点，有左右子树的指针
	while (!QueueEmpty(&q)) 
	{ 
		BTNode* front = QueueFront(&q);		// front是二叉树的一个结点
		printf("%c ", front->_data);        // 打印指针指向的值	
		QueuePop(&q);		// 从队列里删除掉该结点
		if (front->_left != NULL) // 判断该结点的左子树是否为空，不为空，则左孩子结点入队列
		{ 
			QueuePush(&q, front->_left); 
		}		
		if (front->_right != NULL) // 判断该结点的右子树是否为空，不为空，则右孩子结点入队列
		{ 
			QueuePush(&q, front->_right); 
		} 
	} 
}

int BinaryTreeComplete(BTNode* root)// 判断二叉树是否为完全二叉树
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else break;
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}
	return true;
}
