#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;

	return newnode;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//int count = 0;
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	count++;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//}

int BinaryTreeSize(BTNode* root)
{
	return root == 0 ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}
