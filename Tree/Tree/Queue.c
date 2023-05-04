#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	
	pq->front = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, Datatype x)
{
	assert(pq);	
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("¿ª±ÙÊ§°Ü£¡£¡");
		return;
	}
	newnode->next = NULL;
	newnode->data = x;
	
	if (pq->front == NULL)
	{
		pq->tail = newnode;
		pq->front = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = pq->tail->next;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->tail = NULL;
	}
}


Datatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->front->data;
}

Datatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QNode* cur = pq->front;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->front == NULL)
	{
		return true;
	}
	return false;
}