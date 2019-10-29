#define _CRT_SECURE_NO_WARNINGS 1

#include"binary.h"
#include"queue.h"

int main()
{
	char str[] = "ABDF###E##C##";
	int i = 0;

	printf("构建二叉树\n");
	BTNode* root=BinaryTreeCreate(str, &i);// 构建二叉树

	printf("二叉树的结点个数：%d\n", BinaryTreeSize(root));//二叉树的结点个数

	printf("二叉树叶子结点个数：%d\n", BinaryTreeLeafSize(root));// 二叉树叶子结点个数

	printf("二叉树第K层结点个数：%d\n", BinaryTreeLevelKSize(root, 3));// 二叉树第K层结点个数

	printf("二叉树中查找结点E");
	BTNode* BinaryTreeFind(root, E);// 二叉树查找结点x

	printf("\n先序遍历：");
	BinaryTreePrevOrder(root);// 先序遍历
	printf("\n中序遍历：");
	BinaryTreeInOrder(root);// 中序遍历
	printf("\n后序遍历：");
	BinaryTreePostOrder(root);// 后序遍历
	printf("\n层序遍历：");
	BinaryTreeLevelOrder(root);// 层序遍历

	printf("\n判断二叉树是否为完全二叉树：%d",BinaryTreeComplete(root));// 判断二叉树是否为完全二叉树

	printf("\n销毁二叉树\n");
	BinaryTreeDestory(&root);// 销毁二叉树

	system("pause");
	return 0;
}