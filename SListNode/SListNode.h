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

//�����½��
SLTNode* BuySListNode(SLTDataType x);

//��ӡ
void SListPrint(SLTNode* phead);

//������β��
void SListPushBack(SLTNode** pphead, SLTDataType x);

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

//βɾ
void SListPopBack(SLTNode** pphead);

//ͷɾ
void SListPopFront(SLTNode** pphead);

//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//��posλ��֮�����
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//��posλ��֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//ɾ��posλ��֮���ֵ
void SListEraseAfter(SLTNode* pos);

//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos);

//��������
SListDestory(SLTNode** pphead);