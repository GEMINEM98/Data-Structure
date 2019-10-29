#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	size_t _size; // ��С
	size_t _capacity; // ����
}SeqList;

void SeqListInit(SeqList* ps);// ��ʼ��
void SeqListDestory(SeqList* ps);// ����
void SeqListPushBack(SeqList* ps, DataType x);// β��
void SeqListPushFront(SeqList* ps, DataType x);// ͷ��
void SeqListPopBack(SeqList* ps);// βɾ
void SeqListPopFront(SeqList* ps);// ͷɾ

void SeqListInsert(SeqList* ps, size_t pos, DataType x);// ����
void SeqListErase(SeqList* ps, size_t pos);// ɾ��ָ��λ�õĽ��
size_t SeqListSize(SeqList* ps);// ��������
size_t SeqListFind(SeqList* ps, DataType x);// ��ֵx��λ�ã������±�
DataType SeqListAt(SeqList* ps, size_t pos);// ����posλ�õ�ֵ

void SeqListRemove(SeqList* ps, DataType x); // ɾ��ָ��ֵ�Ľ��
void SeqListModify(SeqList* ps, size_t pos, DataType x); // ɾ��ָ��λ�õ�ָ��ֵ
void SeqListPrint(SeqList* ps); // ��ӡ

void SeqListBubbleSort(SeqList* ps);// ð������
int SeqListBinaryFind(SeqList* ps, DataType x); // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
void SeqListRemoveAll(SeqList* ps, DataType x);//  ��ֵ֪��ȫ�����ɾ��