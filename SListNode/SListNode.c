#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("����ʧ��\n");
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
	if (*pphead == NULL)//�������Ϊ�գ�ֱ�ӽ��½�㸳����һ��λ��
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL) //�ҵ�β���
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);  //������Ϊ�յ�ʱ��һ����������������⣬����Ҫ�ֿ�����
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
		tail = NULL;       //����ʣһ������ʱ��tail��prenodeָ��ͬһ���ط���һ��free(tail)��prenode��ָ����һ�鱻�ͷŵĿռ䣬���Ұָ���ʹ������
		prenode->next = NULL;//���Ҫ�ѽ�ʣһ�������������д����
	}
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)//����Ϊ�յ�ʱ��ֱ�ӽ���
	{
		return;
	}
	SLTNode* prenode = *pphead;
	*pphead = (*pphead)->next;//��ʣһ������ʱ�������������ͬ����������
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
		while (pospre->next != pos)  //�ҵ�pos��ǰһ�����
		{
			pospre = pospre->next;
		}
		newnode->next = pospre->next;  //pospre->nextҲ���Ի���pos
		pospre->next = newnode;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next != NULL);
	SLTNode* next = pos->next;  //����pos��һ�����ĵ�ַ
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