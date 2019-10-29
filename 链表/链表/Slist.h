#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

// ���� ����ͷ ��ѭ��
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

void SListInit(SList* plt);// ��ʼ��
void SListPushBack(SList* plt, SLTDataType x);// β��
void SListPushFront(SList* plt, SLTDataType x);// ͷ��
void SListPopBack(SList* plt);// βɾ
void SListPopFront(SList* plt);// ͷɾ
SListNode* SlistFind(SList* plt, SLTDataType x);// Ѱ��ĳ��ָ�����
void SListInsertAfter(SListNode* pos, SLTDataType x);// ָ��λ�ú������
void SListEraseAfter(SListNode* pos);// ָ��λ�ú���ɾ��
void SListRemove(SList* plt, SLTDataType x);// ��ֵ֪�ĵ�һ�����ɾ��
void SListRemoveAll(SList* plt, SLTDataType x);// ��ֵ֪�����н��ɾ��
void SListPrint(SList* plt);// ��ӡ
void SListDestory(SList* plt);// ���

void TestSList();// ��������
