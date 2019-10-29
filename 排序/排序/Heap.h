//
#pragma once
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<malloc.h>
//#include<string.h>
//#include"����.h"
//
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	HPDataType _size;
//	HPDataType _capacity;
//}Heap;
//
//void HeapInit(Heap* hp, HPDataType* a, int n);// ��ʼ��
//void AdjustDown(HPDataType* a, size_t n, size_t parent);// ���µ���
//void HeapSort(HPDataType* a, size_t n);// ������ 
//void PrintHeap(HPDataType* a, size_t n);// ��ӡ��
//
//
//void HeapInit(Heap* hp, HPDataType* a, int n)// ��ʼ��
//{
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
//	memcpy(hp->_a, a, sizeof(HPDataType));
//	hp->_capacity = n;
//	hp->_size = n;
//
//	// �����ɶ�
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(hp->_a, hp->_size, i);
//	}
//}


void AdjustDown1(int* a, size_t n, size_t parent)// ���µ���   ����
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ������Ǹ�����
		if (child + 1 < n && a[child + 1] > a[child])
			++child;

		// ���Ӵ��ڸ��ף��򽻻�
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else return;
	}
}

void AdjustDown2(int* a, size_t n, size_t parent)// ���µ���   ����
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ��С���Ǹ�����
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		// ����С�ڸ��ף��򽻻�
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else return;
	}
}




void HeapSort(int* a, size_t n)// ������ 
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown2(a, n, i);
	}
	int end = n - 1; // end���±�
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown2(a, end, 0);
		--end;
	}

	/*for (int i = 0; i < n; i++) {
		Swap(a, a + n - i - 1);
		AdjustDown(a, n - i - 1, 0);
	}*/
}

void PrintHeap(int* a, size_t n)// ��ӡ��
{
	for (int i = 0; i <= n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}