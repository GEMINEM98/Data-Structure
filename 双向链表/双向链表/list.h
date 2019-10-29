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



ListNode* BuyListNode(LTDataType x);// 建立新结点
void ListInit(List* plt);// 初始化
void ListDestroy(List* plt);// 销毁

void ListPushBack(List* plt, LTDataType x);// 尾插
void ListPopBack(List* plt);// 尾删
void ListPushFront(List* plt, LTDataType x);// 头插
void ListPopFront(List* plt);// 头删

ListNode* ListFind(List* plt, LTDataType x); // 查找结点x，返回指向结点x的指针
void ListInsert(ListNode* pos, LTDataType x);  // 在pos的前面插入结点x
void ListErase(ListNode* pos);// 删除pos位置的结点
void ListRemove(List* plt, LTDataType x);// 删除结点x

int ListSize(List* plt);//双向链表的大小
int ListEmpty(List* plt);//判断双向链表是否为空

void ListPrint(List* plt);// 打印