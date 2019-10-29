#define _CRT_SECURE_NO_WARNINGS 1

#include"排序.h"
#include"Heap.h"
#include"Stack.h"

void test()
{
	int a[] = { 1,5,2,3,9,7,6,4,8 };
	int n = sizeof(a) / sizeof(a[0]);

	printf("原数列a：");
	PrintSort(a, n);

	int b[] = { 49,38,65,97,76,13,27,49 };
	int m = sizeof(b) / sizeof(b[0]);

	printf("原数列b：");
	PrintSort(b, m);

	/*printf("直接插入排序：");
	DirectInsertionSort(a, n);
	PrintSort(a, n);*/

	/*printf("希尔排序：");
	ShellSort(a, n);
	PrintSort(a, n);*/

	//printf("直接选择排序：");
	//DirectSelectionSort(a, n);
	//PrintSort(a, n);

	/*printf("堆排序：");

	HeapSort(a, n);
	PrintHeap(a, n);*/

	/*printf("冒泡排序：");
	BubbleSort(a, n);
	PrintSort(a, n);*/

	/*printf("快速排序(左右指针法)：");      
	QuickSort1(a, 0, n - 1);
	PrintSort(a, n);
	QuickSort1(b, 0, m - 1);
	PrintSort(b, m);*/

	/*printf("快速排序(挖坑法)：");
	QuickSort2(a, 0, n - 1);
	PrintSort(a, n);*/

	/*printf("快速排序(挖坑法，优化)：");
	QuickSort22(a, 0, n - 1);
	PrintSort(a, n);
	QuickSort22(b, 0, m - 1);
	PrintSort(b, m);*/

	/*printf("快速排序(前后指针法)：");
	QuickSort3(a, 0, n - 1);
	PrintSort(a, n);*/

	printf("快速排序(非递归法)：");   
	QuickSort4(a, 0, n - 1);
	PrintSort(a, n);

	//printf("归并排序："); 
	//MergeSort1(a, n);
	//PrintSort(a, n);

	//printf("归并排序(非递归法)：");   
	//MergeSort2(a, n);
	//PrintSort(a, n);

	//printf("计数排序（鸽巢排序）：");
	//CountSort(a, n);
	//PrintSort(a, n);
}

int main()
{
	test();
	system("pause");
	return 0;
}