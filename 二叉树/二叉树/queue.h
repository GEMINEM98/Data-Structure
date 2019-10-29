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
	QueueNode* _front;// ��ͷ
	QueueNode* _tail;// ��β
}Queue;

void QueueInit(Queue* pq);//��ʼ��
void QueueDestory(Queue* pq);//����
QueueNode* BuyQueueNode(QUDataType x);//�����½��
void QueuePush(Queue* pq, QUDataType x);//�����
void QueuePop(Queue* pq);//��˳��ɾ��
QUDataType QueueFront(Queue* pq);//����ͷ����ֵ
QUDataType QueueBack(Queue* pq);//����β����ֵ
bool QueueEmpty(Queue* pq);//�ж����Ƿ�Ϊ��
int QueueSize(Queue* pq);//���д�С


void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);
	pq->_front = NULL;
	pq->_tail = NULL;
}

void QueueDestory(Queue* pq)//����
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

QueueNode* BuyQueueNode(QUDataType x)//�����½��
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QUDataType x)//�����
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

void QueuePop(Queue* pq)//��˳��ɾ��
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

QUDataType QueueFront(Queue* pq)//����ͷ����ֵ
{
	assert(pq&&pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)//����β����ֵ
{
	assert(pq&&pq->_tail != NULL);
	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)//�ж����Ƿ�Ϊ��
{
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)//���д�С
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
