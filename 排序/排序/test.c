#define _CRT_SECURE_NO_WARNINGS 1

#include"����.h"
#include"Heap.h"
#include"Stack.h"

void test()
{
	int a[] = { 1,5,2,3,9,7,6,4,8 };
	int n = sizeof(a) / sizeof(a[0]);

	printf("ԭ����a��");
	PrintSort(a, n);

	int b[] = { 49,38,65,97,76,13,27,49 };
	int m = sizeof(b) / sizeof(b[0]);

	printf("ԭ����b��");
	PrintSort(b, m);

	/*printf("ֱ�Ӳ�������");
	DirectInsertionSort(a, n);
	PrintSort(a, n);*/

	/*printf("ϣ������");
	ShellSort(a, n);
	PrintSort(a, n);*/

	//printf("ֱ��ѡ������");
	//DirectSelectionSort(a, n);
	//PrintSort(a, n);

	/*printf("������");

	HeapSort(a, n);
	PrintHeap(a, n);*/

	/*printf("ð������");
	BubbleSort(a, n);
	PrintSort(a, n);*/

	/*printf("��������(����ָ�뷨)��");      
	QuickSort1(a, 0, n - 1);
	PrintSort(a, n);
	QuickSort1(b, 0, m - 1);
	PrintSort(b, m);*/

	/*printf("��������(�ڿӷ�)��");
	QuickSort2(a, 0, n - 1);
	PrintSort(a, n);*/

	/*printf("��������(�ڿӷ����Ż�)��");
	QuickSort22(a, 0, n - 1);
	PrintSort(a, n);
	QuickSort22(b, 0, m - 1);
	PrintSort(b, m);*/

	/*printf("��������(ǰ��ָ�뷨)��");
	QuickSort3(a, 0, n - 1);
	PrintSort(a, n);*/

	printf("��������(�ǵݹ鷨)��");   
	QuickSort4(a, 0, n - 1);
	PrintSort(a, n);

	//printf("�鲢����"); 
	//MergeSort1(a, n);
	//PrintSort(a, n);

	//printf("�鲢����(�ǵݹ鷨)��");   
	//MergeSort2(a, n);
	//PrintSort(a, n);

	//printf("�������򣨸볲���򣩣�");
	//CountSort(a, n);
	//PrintSort(a, n);
}

int main()
{
	test();
	system("pause");
	return 0;
}