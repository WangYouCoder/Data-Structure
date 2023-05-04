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

//���Ի�������
void test1()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);  //����:ǰ�����
	printf("\n");

	InOrder(root);  //����:�������
	printf("\n");

	PostOrder(root);  //����:�������
	printf("\n");

	int count = BinaryTreeSize(root);  //����:ͳ�����Ľ�����
	printf("BinaryTreeSize:%d\n", count);

	int leafSize = BinaryTreeLeafSize(root);  //����:ͳ������Ҷ�ӽ�����
	printf("BinaryTreeLeafSize:%d\n", leafSize);

	int LeveKSize = BinaryTreeLevelKSize(root,3);  //����:ͳ�����ĵ�K��Ľ�����
	printf("BinaryTreeLevelKSize:%d\n", LeveKSize);

	LevelOrder(root);  //����:�������

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));  //����:�ж��Ƿ�Ϊ��ȫ������

	BinaryTreeDestory(root);
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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