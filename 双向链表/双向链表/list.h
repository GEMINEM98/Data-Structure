#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* _prev;
	LTDataType _val;
	struct ListNode* _next;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;



ListNode* BuyListNode(LTDataType x);// �����½��
void ListInit(List* plt);// ��ʼ��
void ListDestroy(List* plt);// ����

void ListPushBack(List* plt, LTDataType x);// β��
void ListPopBack(List* plt);// βɾ
void ListPushFront(List* plt, LTDataType x);// ͷ��
void ListPopFront(List* plt);// ͷɾ

ListNode* ListFind(List* plt, LTDataType x); // ���ҽ��x������ָ����x��ָ��
void ListInsert(ListNode* pos, LTDataType x);  // ��pos��ǰ�������x
void ListErase(ListNode* pos);// ɾ��posλ�õĽ��
void ListRemove(List* plt, LTDataType x);// ɾ�����x

int ListSize(List* plt);//˫������Ĵ�С
int ListEmpty(List* plt);//�ж�˫�������Ƿ�Ϊ��

void ListPrint(List* plt);// ��ӡ