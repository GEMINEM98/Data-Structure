#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

// 单向 不带头 不循环
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);// 初始化
void SListPushBack(SList* plt, SLTDataType x);// 尾插
void SListPushFront(SList* plt, SLTDataType x);// 头插
void SListPopBack(SList* plt);// 尾删
void SListPopFront(SList* plt);// 头删
SListNode* SlistFind(SList* plt, SLTDataType x);// 寻找某个指定结点
void SListInsertAfter(SListNode* pos, SLTDataType x);// 指定位置后面添加
void SListEraseAfter(SListNode* pos);// 指定位置后面删除
void SListRemove(SList* plt, SLTDataType x);// 已知值的第一个结点删除
void SListRemoveAll(SList* plt, SLTDataType x);// 已知值的所有结点删除
void SListPrint(SList* plt);// 打印
void SListDestory(SList* plt);// 清空

void TestSList();// 测试用例
