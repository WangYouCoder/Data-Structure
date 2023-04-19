#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Datatype;

//��ʽ�ṹ��ʾ����
typedef struct QListNode
{
	Datatype data;
	struct Queue* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* tail;
}Queue;

// ��ʼ������
void QueueInit(Queue* pq);

// ��β�����
void QueuePush(Queue* pq, Datatype data);

// ��ͷ������
void QueuePop(Queue* pq);

// ��ȡ����ͷ��Ԫ��
Datatype QueueFront(Queue* pq);

// ��ȡ���ж�βԪ��
Datatype QueueBack(Queue* pq);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq);

// ���ٶ���
void QueueDestroy(Queue* pq);
