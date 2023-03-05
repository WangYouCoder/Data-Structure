#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLTDataType int

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//开辟新结点
SLTNode* BuySListNode(SLTDataType x);

//打印
void SListPrint(SLTNode* phead);

//单链表尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

//尾删
void SListPopBack(SLTNode** pphead);

//头删
void SListPopFront(SLTNode** pphead);

//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//删除pos位置之后的值
void SListEraseAfter(SLTNode* pos);

//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);

//销毁链表
SListDestory(SLTNode** pphead);