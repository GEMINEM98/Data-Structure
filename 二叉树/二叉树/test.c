#define _CRT_SECURE_NO_WARNINGS 1

#include"binary.h"
#include"queue.h"

int main()
{
	char str[] = "ABDF###E##C##";
	int i = 0;

	printf("����������\n");
	BTNode* root=BinaryTreeCreate(str, &i);// ����������

	printf("�������Ľ�������%d\n", BinaryTreeSize(root));//�������Ľ�����

	printf("������Ҷ�ӽ�������%d\n", BinaryTreeLeafSize(root));// ������Ҷ�ӽ�����

	printf("��������K���������%d\n", BinaryTreeLevelKSize(root, 3));// ��������K�������

	printf("�������в��ҽ��E");
	BTNode* BinaryTreeFind(root, E);// ���������ҽ��x

	printf("\n���������");
	BinaryTreePrevOrder(root);// �������
	printf("\n���������");
	BinaryTreeInOrder(root);// �������
	printf("\n���������");
	BinaryTreePostOrder(root);// �������
	printf("\n���������");
	BinaryTreeLevelOrder(root);// �������

	printf("\n�ж϶������Ƿ�Ϊ��ȫ��������%d",BinaryTreeComplete(root));// �ж϶������Ƿ�Ϊ��ȫ������

	printf("\n���ٶ�����\n");
	BinaryTreeDestory(&root);// ���ٶ�����

	system("pause");
	return 0;
}