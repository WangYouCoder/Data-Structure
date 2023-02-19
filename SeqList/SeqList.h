#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SLDataType int
//顺序表的创建
typedef struct SeqList
{
	SLDataType* data;
	int sz;
	int capacity;
}SL;

//初始化
void InitSeqList(SL* ps);

//增容
void AddCapacity(SL* ps);

//尾插
void SeqListPushBack(SL* ps, SLDataType x);

//尾删
void SeqListPopback(SL* ps);

//打印
void SeqListPrint(SL* ps);

//头插
void SeqListPushFront(SL* ps, SLDataType x);

//头删
void SeqListPopFront(SL* ps);

//查找
void SeqListFind(SL* ps, SLDataType x);

//在pos位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);

//在pos位置删除
void SeqListErase(SL* ps, int pos);

//销毁
void SeqListDestory(SL* ps);