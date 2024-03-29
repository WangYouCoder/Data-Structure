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

//创建结点
BTNode* BuyNode(BTDataType x);

// 二叉树前序遍历
void PreOrder(BTNode* root);

// 二叉树中序遍历
void InOrder(BTNode* root);

// 二叉树后序遍历
void PostOrder(BTNode* root);

// 二叉树节点个数
int BinaryTreeSize(BTNode* root);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* str,int* pi);

// 二叉树销毁
void BinaryTreeDestory(BTNode* root);

// 层序遍历
void LevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);