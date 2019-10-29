#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void test1()
{
	List lt;

	ListInit(&lt);// 初始化
	ListPrint(&lt);// 打印

	ListPushBack(&lt, 1);// 尾插
	ListPushBack(&lt, 2);// 尾插
	ListPushBack(&lt, 3);// 尾插
	ListPushBack(&lt, 4);// 尾插
	ListPushBack(&lt, 5);// 尾插
	ListPrint(&lt);// 打印

	ListPopBack(&lt);// 尾删
	ListPrint(&lt);// 打印

	ListPushFront(&lt, 0);// 头插
	ListPrint(&lt);// 打印

	ListPopFront(&lt);// 头删
	ListPrint(&lt);// 打印

	ListInsert(ListFind(&lt, 1), 0);  // 在pos的前面插入结点x
	ListPrint(&lt);// 打印

	ListErase(ListFind(&lt, 0)); // 删除pos位置的结点
	ListPrint(&lt);// 打印

	ListRemove(&lt, 1);// 删除结点x
	ListPrint(&lt);// 打印

	printf("双向链表的大小是：%d\n",ListSize(&lt));//双向链表的大小
	printf("双向链表是否为空：%d\n", ListEmpty(&lt));//判断双向链表的大小

	ListDestroy(&lt);// 销毁
	ListPrint(&lt);// 打印
}

int main()
{
	test1();
	system("pause");
	return 0;
}