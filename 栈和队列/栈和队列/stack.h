#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;//栈
	size_t _top;//栈顶
	size_t _capacity;//容量
}Stack;

void StackInit(Stack* ps);// 初始化
void StackDestory(Stack* ps);// 销毁
void StackPush(Stack* ps, STDataType x);// 入栈
void StackPop(Stack* ps);// 删除栈顶元素
STDataType StackTop(Stack* ps);// 取栈顶元素
bool StackEmpty(Stack* ps);// 判栈空
size_t StackSize(Stack* ps);// 栈大小
void StackPrint(Stack* ps);// 打印出栈所有元素

void StackInit(Stack* ps)// 初始化
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)// 销毁
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

void StackPush(Stack* ps, STDataType x)// 入栈
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

void StackPop(Stack* ps)// 删除栈顶元素
{
	assert(ps&&ps->_top > 0);
	--ps->_top;// 直接挪动下标即可
}

STDataType StackTop(Stack* ps)// 取栈顶元素
{
	assert(ps&&ps->_top > 0);
	return (ps->_a[ps->_top - 1]);
	//return ps->_top - 1; // 这是错误的，因为ps->_top是下标，不是该下标代表的元素！！！！！！！！！！！
}

bool StackEmpty(Stack* ps)// 判栈空
{
	assert(ps);
	return ps->_top == 0;// 看下标是否为0
}

size_t StackSize(Stack* ps)// 栈大小
{
	assert(ps);
	return ps->_top;// 下标表示几个元素
}

void StackPrint(Stack* ps)// 打印出栈所有元素
{
	assert(ps&&ps->_top > 0);
	while (ps->_top)
	{
		printf("%d ", ps->_top);
		ps->_top--;
	}
}