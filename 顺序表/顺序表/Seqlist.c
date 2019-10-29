#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"


void SeqListInit(SeqList* ps)// 初始化
{
	assert(ps);// 断言 空指针报错
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}


void SeqListDestory(SeqList* ps)// 销毁
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);

		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


void SeqListCheckCapacity(SeqList* ps)// 检查capacity容量，不够就增容
{
	assert(ps);

	if (ps->_capacity == ps->_size)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;
		ps->_array = realloc(ps->_array, sizeof(DataType) * newcapacity); // realloc第一个参数为空，相当于malloc
		ps->_capacity = newcapacity;
	}
}


void SeqListPushBack(SeqList* ps, DataType x)// 尾插
{
	assert(ps);

	SeqListCheckCapacity(ps);// 检查capacity容量，不够就增容

	ps->_array[ps->_size] = x;
	ps->_size++;
}


void SeqListPushFront(SeqList* ps, DataType x)// 头插
{
	assert(ps);
	SeqListCheckCapacity(ps);// 检查capacity容量，不够就增容

	size_t end = ps->_size;// size从0开始

	//while (end >= 0)   // 死循环 -1是整型最大值
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	--end;   
	//}

	while (end > 0) // end == 0时，循环停止，end 不会成为-1
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}

	ps->_array[0] = x;
	ps->_size++;
}


void SeqListPopBack(SeqList* ps)// 尾删
{
	assert(ps&&ps->_size > 0);
	--ps->_size;
}


void SeqListPopFront(SeqList* ps)// 头删
{
	assert(ps);
	size_t start = 0;
	while (start < ps->_size - 1)
	{
		ps->_array[start] = ps->_array[start + 1];
		++start;
	}
	--ps->_size;
}


void SeqListInsert(SeqList* ps, size_t pos, DataType x)// 插入
{
	assert(ps&&pos <= ps->_size);// pos是无符号的，大于0
	SeqListCheckCapacity(ps);// 检查capacity容量，不够就增容
	size_t end = ps->_size - 1;  // 定义下标时，注意越界 死循环问题
	while (end > pos)   // 当pos是0时，end是整型最大值，死循环
	{
		ps->_array[end] = ps->_array[end - 1];  // 用减不用加
		--end;//无符号数--  一定要小心上述问题 *********************
	}
	ps->_array[pos] = x;
	++ps->_size;
}


void SeqListErase(SeqList* ps, size_t pos)// 删除
{
	assert(ps&&pos < ps->_size);// pos 是无符号的，大于0
	while (pos < ps->_size - 1)
	{
		ps->_array[pos] = ps->_array[pos + 1];
		++pos;
	}
	--ps->_size;
}


size_t SeqListSize(SeqList* ps)// 返回数据  尽量不要自己操作结构体
{
	assert(ps);
	return ps->_size;
}


size_t SeqListFind(SeqList* ps, DataType x)// 找值x的位置，返回下标
{
	assert(ps);
	size_t end = 0;
	while (end < ps->_size)
	{
		if (ps->_array[end] == x)
		{
			return end;
		}
		++end;
	}
	return -1; //  虽然是无符号，但可以返回-1
}


DataType SeqListAt(SeqList* ps, size_t pos)// 返回pos位置的值
{
	assert(ps&&pos < ps->_size);
	return ps->_array[pos];
}

//***************************************************************************

void SeqListRemove(SeqList* ps, DataType x)// 删除第一个指定值的结点
{
	assert(ps);
	size_t start = 0;
	for (start = 0; start < ps->_size; ++start)
	{
		if (x == ps->_array[start])
		{
			SeqListErase(ps, start);
			return 0;
		}
	}
	if (start == ps->_size)
	{
		printf("没有找到%d\n", x);
	}
	return 0;
}


void SeqListModify(SeqList* ps, size_t pos, DataType x)// 删除指定位置的指定值
{
	assert(ps&&pos < ps->_size);
	size_t start = 0;
	for (start = 0; start < ps->_size; ++start)
	{
		if ((start == pos) && (ps->_array[start] == x))
		{
			SeqListErase(ps, start);
			return 0;
		}
	}
	if (start == ps->_size)
	{
		printf("没有找到%d\n", x);
	}
	return 0;
}


void SeqListPrint(SeqList* ps)// 打印
{
	for (size_t i = 0; i < SeqListSize(ps); ++i)  // 打印
	{
		printf("%d ", SeqListAt(ps, i));
	}
	printf("\n");
}


void SeqListBubbleSort(SeqList* ps)// 冒泡排序
{
	assert(ps);
	size_t end = ps->_size;
	// 控制多趟冒泡
	while (end > 1)
	{
		// 控制单趟冒泡
		int flag = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (ps->_array[i - 1] > ps->_array[i])
			{
				DataType tmp = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}


// 左闭右开
int SeqListBinaryFind(SeqList* ps, DataType x) // 二分查找    时间复杂度O(N),空间复杂度O(1)
{
	assert(ps);
	size_t begin = 0;
	size_t end = ps->_size;
	while (begin < end)
	{
		size_t mid = begin + ((end - begin) >> 1);
		if (ps->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else if (ps->_array[mid] > x)
		{
			end = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


//// 左闭右闭   有问题
//int SeqListBinaryFind(SeqList* ps, DataType x) // 二分查找    时间复杂度O(N),空间复杂度O(1)
//{
//	assert(ps);
//	size_t begin = 0;
//	size_t end = ps->_size - 1;
//	while (begin <= end)
//	{
//		size_t mid = begin + ((end - begin) >> 1);
//		if (ps->_array[mid] < x)
//		{
//			begin = mid + 1;
//		}
//		else if (ps->_array[mid] > x)
//		{
//			end = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}


void SeqListRemoveAll(SeqList* ps, DataType x) // 已知值的全部结点删除
{
	assert(ps);
	size_t tmp = 0;
	size_t index = 0;
	for (tmp = 0; tmp < ps->_size; ++tmp)
	{
		if (ps->_array[tmp] != x)
		{
			ps->_array[index] = ps->_array[tmp];
			++index;
		}
	}
	ps->_size = index;
	return 0;
}