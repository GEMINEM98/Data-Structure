#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"


void SeqListInit(SeqList* ps)// ��ʼ��
{
	assert(ps);// ���� ��ָ�뱨��
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}


void SeqListDestory(SeqList* ps)// ����
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


void SeqListCheckCapacity(SeqList* ps)// ���capacity����������������
{
	assert(ps);

	if (ps->_capacity == ps->_size)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;
		ps->_array = realloc(ps->_array, sizeof(DataType) * newcapacity); // realloc��һ������Ϊ�գ��൱��malloc
		ps->_capacity = newcapacity;
	}
}


void SeqListPushBack(SeqList* ps, DataType x)// β��
{
	assert(ps);

	SeqListCheckCapacity(ps);// ���capacity����������������

	ps->_array[ps->_size] = x;
	ps->_size++;
}


void SeqListPushFront(SeqList* ps, DataType x)// ͷ��
{
	assert(ps);
	SeqListCheckCapacity(ps);// ���capacity����������������

	size_t end = ps->_size;// size��0��ʼ

	//while (end >= 0)   // ��ѭ�� -1���������ֵ
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	--end;   
	//}

	while (end > 0) // end == 0ʱ��ѭ��ֹͣ��end �����Ϊ-1
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}

	ps->_array[0] = x;
	ps->_size++;
}


void SeqListPopBack(SeqList* ps)// βɾ
{
	assert(ps&&ps->_size > 0);
	--ps->_size;
}


void SeqListPopFront(SeqList* ps)// ͷɾ
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


void SeqListInsert(SeqList* ps, size_t pos, DataType x)// ����
{
	assert(ps&&pos <= ps->_size);// pos���޷��ŵģ�����0
	SeqListCheckCapacity(ps);// ���capacity����������������
	size_t end = ps->_size - 1;  // �����±�ʱ��ע��Խ�� ��ѭ������
	while (end > pos)   // ��pos��0ʱ��end���������ֵ����ѭ��
	{
		ps->_array[end] = ps->_array[end - 1];  // �ü����ü�
		--end;//�޷�����--  һ��ҪС���������� *********************
	}
	ps->_array[pos] = x;
	++ps->_size;
}


void SeqListErase(SeqList* ps, size_t pos)// ɾ��
{
	assert(ps&&pos < ps->_size);// pos ���޷��ŵģ�����0
	while (pos < ps->_size - 1)
	{
		ps->_array[pos] = ps->_array[pos + 1];
		++pos;
	}
	--ps->_size;
}


size_t SeqListSize(SeqList* ps)// ��������  ������Ҫ�Լ������ṹ��
{
	assert(ps);
	return ps->_size;
}


size_t SeqListFind(SeqList* ps, DataType x)// ��ֵx��λ�ã������±�
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
	return -1; //  ��Ȼ���޷��ţ������Է���-1
}


DataType SeqListAt(SeqList* ps, size_t pos)// ����posλ�õ�ֵ
{
	assert(ps&&pos < ps->_size);
	return ps->_array[pos];
}

//***************************************************************************

void SeqListRemove(SeqList* ps, DataType x)// ɾ����һ��ָ��ֵ�Ľ��
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
		printf("û���ҵ�%d\n", x);
	}
	return 0;
}


void SeqListModify(SeqList* ps, size_t pos, DataType x)// ɾ��ָ��λ�õ�ָ��ֵ
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
		printf("û���ҵ�%d\n", x);
	}
	return 0;
}


void SeqListPrint(SeqList* ps)// ��ӡ
{
	for (size_t i = 0; i < SeqListSize(ps); ++i)  // ��ӡ
	{
		printf("%d ", SeqListAt(ps, i));
	}
	printf("\n");
}


void SeqListBubbleSort(SeqList* ps)// ð������
{
	assert(ps);
	size_t end = ps->_size;
	// ���ƶ���ð��
	while (end > 1)
	{
		// ���Ƶ���ð��
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


// ����ҿ�
int SeqListBinaryFind(SeqList* ps, DataType x) // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
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


//// ����ұ�   ������
//int SeqListBinaryFind(SeqList* ps, DataType x) // ���ֲ���    ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
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


void SeqListRemoveAll(SeqList* ps, DataType x) // ��ֵ֪��ȫ�����ɾ��
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