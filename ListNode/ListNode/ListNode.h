#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct LTNode
{
	LTDataType data;
	struct LTNode* prev;
	struct LTNode* next;
}LTNode;

// 创建返回链表的头结点.
LTNode* ListInit();

// 双向链表销毁
void ListDestroy(LTNode* phead);

// 双向链表打印
void ListPrint(LTNode* phead);

// 双向链表尾插
void ListPushBack(LTNode* phead, LTDataType x);

// 双向链表尾删
void ListPopBack(LTNode* phead);

// 双向链表头插
void ListPushFront(LTNode* phead, LTDataType x);

// 双向链表头删
void ListPopFront(LTNode* phead);

// 双向链表查找
LTNode* ListFind(LTNode* phead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(LTNode* pos);