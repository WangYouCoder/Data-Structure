#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->capacity = hp->size = 0;
	hp->data = NULL;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

void Swap(HeapDatatype* x, HeapDatatype* y)
{
	HeapDatatype tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(HeapDatatype* data,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (data[child] < data[parent]) // "<" 小堆
		{
			Swap(&data[child], &data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HeapDatatype x)
{
	assert(hp);

	//考虑增容
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HeapDatatype* tmp = (HeapDatatype*)realloc(hp->data, sizeof(HeapDatatype) * newcapacity);
		if (tmp == NULL)
		{
			return;
		}
		hp->data = tmp;
		hp->capacity = newcapacity;
	}
	hp->data[hp->size] = x;
	hp->size++;

	AdjustUp(hp->data, hp->size - 1);
}

//向下调整
void AdjustDown(HeapDatatype* data, int size, int parent)
{
	int child = (parent * 2) + 1;
	while (child < size)
	{
		if (child + 1 < size &&	data[child] > data[child + 1])  // "<" 大堆
		{
			child++;
		}
		
		if (data[child] < data[parent]) // ">"大堆
		{
			Swap(&data[child], &data[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->data, hp->size, 0);
}

HeapDatatype HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->data[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}