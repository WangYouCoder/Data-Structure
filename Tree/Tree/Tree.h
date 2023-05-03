#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�������
BTNode* BuyNode(BTDataType x);

// ������ǰ�����
void PreOrder(BTNode* root);

// �������������
void InOrder(BTNode* root);

// �������������
void PostOrder(BTNode* root);

// �������
void LevelOrder(BTNode* root);

// �������ڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

// ����������
void BinaryTreeDestory(BTNode** root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);