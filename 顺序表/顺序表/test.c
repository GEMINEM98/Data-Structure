#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

void test1()
{
	SeqList s1;
	SeqListInit(&s1); // 初始化          

	SeqListPushBack(&s1, 1); // 尾插
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);

	SeqListPushFront(&s1, 0); // 头插

	SeqListPopBack(&s1); // 尾删

	SeqListPopFront(&s1); // 头删

	SeqListInsert(&s1, 0, 0);// 插入

	SeqListErase(&s1, 0);// 删除


	for (size_t i = 0; i < SeqListSize(&s1); ++i)  // 打印
	{
		printf("%d ", SeqListAt(&s1, i));
	}
	printf("\n");

	printf("%d\n", SeqListFind(&s1, 1));// 找值x的位置，返回下标

	SeqListDestory(&s1);// 撤销

}


void test2()
{
	SeqList s2;
	
	SeqListInit(&s2); // 初始化    

	SeqListPushFront(&s2, 5); // 头插
	SeqListPushBack(&s2, 1); // 尾插
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 9);
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 4);
	SeqListPushBack(&s2, 3);

	SeqListRemove(&s2, 5);// 删除第一个指定值的结点
	SeqListModify(&s2, 0, 1);// 删除指定位置的指定值

	SeqListBubbleSort(&s2);// 冒泡排序
	printf("%d\n", SeqListBinaryFind(&s2, 3)); // 二分查找    时间复杂度O(N),空间复杂度O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 4)); // 二分查找    时间复杂度O(N),空间复杂度O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 9)); // 二分查找    时间复杂度O(N),空间复杂度O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 0)); // 二分查找    时间复杂度O(N),空间复杂度O(1)

	SeqListRemoveAll(&s2, 3); // 已知值的全部结点删除

	SeqListPrint(&s2);// 打印
}


int main()
{
	test1();
	//test2();

	system("pause");
	return 0;
}