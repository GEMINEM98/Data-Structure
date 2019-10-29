#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Stack.h"



// ����  �鲢  ����  ��������



void PrintSort(int* a, int n)// ��ӡ
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


//*******************************************************************************************************************


void DirectInsertionSort(int* a, int n)// ֱ�Ӳ�������
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;// �±�
		int index = a[end + 1];// ��¼������ֵ
		while (end >= 0)
		{
			if (index < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else break;
		}
		a[end + 1] = index;
	}
}


//*******************************************************************************************************************


void ShellSort(int* a, int n)// ϣ������
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int index = a[end + gap];

			while (end >= 0)
			{
				if (index < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else break;
			}
			a[end + gap] = index;
		}
	}
}


//*******************************************************************************************************************


void Swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
void DirectSelectionSort(int* a, int n)// ֱ��ѡ������
{
	int end = n - 1;
	int begin = 0;
	int min;
	int max;
	while (begin <= end)
	{
		max = begin;
		min = begin;
		for (int i = begin + 1; i <= end; ++i)// ���м������е������Сֵ
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[min], &a[begin]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);

		++begin;
		--end;
	}
}


//*******************************************************************************************************************


void BubbleSort(int* a, int n)// ð������
{
	for (int i = 0; i < n - 1; ++i)    // ����ѭ��������
	{
		int tmp = n - i - 1;           // ��¼ÿ����Ҫ�ȽϵĴ���
		for (int j = 0; j < tmp; ++j)  // ����ÿ����Ҫ�ȽϵĴ���
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}




//************************************************��������**************************************************************




int _QuickPartSort1(int* a, int left, int right)// ������������ָ�뷨��  
{
	int key = a[right];
	int keyindex = right;

	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;
		}
		while (left < right && a[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	Swap(&a[left], &a[keyindex]);
	return left;
}
void QuickSort1(int* a, int left, int right)// ������������ָ�뷨�� 
{
	if (left >= right)
		return;
	int keyindex = _QuickPartSort1(a, left, right);

	QuickSort1(a, left, keyindex - 1);
	QuickSort1(a, keyindex + 1, right);
}


//------------------------------------------------------------------------------------------------------------------


int _QuickPartSort2(int* a, int left, int right)// ���������ڿӷ���
{
	int key = a[right];   //��¼��׼ֵ
	while (left < right)
	{
		//leftԪ��С�ڵ��ڻ�׼ֵ�������±�����
		while (left < right&&a[left] <= key)
		{
			++left;
		}
		a[right] = a[left]; //�����ڻ�׼ֵ��Ԫ��Ų���ұ�

		//rightԪ�ش��ڵ��ڻ�׼ֵ�������±�����
		while (left < right&&a[right] >= key) 
		{
			--right;
		}
		a[left] = a[right]; //��С�ڻ�׼ֵ��Ԫ��Ų�����
	}
	a[left] = key; //��λ��׼ֵ
	return left;
}
void QuickSort2(int* a, int left, int right)// ���������ڿӷ���
{
	if (left >= right)
		return;
	int keyindex = _QuickPartSort2(a, left, right);

	QuickSort2(a, left, keyindex - 1);
	QuickSort2(a, keyindex + 1, right);
}


//------------------------------------------------------------------------------------------------------------------


int GetMidIndex(int* a, int left, int right) // �Ż�����������ȡ�� 
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else return left;
	}
	else  // a[left]>a[mid]
	{
		if (a[right] < a[mid])
			return mid;
		else if (a[left] < a[right])
			return left;
		else return right;
	}
}
int _QuickPartSort22(int* a, int left, int right)// ���������ڿӷ���
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];

	while (left < right)
	{
		while (left < right&&a[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			a[right] = a[left];
			right--;
		}

		while (left < right&&a[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			a[left] = a[right];
			left++;
		}
	}
	a[left] = key;
	return left;
}
void QuickSort22(int* a, int left, int right)// ���������ڿӷ���
{
	if (left >= right)
		return;
	int keyindex = _QuickPartSort22(a, left, right);

	QuickSort22(a, left, keyindex - 1);
	QuickSort22(a, keyindex + 1, right);
}

//------------------------------------------------------------------------------------------------------------------


int _QuickPartSort3(int* a, int left, int right)   // ��������ǰ��ָ�뷨��
{
	int key = a[right];  
	int prev = left - 1;
	int cur = left;

	while (cur < right)
	{
		if (a[cur] < key && (++prev) != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&a[right], &a[prev]);
	return prev;
}
void QuickSort3(int* a, int left, int right)// ��������ǰ��ָ�뷨��
{
	if (left >= right)
		return;
	int keyindex = _QuickPartSort3(a, left, right);

	QuickSort3(a, left, keyindex - 1);
	QuickSort3(a, keyindex + 1, right);
}


//------------------------------------------------------------------------------------------------------------------


void QuickSort4(int* a, int left, int right)  // �������򣨷ǵݹ��㷨�� 
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);

	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int keyindex = _QuickPartSort2(a, begin, end);

		// [begin,keyindex-1] key [keyindex+1,end]
		if (begin < keyindex - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, keyindex - 1);
		}
		if (keyindex + 1 < end)
		{
			StackPush(&s, keyindex + 1);
			StackPush(&s, end);
		}
	}
}


//*******************************************************************************************************************



void _MergeSort1(int* a, int left, int right, int* tmp)// �鲢�����Ӻ�����  
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;
	// [left,mid] [mid+1,right]
	_MergeSort1(a, left, mid, tmp);
	_MergeSort1(a, mid + 1, right, tmp);

	// a[left,mid]��a[mid+1,right]�鲢��tmp[left,right]��
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;

	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		++begin2;
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
void MergeSort1(int* a, int n) // �鲢����                    
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort1(a, 0, n - 1, tmp);
	free(tmp);
}


//------------------------------------------------------------------------------------------------------------------


void MergeSort2(int* a, int n)      // �鲢���򣨷ǵݹ��㷨��
{
	int* tmp = (int*)malloc(sizeof(int)* n);

	// [begin1,end1][begin2,end2]
	int gap = 1;
	while (gap < n)
	{
		for (int begin = 0; begin < n; begin += 2 * gap)
		{
			// [begin, begin+gap-1][begin+gap, begin+2*gap-1]
			// [0, 0][1, 1]  gap = 1
			// [0, 1][2, 3]	 gap = 2

			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 >= n)
				end1 = n - 1;

			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 >= n)
				end2 = n - 1;

			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}

			while (begin1 <= end1)
				tmp[index++] = a[begin1++];

			while (begin2 <= end2)
				tmp[index++] = a[begin2++];

		}
		memcpy(a, tmp, sizeof(int)*n);

		gap *= 2;
	}
	free(tmp);
}


//*******************************************************************************************************************


void CountSort(int* a, int n)          // �������򣨸볲����
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}		
	// ��̬����tmp����
	int range = max - min + 1;
	int* counta = (int*)malloc(sizeof(int)*(max - min + 1));
	memset(counta, 0, sizeof(int)*range);

	for (int i = 0; i < n; ++i)
	{
		counta[a[i] - min]++;
	}
	// ��ʱ��tmp�������Ѿ����ڸ����ݳ��ֵĴ���
	int j = 0; 
	for (int i = 0; i < range; ++i)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;
		}
	} 
}