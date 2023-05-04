#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>



typedef char BTDataType;
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

// �������ڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* str,int* pi);

// ����������
void BinaryTreeDestory(BTNode* root);

// �������
void LevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);