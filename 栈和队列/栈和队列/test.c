#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"
#include"stack.h"

void test_stack()
{
	Stack ps;
	StackInit(&ps);// 初始化

	StackPush(&ps, 1);// 入栈
	StackPush(&ps, 2);// 入栈
	StackPush(&ps, 3);// 入栈
	StackPush(&ps, 4);// 入栈
	StackPush(&ps, 5);// 入栈

	StackPop(&ps);// 出栈
	StackPop(&ps);// 出栈

	printf("出栈后，栈顶元素是：%d",StackTop(&ps));// 取栈顶元素

	printf("\n栈是否为空：%d", StackEmpty(&ps));// 判栈空

	printf("\n栈大小是：%d", StackSize(&ps));// 栈大小
										  
	printf("\n所有元素出栈：");

	StackPrint(&ps);// 打印出栈所有元素

	StackDestory(&ps);// 销毁
	printf("\n栈帧已销毁！\n");
}

void test_queue()
{
	Queue pq;
	QueueInit(&pq);//初始化
	printf("初始化：");
	QueuePrint(&pq);//打印队列

	QueuePush(&pq, 1);//入队列
	QueuePush(&pq, 2);//入队列
	QueuePush(&pq, 3);//入队列
	QueuePush(&pq, 4);//入队列
	QueuePush(&pq, 5);//入队列
	printf("入队列：");
	QueuePrint(&pq);//打印队列

	QueuePop(&pq);//按顺序删除
	printf("打印队列：");
	QueuePrint(&pq);//删除后打印队列

	printf("头结点的值为：%d\n", QueueFront(&pq));//返回头结点的值

	printf("尾结点的值为：%d\n", QueueBack(&pq));//返回尾结点的值

	printf("队列是否为空：%d\n", QueueEmpty(&pq));//判队列是否为空

	printf("队列大小为：%d\n", QueueSize(&pq));//队列大小

	QueueDestory(&pq);//销毁
	printf("销毁：");
	QueuePrint(&pq);//打印队列
}

int main()
{
	printf("栈：\n");
	test_stack();
	printf("\n\n队列：\n");
	test_queue();
	system("pause");
	return 0;
}