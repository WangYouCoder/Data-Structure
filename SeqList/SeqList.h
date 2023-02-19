#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SLDataType int
//˳���Ĵ���
typedef struct SeqList
{
	SLDataType* data;
	int sz;
	int capacity;
}SL;

//��ʼ��
void InitSeqList(SL* ps);

//����
void AddCapacity(SL* ps);

//β��
void SeqListPushBack(SL* ps, SLDataType x);

//βɾ
void SeqListPopback(SL* ps);

//��ӡ
void SeqListPrint(SL* ps);

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);

//ͷɾ
void SeqListPopFront(SL* ps);

//����
void SeqListFind(SL* ps, SLDataType x);

//��posλ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);

//��posλ��ɾ��
void SeqListErase(SL* ps, int pos);

//����
void SeqListDestory(SL* ps);