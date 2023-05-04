#define _CRT_SECURE_NO_WARNINGS 1
#include"Tree.h"
#include"Queue.h"

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

	//用于整形数据的测试
	printf("%d ", root->data);

	////用于字符型数据的测试
	//printf("%c ", root->data);
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

//需要单独拿出来测试，因为此时的BTDataType的类型需要是char
BTNode* BinaryTreeCreate(BTDataType* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	
	BTNode* root = BuyNode(str[(*pi)++]);
	root->left = BinaryTreeCreate(str, pi);
	root->right = BinaryTreeCreate(str, pi);
	return root;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* Front = QueueFront(&q);
		QueuePop(&q);
		if (Front)
			return false;
	}
	QueueDestroy(&q);
	return true;
}