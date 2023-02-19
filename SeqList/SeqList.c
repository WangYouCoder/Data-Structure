#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void InitSeqList(SL* ps)
{
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}

void AddCapacity(SL* ps)
{
	//增容
	if (ps->sz == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* pc = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * newcapacity);
		if (pc == NULL)
		{
			perror("SeqListPushBack");
		}
		ps->data = pc;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	AddCapacity(ps);
	ps->data[ps->sz] = x;
	ps->sz++;
}

void SeqListPopback(SL* ps)
{
	//assert(ps->sz > 0);
	if (ps->sz > 0)
	{
		ps->sz--;
	}
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	AddCapacity(ps);
	int end = ps->sz - 1;
	while (end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->sz++;
}

void SeqListPopFront(SL* ps)
{
	if (ps->sz > 0)
	{
		int front = 1;
		while (front < ps->sz)
		{
			ps->data[front - 1] = ps->data[front];
			front++;
		}
		ps->sz--;
	}
}

void SeqListFind(SL* ps, SLDataType x)
{
	int front = 0;
	while (front < ps->sz)
	{
		if (ps->data[front] == x)
		{
			printf("找到了,下标为:>%d\n", front);
			break;
		}
		front++;
		if (front == ps->sz)
		{
			printf("元素不存在\n");
		}
	}
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	AddCapacity(ps);
	pos -= 1;               //转化为对应的下标
	int end = ps->sz - 1;  
	while (pos <= end)   //一直将下标为pos位置的元素挪完
	{
		ps->data[end + 1] = ps->data[end];   //将元素从后一个一个往后挪
		end--;
	}
	ps->data[pos] = x;
	ps->sz++;
}

void SeqListErase(SL* ps, int pos)
{
	int end = pos - 1;      //将end与下标相对应，指向第pos个元素的下标
	if (pos > ps->sz)
	{
		printf("该位置没有元素\n");
	}
	if (pos > 0 && pos <= ps->sz)   //保证顺序表里要有元素，并且删除的元素位置必须小于最后一个元素的位置
	{
		while (end < ps->sz - 1)      //不断往前覆盖，当然也可以一开始不转化为下标，pos指向的是对应元素的下一个元素，直接向前覆盖也可以
		{
			ps->data[end] = ps->data[end + 1];
			end++;
		}
		ps->sz--;
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}


