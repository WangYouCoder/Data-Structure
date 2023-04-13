#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		return NULL;
	}
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);
	
	newnode->data = x;
	newnode->next = phead;
	phead->prev = newnode;
	newnode->prev = tail;
	tail->next = newnode;
}

void ListPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		return;
	}
	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* next = phead->next;
	LTNode* newnode = BuyListNode(x);

	newnode->prev = phead;
	phead->next = newnode;

	newnode->next = next;
	next->prev = newnode;
}

void ListPopFront(LTNode* phead)
{
	//assert(phead->next != phead);  //暴力解决

	//温和方式
	if (phead->next == phead)
	{
		return;
	}
	LTNode* prev = phead->next;
	LTNode* next = prev->next;

	phead->next = next;
	next->prev = phead;
	free(prev);
	prev = NULL;
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("该元素不存在\n");
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	LTNode* prevPos = pos->prev;
	LTNode* newnode = BuyListNode(x);

	newnode->next = pos;
	pos->prev = newnode;

	newnode->prev = prevPos;
	prevPos->next = newnode;
}

void ListErase(LTNode* pos)
{
	LTNode* nextPos = pos->next;
	LTNode* prevPos = pos->prev;

	nextPos->prev = prevPos;
	prevPos->next = nextPos;
	free(pos);
	pos = NULL;
}

void ListDestroy(LTNode* phead)
{
	LTNode* cur = phead;
	LTNode* next = cur->next;

	while (cur)
	{
		free(cur);
		cur = NULL;

		if (cur != NULL)
		{
			cur = next;
			next = next->next;
		}
	}
}