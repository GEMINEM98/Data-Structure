#pragma once

#include<stdio.h>
#include<malloc.h>

#include"queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode BTNode;
typedef struct BinaryTreeNode
{
	// �ý���������򣬵�һ����������ָ�룬�ڶ������Ǵ�����ݣ������������Һ���ָ��
	struct BinaryTreeNode* _left;
	BTDataType _data;
	struct BinaryTreeNode* _right;
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* a, int* pi);// ����������
void BinaryTreeDestory(BTNode** root);// ���ٶ�����

int BinaryTreeSize(BTNode* root);// �������Ľ�����
int BinaryTreeLeafSize(BTNode* root);// ������Ҷ�ӽ�����
int BinaryTreeLevelKSize(BTNode* root, int k);// ��������K�������
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);// ���������ҽ��x

void BinaryTreePrevOrder(BTNode* root);// �������
void BinaryTreeInOrder(BTNode* root);// �������
void BinaryTreePostOrder(BTNode* root);// �������
void BinaryTreeLevelOrder(BTNode* root);// �������

int BinaryTreeComplete(BTNode* root);// �ж϶������Ƿ�Ϊ��ȫ������


BTNode* BinaryTreeCreate(BTDataType* a, int* pi)// ����������
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

void BinaryTreeDestory(BTNode** root)// ���ٶ�����
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)// �������Ľ�����
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)// ������Ҷ�ӽ�����
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)// ��������K�������
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)// ���������ҽ��x
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

void BinaryTreePrevOrder(BTNode* root)// �������
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)// �������
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)// �������
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root) // �������
{ 
	Queue q;	
	QueueInit(&q);	
	if (root != NULL)		
		QueuePush(&q, root);// �����ĸ��ڵ�浽������������Ԫ����һ�����������ڵ㣬������������ָ��
	while (!QueueEmpty(&q)) 
	{ 
		BTNode* front = QueueFront(&q);		// front�Ƕ�������һ�����
		printf("%c ", front->_data);        // ��ӡָ��ָ���ֵ	
		QueuePop(&q);		// �Ӷ�����ɾ�����ý��
		if (front->_left != NULL) // �жϸý����������Ƿ�Ϊ�գ���Ϊ�գ������ӽ�������
		{ 
			QueuePush(&q, front->_left); 
		}		
		if (front->_right != NULL) // �жϸý����������Ƿ�Ϊ�գ���Ϊ�գ����Һ��ӽ�������
		{ 
			QueuePush(&q, front->_right); 
		} 
	} 
}

int BinaryTreeComplete(BTNode* root)// �ж϶������Ƿ�Ϊ��ȫ������
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
