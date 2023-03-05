#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("开辟失败\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SLTNode* phead)
{
	while (phead != NULL)
	{
		printf("%d ", phead->data);
		phead = phead->next;
	}
	printf("\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)//如果链表为空，直接将新结点赋给第一个位置
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL) //找到尾结点
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);  //当链表为空的时候，一样可以完美解决问题，不需要分开讨论
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prenode = *pphead;
		while (tail->next != NULL)
		{
			prenode = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;       //当仅剩一个结点的时候，tail和prenode指向同一个地方，一旦free(tail)，prenode就指向了一块被释放的空间，造成野指针的使用问题
		prenode->next = NULL;//因此要把仅剩一个结点的情况单独写出来
	}
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)//链表为空的时候直接结束
	{
		return;
	}
	SLTNode* prenode = *pphead;
	*pphead = (*pphead)->next;//仅剩一个结点的时候与正常情况相同，无需讨论
	free(prenode);
	prenode = NULL;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	while (phead)
	{
		if (phead->data == x)
		{
			return phead;
		}
		else
		{
			phead = phead->next;
		}
		/*if (phead->next == NULL)
		{
			return NULL;
		}
		phead = phead->next;*/
	}
	return NULL;	
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	/*SLTNode* newnode = BuySListNode(x);
	SLTNode* cur = *pphead;
	if (pos == cur)
	{
		*pphead = newnode;
	}
	else
	{
		while (cur != pos)
		{
			cur = cur->next;
		}
		newnode->next = cur->next;
		cur->next = newnode;
	}*/
	
	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	if (pos == *pphead)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* pospre = *pphead;
		while (pospre->next != pos)  //找到pos的前一个结点
		{
			pospre = pospre->next;
		}
		newnode->next = pospre->next;  //pospre->next也可以换成pos
		pospre->next = newnode;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next != NULL);
	SLTNode* next = pos->next;  //保存pos下一个结点的地址
	pos->next = pos->next->next;
	free(next);
	next = NULL;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}


SListDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}