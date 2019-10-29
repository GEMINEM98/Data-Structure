#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

void SListInit(SList* plt)// ��ʼ��
{
	assert(plt);
	plt->_head = NULL;
}

void SListPushBack(SList* plt, SLTDataType x)// β��
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	// 1.��
	// 2.�ǿ�
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

void SListPushFront(SList* plt, SLTDataType x)// ͷ��
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPopBack(SList* plt)// βɾ
{
	assert(plt);

/*  ����һ��
	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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

//  ��������
	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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

void SListPopFront(SList* plt)// ͷɾ
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;// ��ֹҰָ��
	}
}

SListNode* SlistFind(SList* plt, SLTDataType x)// Ѱ��ĳ��ָ�����
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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

void SListInsertAfter(SListNode* pos, SLTDataType x)// ָ��λ�ú������
{
	assert(pos);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)// ָ��λ�ú���ɾ��
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

		//�������ַ����Ǵ���ģ���Ϊpos->_next->_next����ָ��Ƿ���ַ��
		//pos->_next = pos->_next->_next;
		//free(pos->_next);
	}
}

void SListRemove(SList* plt, SLTDataType x)// ��ֵ֪�ĵ�һ�����ɾ��
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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

void SListRemoveAll(SList* plt, SLTDataType x)// ��ֵ֪�����н��ɾ��
{
	assert(plt);
	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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

void SListDestory(SList* plt)// ���
{
	assert(plt);

	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
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
			cur = next;// ��ֹҰָ��
		}
	}
}

//  ����һ��
void SListPrint(SList* plt)// ��ӡ
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

//  ��������
//void SListPrint(SList* plt)// ��ӡ
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

void TestSList()// ��������
{
	SList lt;
	SListNode* p = NULL;

	SListInit(&lt);// ��ʼ��
	SListPushBack(&lt, 6);// β��
	SListPushBack(&lt, 7);// β��
	SListPushBack(&lt, 8);// β��
	SListPushBack(&lt, 1);// β��
	SListPushBack(&lt, 1);// β��
	SListPushFront(&lt, 5);// ͷ��
	SListPushFront(&lt, 4);// ͷ��
	SListPushFront(&lt, 4);// ͷ��
	SListPushFront(&lt, 1);// ͷ��
	SListPushFront(&lt, 4);// ͷ��
	SListPushFront(&lt, 3);// ͷ��
	SListPushFront(&lt, 2);// ͷ��
	SListPushFront(&lt, 1);// ͷ��
	SListPushFront(&lt, 1);// ͷ��
	SListPushFront(&lt, 1);// ͷ��
	SListPrint(&lt);// ��ӡ

	printf("βɾ��");
	SListPopBack(&lt);// βɾ
	SListPrint(&lt);// ��ӡ

	printf("ͷɾ��");
	SListPopFront(&lt);// ͷɾ
	SListPrint(&lt);// ��ӡ

	printf("Ѱ��2��");
	p = SlistFind(&lt, 2);// Ѱ��ĳ��ָ�����
	printf("%d\n", *p);

	SListNode* pos1 = SlistFind(&lt, 2);
	printf("2�������22��");
	SListInsertAfter(pos1, 22);// ָ��λ�ú������
	SListPrint(&lt);// ��ӡ

	SListNode* pos2 = SlistFind(&lt, 22);
	printf("22����ɾ����");
	SListEraseAfter(pos2);// ָ��λ�ú���ɾ��
	SListPrint(&lt);// ��ӡ

	printf("ɾ��4��");
	SListRemove(&lt, 4);// ��ֵ֪���ɾ��
	SListPrint(&lt);// ��ӡ

	printf("ɾ��1��");
	SListRemoveAll(&lt, 1);// ��ֵ֪�����н��ɾ��
	SListPrint(&lt);// ��ӡ



	printf("��գ�");
	SListDestory(&lt);// ���
	SListPrint(&lt);// ��ӡ
}

int main()
{
	TestSList();
	system("pause");
	return 0;
}