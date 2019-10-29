#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

ListNode* BuyListNode(LTDataType x)// �����½��
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_val = x;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}

void ListInit(List* plt)// ��ʼ��
{
	assert(plt);
	ListNode* head = BuyListNode(-1);
//	plt->_head->_next = plt->_head;// Ӧ��ָ���һ����㣬���Ǵ�ʱû�е�һ���������һ����㣬��ָ�����Լ������Լ�һ�£����£�
	head->_prev = head;
	head->_next = head;
	plt->_head = head;
}

void ListDestroy(List* plt)// ����
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return 0;
	}
	ListNode* cur = plt->_head->_next;//cur��ָ���һ��Ԫ�ص�ָ��
	while (cur != plt->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plt->_head);//�ͷ�ͷ���
	plt->_head = NULL;//ͷ���ָ���ÿ�
}

void ListPushBack(List* plt, LTDataType x)// β��
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

void ListPopBack(List* plt)// βɾ
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

void ListPushFront(List* plt, LTDataType x)// ͷ��
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

void ListPopFront(List* plt)// ͷɾ
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

ListNode* ListFind(List* plt, LTDataType x) // ���ҽ��x������ָ����x��ָ��
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

void ListInsert(ListNode* pos, LTDataType x)  // ��pos��ǰ�������x
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	pos->_prev = newnode;
	newnode->_next = pos;
}

void ListErase(ListNode* pos) // ɾ��posλ�õĽ��
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plt, LTDataType x)// ɾ�����x
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

int ListSize(List* plt)//˫������Ĵ�С
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

int ListEmpty(List* plt)//�ж�˫�������Ƿ�Ϊ�գ���Ϊ0���ǿ�Ϊ-1
{
	assert(plt);
	//if (plt->_head->_next == plt->_head)
	//{
	//	return 0;
	//}
	//else return -1;

	return ListSize(plt) == 0 ? 0 : -1;
}

void ListPrint(List* plt)// ��ӡ
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