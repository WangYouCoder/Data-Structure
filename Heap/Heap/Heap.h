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

//堆的初始化
void HeapInit(Heap* hp);

// 堆的销毁
void HeapDestory(Heap* hp);

//向上调整
void AdjustUp(HeapDatatype* data, int child);

//向下调整
void AdjustDown(HeapDatatype* data, int size, int parent);

// 堆的插入
void HeapPush(Heap* hp, HeapDatatype x);

//堆的打印
void HeapPrint(Heap* hp);

//交换函数
void Swap(HeapDatatype* x, HeapDatatype* y);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HeapDatatype HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
bool HeapEmpty(Heap* hp);
