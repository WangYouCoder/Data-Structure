#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
#include"Queue.h"

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = node7;
	return node1;
}

//测试基本功能
void test1()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);  //测试:前序遍历
	printf("\n");

	InOrder(root);  //测试:中序遍历
	printf("\n");

	PostOrder(root);  //测试:后序遍历
	printf("\n");

	int count = BinaryTreeSize(root);  //测试:统计树的结点个数
	printf("BinaryTreeSize:%d\n", count);

	int leafSize = BinaryTreeLeafSize(root);  //测试:统计树的叶子结点个数
	printf("BinaryTreeLeafSize:%d\n", leafSize);

	int LeveKSize = BinaryTreeLevelKSize(root,3);  //测试:统计树的第K层的结点个数
	printf("BinaryTreeLevelKSize:%d\n", LeveKSize);

	LevelOrder(root);  //测试:层序遍历

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));  //测试:判断是否为完全二叉树

	BinaryTreeDestory(root);
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
void test2()
{
	char str[20] = "ABC##DE#G##F###";
	int i = 0;
	int* pi = &i;
	BTNode* root = BinaryTreeCreate(str, pi);
	PreOrder(root);
	printf("\n");

	BinaryTreeDestory(root);
}

int main()
{
	test1();
	//test2();
	return 0;
}