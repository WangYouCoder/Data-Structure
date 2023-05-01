#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef int HeapDatatype;
typedef struct Heap
{
	HeapDatatype* data;
	int capacity;
	int size;
}Heap;

//�ѵĳ�ʼ��
void HeapInit(Heap* hp);

// �ѵ�����
void HeapDestory(Heap* hp);

//���ϵ���
void AdjustUp(HeapDatatype* data, int child);

//���µ���
void AdjustDown(HeapDatatype* data, int size, int parent);

// �ѵĲ���
void HeapPush(Heap* hp, HeapDatatype x);

//�ѵĴ�ӡ
void HeapPrint(Heap* hp);

//��������
void Swap(HeapDatatype* x, HeapDatatype* y);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HeapDatatype HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
bool HeapEmpty(Heap* hp);
