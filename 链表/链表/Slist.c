#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

void SListInit(SList* plt)// 初始化
{
	assert(plt);
	plt->_head = NULL;
}

void SListPushBack(SList* plt, SLTDataType x)// 尾插
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	// 1.空
	// 2.非空
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SListPushFront(SList* plt, SLTDataType x)// 头插
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPopBack(SList* plt)// 尾删
{
	assert(plt);

/*  方法一：
	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
*/

//  方法二：
	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* n1 = plt->_head;
		SListNode* n2 = plt->_head;
		while (n2->_next != NULL)
		{
			n1 = n2;
			n2 = n2->_next;
		}
		free(n2);
		n2 = NULL;
		n1->_next = NULL;
	}
}

void SListPopFront(SList* plt)// 头删
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;// 防止野指针
	}
}

SListNode* SlistFind(SList* plt, SLTDataType x)// 寻找某个指定结点
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur != NULL)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			else
			{
				cur = cur->_next;
			}
		}
		return NULL;
	}
}

void SListInsertAfter(SListNode* pos, SLTDataType x)// 指定位置后面添加
{
	assert(pos);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)// 指定位置后面删除
{
	assert(pos);

	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* apos = pos->_next;
		pos->_next = apos->_next;
		free(apos);
		apos = NULL;

		//下面这种方法是错误的，因为pos->_next->_next可能指向非法地址。
		//pos->_next = pos->_next->_next;
		//free(pos->_next);
	}
}

void SListRemove(SList* plt, SLTDataType x)// 已知值的第一个结点删除
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* fcur = NULL;
		SListNode* cur = plt->_head;
		while (cur != NULL)
		{
			if (cur->_data != x)
			{
				fcur = cur;
				cur = cur->_next;
			}
			else
			{
				if (fcur == NULL)
					plt->_head = cur->_next;
				else
					fcur->_next = cur->_next;
				free(cur);
				cur = NULL;
				return;
			}
		}
	}
}

void SListRemoveAll(SList* plt, SLTDataType x)// 已知值的所有结点删除
{
	assert(plt);
	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* cur = plt->_head;
		while (cur != NULL)
		{
			if (cur->_data == x)
			{
				if (prev == NULL)
				{
					SListNode* next = cur->_next;
					plt->_head = next;
					free(cur);
					cur = next;
				}
				else
				{
					SListNode* next = cur->_next;
					prev->_next = next;
					free(cur);
					cur = next;
				}
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
	}
}

void SListDestory(SList* plt)// 清空
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur != NULL)
		{
			SListNode* next = cur->_next;
			plt->_head = next;
			free(cur);
			cur = next;// 防止野指针
		}
	}
}

//  方法一：
void SListPrint(SList* plt)// 打印
{
	assert(plt);

	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

//  方法二：
//void SListPrint(SList* plt)// 打印
//{
//	assert(plt);
//
//	if (plt->_head == NULL)
//	{
//		printf("NULL\n");
//		return;
//	}
//	SListNode* cur = plt->_head;
//	while (cur->_next != NULL)
//	{
//		printf("%d->", cur->_data);
//		cur = cur->_next;
//	}
//	printf("%d\n", cur->_data);
//}

void TestSList()// 测试用例
{
	SList lt;
	SListNode* p = NULL;

	SListInit(&lt);// 初始化
	SListPushBack(&lt, 6);// 尾插
	SListPushBack(&lt, 7);// 尾插
	SListPushBack(&lt, 8);// 尾插
	SListPushBack(&lt, 1);// 尾插
	SListPushBack(&lt, 1);// 尾插
	SListPushFront(&lt, 5);// 头插
	SListPushFront(&lt, 4);// 头插
	SListPushFront(&lt, 4);// 头插
	SListPushFront(&lt, 1);// 头插
	SListPushFront(&lt, 4);// 头插
	SListPushFront(&lt, 3);// 头插
	SListPushFront(&lt, 2);// 头插
	SListPushFront(&lt, 1);// 头插
	SListPushFront(&lt, 1);// 头插
	SListPushFront(&lt, 1);// 头插
	SListPrint(&lt);// 打印

	printf("尾删：");
	SListPopBack(&lt);// 尾删
	SListPrint(&lt);// 打印

	printf("头删：");
	SListPopFront(&lt);// 头删
	SListPrint(&lt);// 打印

	printf("寻找2：");
	p = SlistFind(&lt, 2);// 寻找某个指定结点
	printf("%d\n", *p);

	SListNode* pos1 = SlistFind(&lt, 2);
	printf("2后面插入22：");
	SListInsertAfter(pos1, 22);// 指定位置后面添加
	SListPrint(&lt);// 打印

	SListNode* pos2 = SlistFind(&lt, 22);
	printf("22后面删除：");
	SListEraseAfter(pos2);// 指定位置后面删除
	SListPrint(&lt);// 打印

	printf("删除4：");
	SListRemove(&lt, 4);// 已知值结点删除
	SListPrint(&lt);// 打印

	printf("删除1：");
	SListRemoveAll(&lt, 1);// 已知值的所有结点删除
	SListPrint(&lt);// 打印



	printf("清空：");
	SListDestory(&lt);// 清空
	SListPrint(&lt);// 打印
}

int main()
{
	TestSList();
	system("pause");
	return 0;
}