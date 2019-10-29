//
#pragma once
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<malloc.h>
//#include<string.h>
//#include"排序.h"
//
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	HPDataType _size;
//	HPDataType _capacity;
//}Heap;
//
//void HeapInit(Heap* hp, HPDataType* a, int n);// 初始化
//void AdjustDown(HPDataType* a, size_t n, size_t parent);// 向下调整
//void HeapSort(HPDataType* a, size_t n);// 堆排序 
//void PrintHeap(HPDataType* a, size_t n);// 打印堆
//
//
//void HeapInit(Heap* hp, HPDataType* a, int n)// 初始化
//{
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
//	memcpy(hp->_a, a, sizeof(HPDataType));
//	hp->_capacity = n;
//	hp->_size = n;
//
//	// 构建成堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(hp->_a, hp->_size, i);
//	}
//}


void AdjustDown1(int* a, size_t n, size_t parent)// 向下调整   升序
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出大的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
			++child;

		// 孩子大于父亲，则交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else return;
	}
}

void AdjustDown2(int* a, size_t n, size_t parent)// 向下调整   降序
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出小的那个孩子
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		// 孩子小于父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else return;
	}
}




void HeapSort(int* a, size_t n)// 堆排序 
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown2(a, n, i);
	}
	int end = n - 1; // end是下标
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

void PrintHeap(int* a, size_t n)// 打印堆
{
	for (int i = 0; i <= n - 1; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}