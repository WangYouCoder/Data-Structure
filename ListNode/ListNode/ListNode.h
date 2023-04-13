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

// �������������ͷ���.
LTNode* ListInit();

// ˫����������
void ListDestroy(LTNode* phead);

// ˫�������ӡ
void ListPrint(LTNode* phead);

// ˫������β��
void ListPushBack(LTNode* phead, LTDataType x);

// ˫������βɾ
void ListPopBack(LTNode* phead);

// ˫������ͷ��
void ListPushFront(LTNode* phead, LTDataType x);

// ˫������ͷɾ
void ListPopFront(LTNode* phead);

// ˫���������
LTNode* ListFind(LTNode* phead, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(LTNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos);