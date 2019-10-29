#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	size_t _size; // 大小
	size_t _capacity; // 容量
}SeqList;

void SeqListInit(SeqList* ps);// 初始化
void SeqListDestory(SeqList* ps);// 销毁
void SeqListPushBack(SeqList* ps, DataType x);// 尾插
void SeqListPushFront(SeqList* ps, DataType x);// 头插
void SeqListPopBack(SeqList* ps);// 尾删
void SeqListPopFront(SeqList* ps);// 头删

void SeqListInsert(SeqList* ps, size_t pos, DataType x);// 插入
void SeqListErase(SeqList* ps, size_t pos);// 删除指定位置的结点
size_t SeqListSize(SeqList* ps);// 返回数据
size_t SeqListFind(SeqList* ps, DataType x);// 找值x的位置，返回下标
DataType SeqListAt(SeqList* ps, size_t pos);// 返回pos位置的值

void SeqListRemove(SeqList* ps, DataType x); // 删除指定值的结点
void SeqListModify(SeqList* ps, size_t pos, DataType x); // 删除指定位置的指定值
void SeqListPrint(SeqList* ps); // 打印

void SeqListBubbleSort(SeqList* ps);// 冒泡排序
int SeqListBinaryFind(SeqList* ps, DataType x); // 二分查找    时间复杂度O(N),空间复杂度O(1)
void SeqListRemoveAll(SeqList* ps, DataType x);//  已知值的全部结点删除