#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

void test1()
{
	SeqList s1;
	SeqListInit(&s1); // ��ʼ��          

	SeqListPushBack(&s1, 1); // β��
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);

	SeqListPushFront(&s1, 0); // ͷ��

	SeqListPopBack(&s1); // βɾ

	SeqListPopFront(&s1); // ͷɾ

	SeqListInsert(&s1, 0, 0);// ����

	SeqListErase(&s1, 0);// ɾ��


	for (size_t i = 0; i < SeqListSize(&s1); ++i)  // ��ӡ
	{
		printf("%d ", SeqListAt(&s1, i));
	}
	printf("\n");

	printf("%d\n", SeqListFind(&s1, 1));// ��ֵx��λ�ã������±�

	SeqListDestory(&s1);// ����

}


void test2()
{
	SeqList s2;
	
	SeqListInit(&s2); // ��ʼ��    

	SeqListPushFront(&s2, 5); // ͷ��
	SeqListPushBack(&s2, 1); // β��
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 9);
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 4);
	SeqListPushBack(&s2, 3);

	SeqListRemove(&s2, 5);// ɾ����һ��ָ��ֵ�Ľ��
	SeqListModify(&s2, 0, 1);// ɾ��ָ��λ�õ�ָ��ֵ

	SeqListBubbleSort(&s2);// ð������
	printf("%d\n", SeqListBinaryFind(&s2, 3)); // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 4)); // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 9)); // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
	printf("%d\n", SeqListBinaryFind(&s2, 0)); // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)

	SeqListRemoveAll(&s2, 3); // ��ֵ֪��ȫ�����ɾ��

	SeqListPrint(&s2);// ��ӡ
}


int main()
{
	test1();
	//test2();

	system("pause");
	return 0;
}