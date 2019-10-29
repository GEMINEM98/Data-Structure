#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;//ջ
	size_t _top;//ջ��
	size_t _capacity;//����
}Stack;

void StackInit(Stack* ps);// ��ʼ��
void StackDestory(Stack* ps);// ����
void StackPush(Stack* ps, STDataType x);// ��ջ
void StackPop(Stack* ps);// ɾ��ջ��Ԫ��
STDataType StackTop(Stack* ps);// ȡջ��Ԫ��
bool StackEmpty(Stack* ps);// ��ջ��
size_t StackSize(Stack* ps);// ջ��С
void StackPrint(Stack* ps);// ��ӡ��ջ����Ԫ��

void StackInit(Stack* ps)// ��ʼ��
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)// ����
{
	assert(ps);
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}
}

void StackPush(Stack* ps, STDataType x)// ��ջ
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)// ɾ��ջ��Ԫ��
{
	assert(ps&&ps->_top > 0);
	--ps->_top;// ֱ��Ų���±꼴��
}

STDataType StackTop(Stack* ps)// ȡջ��Ԫ��
{
	assert(ps&&ps->_top > 0);
	return (ps->_a[ps->_top - 1]);
	//return ps->_top - 1; // ���Ǵ���ģ���Ϊps->_top���±꣬���Ǹ��±�����Ԫ�أ���������������������
}

bool StackEmpty(Stack* ps)// ��ջ��
{
	assert(ps);
	return ps->_top == 0;// ���±��Ƿ�Ϊ0
}

size_t StackSize(Stack* ps)// ջ��С
{
	assert(ps);
	return ps->_top;// �±��ʾ����Ԫ��
}

void StackPrint(Stack* ps)// ��ӡ��ջ����Ԫ��
{
	assert(ps&&ps->_top > 0);
	while (ps->_top)
	{
		printf("%d ", ps->_top);
		ps->_top--;
	}
}