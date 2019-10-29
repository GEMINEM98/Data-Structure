#pragma once
#include"binary.h"

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BinaryTreeNode* QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;// 队头
	QueueNode* _tail;// 队尾
}Queue;

void QueueInit(Queue* pq);//初始化
void QueueDestory(Queue* pq);//销毁
QueueNode* BuyQueueNode(QUDataType x);//建立新结点
void QueuePush(Queue* pq, QUDataType x);//入队列
void QueuePop(Queue* pq);//按顺序删除
QUDataType QueueFront(Queue* pq);//返回头结点的值
QUDataType QueueBack(Queue* pq);//返回尾结点的值
bool QueueEmpty(Queue* pq);//判队列是否为空
int QueueSize(Queue* pq);//队列大小


void QueueInit(Queue* pq)//初始化
{
	assert(pq);
	pq->_front = NULL;
	pq->_tail = NULL;
}

void QueueDestory(Queue* pq)//销毁
{
	//assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = NULL;
	pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)//建立新结点
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QUDataType x)//入队列
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL)
	{
		pq->_front = newnode;
		pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)//按顺序删除
{
	assert(pq&&pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
}

QUDataType QueueFront(Queue* pq)//返回头结点的值
{
	assert(pq&&pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)//返回尾结点的值
{
	assert(pq&&pq->_tail != NULL);
	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)//判队列是否为空
{
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)//队列大小
{
	assert(pq);
	size_t count = 0;
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
