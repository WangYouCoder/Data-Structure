#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Datatype;

//链式结构表示队列
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

// 初始化队列
void QueueInit(Queue* pq);

// 队尾入队列
void QueuePush(Queue* pq, Datatype data);

// 队头出队列
void QueuePop(Queue* pq);

// 获取队列头部元素
Datatype QueueFront(Queue* pq);

// 获取队列队尾元素
Datatype QueueBack(Queue* pq);

// 获取队列中有效元素个数
int QueueSize(Queue* pq);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* pq);

// 销毁队列
void QueueDestroy(Queue* pq);
