#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void test1()
{
	List lt;

	ListInit(&lt);// ��ʼ��
	ListPrint(&lt);// ��ӡ

	ListPushBack(&lt, 1);// β��
	ListPushBack(&lt, 2);// β��
	ListPushBack(&lt, 3);// β��
	ListPushBack(&lt, 4);// β��
	ListPushBack(&lt, 5);// β��
	ListPrint(&lt);// ��ӡ

	ListPopBack(&lt);// βɾ
	ListPrint(&lt);// ��ӡ

	ListPushFront(&lt, 0);// ͷ��
	ListPrint(&lt);// ��ӡ

	ListPopFront(&lt);// ͷɾ
	ListPrint(&lt);// ��ӡ

	ListInsert(ListFind(&lt, 1), 0);  // ��pos��ǰ�������x
	ListPrint(&lt);// ��ӡ

	ListErase(ListFind(&lt, 0)); // ɾ��posλ�õĽ��
	ListPrint(&lt);// ��ӡ

	ListRemove(&lt, 1);// ɾ�����x
	ListPrint(&lt);// ��ӡ

	printf("˫������Ĵ�С�ǣ�%d\n",ListSize(&lt));//˫������Ĵ�С
	printf("˫�������Ƿ�Ϊ�գ�%d\n", ListEmpty(&lt));//�ж�˫������Ĵ�С

	ListDestroy(&lt);// ����
	ListPrint(&lt);// ��ӡ
}

int main()
{
	test1();
	system("pause");
	return 0;
}