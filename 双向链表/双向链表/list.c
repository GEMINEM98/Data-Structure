#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

ListNode* BuyListNode(LTDataType x)// 建立新结点
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_val = x;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}

void ListInit(List* plt)// 初始化
{
	assert(plt);
	ListNode* head = BuyListNode(-1);
//	plt->_head->_next = plt->_head;// 应该指向第一个结点，但是此时没有第一个结点和最后一个结点，它指向它自己，所以简化一下，如下：
	head->_prev = head;
	head->_next = head;
	plt->_head = head;
}

void ListDestroy(List* plt)// 销毁
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return 0;
	}
	ListNode* cur = plt->_head->_next;//cur是指向第一个元素的指针
	while (cur != plt->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plt->_head);//释放头结点
	plt->_head = NULL;//头结点指针置空
}

void ListPushBack(List* plt, LTDataType x)// 尾插
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	head->_prev = newnode;
	newnode->_next = head;
}

void ListPopBack(List* plt)// 尾删
{
	assert(plt);
	if (plt->_head == NULL || plt->_head->_next == plt->_head)
	{
		return 0;
	}
	ListNode* cur = plt->_head->_prev;
	ListNode* prev = cur->_prev;
	prev->_next = plt->_head;
	plt->_head->_prev = prev;
	free(cur);
	cur = NULL;
}

void ListPushFront(List* plt, LTDataType x)// 头插
{
	assert(plt);
	ListNode* newnode = BuyListNode(x);
	if (plt->_head->_next == plt->_head)
	{
		ListPushBack(&plt, x);
		return 0;
	}
	ListNode* first = plt->_head->_next;
	plt->_head->_next = newnode;
	newnode->_prev = plt->_head;
	first->_prev = newnode;
	newnode->_next = first;
}

void ListPopFront(List* plt)// 头删
{
	assert(plt);
	ListNode* head = plt->_head;
	if (plt->_head->_next == plt->_head)
	{
		return 0;
	}
	ListNode* first = head->_next;
	ListNode* second = first->_next;

	free(first);
	head->_next = second;
	second->_prev = head;
}

ListNode* ListFind(List* plt, LTDataType x) // 查找结点x，返回指向结点x的指针
{
	assert(plt);
	ListNode* cur = plt->_head->_next;
	while (cur != plt->_head)
	{
		if (cur->_val == x) 
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)  // 在pos的前面插入结点x
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	pos->_prev = newnode;
	newnode->_next = pos;
}

void ListErase(ListNode* pos) // 删除pos位置的结点
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plt, LTDataType x)// 删除结点x
{
	//assert(plt);
	//ListNode* cur = plt->_head->_next;
	//while (cur != plt->_head)
	//{
	//	if (cur->_val == x)
	//	{
	//		ListErase(cur);
	//		return 0;
	//	}
	//}

	assert(plt);
	ListNode* tmp = ListFind(plt, 1);
	if (tmp)
	{
		ListErase(tmp);
	}
}

int ListSize(List* plt)//双向链表的大小
{
	assert(plt);
	ListNode* cur = plt->_head->_next;
	int count = 0;
	while (cur != plt->_head)
	{
		++count;
		cur = cur->_next;
	}
	return count;

}

int ListEmpty(List* plt)//判断双向链表是否为空，空为0，非空为-1
{
	assert(plt);
	//if (plt->_head->_next == plt->_head)
	//{
	//	return 0;
	//}
	//else return -1;

	return ListSize(plt) == 0 ? 0 : -1;
}

void ListPrint(List* plt)// 打印
{
	assert(plt);
	if (plt->_head == NULL)
	{
		printf("NULL\n");
		return 0;
	}
	ListNode* cur = plt->_head->_next;
	printf("<==>head<==>");
	while (cur != plt->_head)
	{
		printf("%d<==>", cur->_val);
		cur = cur->_next;
	}
	printf("\n");
}