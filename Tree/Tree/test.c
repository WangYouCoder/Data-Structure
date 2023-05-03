#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}
void test()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	int count = BinaryTreeSize(root);
	printf("BinaryTreeSize:%d\n", count);

	int leafSize = BinaryTreeLeafSize(root);
	printf("BinaryTreeLeafSize:%d\n", leafSize);

	int LeveKSize = BinaryTreeLevelKSize(root,3);
	printf("BinaryTreeLevelKSize:%d\n", LeveKSize);


}
int main()
{
	test();
	return 0;
}