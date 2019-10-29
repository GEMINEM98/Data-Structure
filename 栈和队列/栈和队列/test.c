#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"
#include"stack.h"

void test_stack()
{
	Stack ps;
	StackInit(&ps);// ��ʼ��

	StackPush(&ps, 1);// ��ջ
	StackPush(&ps, 2);// ��ջ
	StackPush(&ps, 3);// ��ջ
	StackPush(&ps, 4);// ��ջ
	StackPush(&ps, 5);// ��ջ

	StackPop(&ps);// ��ջ
	StackPop(&ps);// ��ջ

	printf("��ջ��ջ��Ԫ���ǣ�%d",StackTop(&ps));// ȡջ��Ԫ��

	printf("\nջ�Ƿ�Ϊ�գ�%d", StackEmpty(&ps));// ��ջ��

	printf("\nջ��С�ǣ�%d", StackSize(&ps));// ջ��С
										  
	printf("\n����Ԫ�س�ջ��");

	StackPrint(&ps);// ��ӡ��ջ����Ԫ��

	StackDestory(&ps);// ����
	printf("\nջ֡�����٣�\n");
}

void test_queue()
{
	Queue pq;
	QueueInit(&pq);//��ʼ��
	printf("��ʼ����");
	QueuePrint(&pq);//��ӡ����

	QueuePush(&pq, 1);//�����
	QueuePush(&pq, 2);//�����
	QueuePush(&pq, 3);//�����
	QueuePush(&pq, 4);//�����
	QueuePush(&pq, 5);//�����
	printf("����У�");
	QueuePrint(&pq);//��ӡ����

	QueuePop(&pq);//��˳��ɾ��
	printf("��ӡ���У�");
	QueuePrint(&pq);//ɾ�����ӡ����

	printf("ͷ����ֵΪ��%d\n", QueueFront(&pq));//����ͷ����ֵ

	printf("β����ֵΪ��%d\n", QueueBack(&pq));//����β����ֵ

	printf("�����Ƿ�Ϊ�գ�%d\n", QueueEmpty(&pq));//�ж����Ƿ�Ϊ��

	printf("���д�СΪ��%d\n", QueueSize(&pq));//���д�С

	QueueDestory(&pq);//����
	printf("���٣�");
	QueuePrint(&pq);//��ӡ����
}

int main()
{
	printf("ջ��\n");
	test_stack();
	printf("\n\n���У�\n");
	test_queue();
	system("pause");
	return 0;
}